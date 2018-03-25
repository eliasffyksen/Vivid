//
// Created by Ole on 10.09.2017.
//

#include "image.h"
#include <sstream>
#include <fstream>
#include "bitarray.h"
#include "tree.h"
#include <vector>

namespace vivid { namespace util {

// The order of which symbol comes first in the 3-bit lengths specifications for the first huffman tree
// (the meta tree, aka the one that is used to create the literal and distance trees)
	static const unsigned short metaTreeOrder[19] = {16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};
// Base length of the length codes
	static const unsigned short lengths[29] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31, 35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258};
// How many extra bits are needed to specify the actual length for the length code
	static const unsigned short lengthsExtraBits[29] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0};
// Base offset of the offset codes
	static const unsigned int offsets[30] = {1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193, 257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577};
// How many extra bits are needed to specify the actual offset for the offset code
	static const unsigned int offsetsExtraBits[30] = {0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13};
	
	Image::Image(const std::string& path) {
		std::vector<Chunk> chunks;
		{
			// Loads the image file and formats the data in chunks (as per the PNG specification)
			std::ifstream stream(path, std::ifstream::in | std::ifstream::ate | std::ifstream::binary);
			auto size = (unsigned int) stream.tellg();
			if (!stream.good()) {
				data = new unsigned char[3] {0, 0, 0};
				format.width = 1;
				format.height = 1;
				format.bitDepth = 8;
				format.colorFormat = VIVID_IMAGE_FORMAT_RGB;
				return;
			}
			stream.seekg(0, std::ifstream::beg);
			
			unsigned char fileData[size];
			unsigned int position = 0;
			char in;
			while (stream.get(in))
				fileData[position++] = (unsigned char) in;
			
			stream.close();
			
			loadChunks(chunks, fileData, size);
			
			// Sets the format of the image
			std::vector<unsigned char>& dataIDHR = chunks[0].data; // the IDAT chunk
			format.width = dataIDHR[0] << 24 | dataIDHR[1] << 16 | dataIDHR[2] << 8 | dataIDHR[3];
			format.height = dataIDHR[4] << 24 | dataIDHR[5] << 16 | dataIDHR[6] << 8 | dataIDHR[7];
			format.bitDepth = dataIDHR[8];
			format.colorFormat = dataIDHR[9];
			format.compressionMethod = dataIDHR[10];
			format.filterMethod = dataIDHR[11];
			format.interlaceMethod = dataIDHR[12];
			if (format.colorFormat == 0 || format.colorFormat == 4) {
				std::cerr << "ERROR - wrong color type: " << format.colorFormat << std::endl;
				data = new unsigned char[3] {0, 0, 0};
				format.width = 1;
				format.height = 1;
				format.bitDepth = 8;
				format.colorFormat = VIVID_IMAGE_FORMAT_RGB;
				return;
			}
		}
		
		std::vector<int>* palette = nullptr;
		
		if(format.colorFormat == 3) {
			unsigned int indexPLTE = 0;
			while(chunks[++indexPLTE].type != "PLTE");
			
			Chunk PLTE = chunks[indexPLTE];
			
			palette = new std::vector<int>(PLTE.length/3);
			
			for(int i = 0; i < PLTE.length/3; i++) {
				(*palette)[i] = PLTE.data[3 * i] << 16 | PLTE.data[3*i + 1] << 8 | PLTE.data[3*i + 2];
			}
		}
		
		// figures out how many IDAT chunks exist
		unsigned int firstIDAT = 0;
		while (chunks[++firstIDAT].type != "IDAT");
		unsigned int lastIDAT = firstIDAT;
		while (++lastIDAT < chunks.size() && chunks[lastIDAT].type == "IDAT");
		
		Chunk firstPixelChunk = chunks[firstIDAT];
		std::vector<unsigned char>& firstCompressedData = firstPixelChunk.data;
//		todo: use dict and stuff
		BitArray flagBits(firstCompressedData[1], 8);
		bool fDict = flagBits.read(5, 1) != 0;
		//std::cout << "has dict: " << fDict << std::endl;
		
		unsigned int pos = 0; // The current position in the bitstream
		// The bit stream containing all the bits of the compressed data and then adds all the data to the bitstream
		BitArray bitStream;
		for (unsigned int i = 2; i < firstCompressedData.size(); i++)
			bitStream.pushBack(firstCompressedData[i]);
		for (unsigned int index = firstIDAT + 1; index < lastIDAT; index++)
			for (unsigned char i : chunks[index].data)
				bitStream.pushBack(i);
		
		std::vector<unsigned int> fixedTreeSymbols;
		fixedTreeSymbols.reserve(288);
		std::vector<unsigned int> fixedTreeLengths;
		fixedTreeLengths.reserve(288);
		for (unsigned int i = 0; i < 288; i++) {
			fixedTreeSymbols.push_back(i);
			if (i <= 143)
				fixedTreeLengths.push_back(8);
			else if (i <= 255)
				fixedTreeLengths.push_back(9);
			else if (i <= 279)
				fixedTreeLengths.push_back(7);
			else//if (i <= 287)
				fixedTreeLengths.push_back(8);
		}
		Tree fixedTree = Tree(fixedTreeSymbols, fixedTreeLengths);
		
		std::vector<unsigned char> dataStream;
		dataStream.reserve((1 + format.width) * format.height);
		
		bool lastBlock = false;
		while (!lastBlock) {
			lastBlock = bitStream.read(pos, 1) == 1;
			pos += 1;
			unsigned short compressionMethod = (unsigned short) bitStream.read(pos, 2);
			pos += 2;
			
			if (compressionMethod == 1) {
				while (true) {
					unsigned int code = fixedTree.uncompressOneCode(bitStream, pos, &pos);
					
					
					if (code < 256) {
						dataStream.emplace_back(code);
					} else if (code == 256) {
						break;
					} else {
						code -= 257;
						unsigned int length = lengths[code];
						length += bitStream.read(pos, lengthsExtraBits[code]);
						pos += lengthsExtraBits[code];
						
						unsigned int offsetCode = bitStream.read(pos, 5, true); // reads inverted
						pos += 5;
						unsigned int offset = offsets[offsetCode];
						offset += bitStream.read(pos, offsetsExtraBits[offsetCode]);
						pos += offsetsExtraBits[offsetCode];
						
						for (int i = 0; i < length; i++) {
							dataStream.emplace_back(dataStream[dataStream.size() - offset]);
						}
					}
				}
			} else if (compressionMethod == 2) {
				// Reads the 14 bit header of the compressed block
				unsigned int hlit = bitStream.read(pos, 5) + 257;
				unsigned int hdist = bitStream.read(pos + 5, 5) + 1;
				unsigned int hlen = bitStream.read(pos + 10, 4) + 4;
				pos += 14;
				
				// Creates the huffman tree that reads the length of the literal and distance trees
				std::vector<unsigned int> metaTreeSymbols;
				metaTreeSymbols.reserve(19);
				std::vector<unsigned int> metaTreeLengths(19);
				{
					unsigned int i = 0;
					for (; i < hlen; i++) {
						metaTreeSymbols.push_back(i);
						metaTreeLengths[metaTreeOrder[i]] = bitStream.read(pos, 3);
						pos += 3;
					}
					for (; i < 19; i++) {
						metaTreeSymbols.push_back(i);
						metaTreeLengths[metaTreeOrder[i]] = 0;
					}
				}
				Tree metaTree(metaTreeSymbols, metaTreeLengths);
				
				std::vector<unsigned int> litAndDistLengths;
				litAndDistLengths.reserve(hlit + hdist);
				
				while (litAndDistLengths.size() < hlit + hdist) {
					unsigned int code = metaTree.uncompressOneCode(bitStream, pos, &pos);
					
					if (code <= 15) {
						litAndDistLengths.push_back(code);
					} else if (code == 16) {
						unsigned int extra = bitStream.read(pos, 2);
						pos += 2;
						
						unsigned int copyPos = (unsigned int) (litAndDistLengths.size() - 1);
						for (unsigned int i = 0; i < 3 + extra; i++) {
							litAndDistLengths.push_back(litAndDistLengths[copyPos]);
						}
					} else if (code == 17) {
						unsigned int extra = bitStream.read(pos, 3);
						pos += 3;
						
						for (unsigned int i = 0; i < 3 + extra; i++) {
							litAndDistLengths.emplace_back(0);
						}
					} else/*if (code == 18)*/{
						unsigned int extra = bitStream.read(pos, 7);
						pos += 7;
						
						for (unsigned int i = 0; i < 11 + extra; i++) {
							litAndDistLengths.emplace_back(0);
						}
					}
				}
				
				std::vector<unsigned int> litSymbols;
				litSymbols.reserve(hlit);
				std::vector<unsigned int> distSymbols;
				distSymbols.reserve(hdist);
				
				for (unsigned int i = 0; i < hlit; i++)
					litSymbols.push_back(i);
				for (unsigned int i = 0; i < hdist; i++)
					distSymbols.push_back(i);
				
				std::vector<unsigned int> litLengths;
				litLengths.reserve(hlit);
				std::vector<unsigned int> distLengths;
				distLengths.reserve(hdist);
				for (unsigned int i = 0; i < hlit; i++)
					litLengths.emplace_back(litAndDistLengths[i]);
				for (unsigned int i = 0; i < hdist; i++)
					distLengths.emplace_back(litAndDistLengths[hlit + i]);
				
				Tree literalTree(litSymbols, litLengths);
				Tree distTree(distSymbols, distLengths);
				
				while (true) {
					unsigned int code = literalTree.uncompressOneCode(bitStream, pos, &pos);
					
					if (code < 256) {
						dataStream.push_back((unsigned char) code);
					} else if (code == 256) {
						break;
					} else {
						code -= 257;
						unsigned int length = lengths[code];
						length += bitStream.read(pos, lengthsExtraBits[code]);
						pos += lengthsExtraBits[code];
						
						unsigned int offsetCode = distTree.uncompressOneCode(bitStream, pos, &pos);
						
						unsigned int offset = offsets[offsetCode];
						offset += bitStream.read(pos, offsetsExtraBits[offsetCode], false);
						pos += offsetsExtraBits[offsetCode];
						
						for (int i = 0; i < length; i++) {
							dataStream.push_back(dataStream[dataStream.size() - offset]);
						}
					}
				}
			} else/*if (compressionMethod == 0)*/{
				unsigned int offsetFromByte = pos & 0x7;
				if (offsetFromByte != 0)
					pos += (8 - offsetFromByte);
				
				unsigned int length = bitStream.read(pos, 16);
				pos += 32;
				
				for (unsigned int i = 0; i < length; i++) {
					dataStream.emplace_back(bitStream.read(pos, 8));
					pos += 8;
				}
			}
		}
		
		// todo: add pixel creation for types 3, 2 and 4
		if (format.colorFormat == 3) {
			PixelRGB* pixels = new PixelRGB[format.width * format.height];
			
			unsigned int actualWidth = 1 + format.width;
			for (unsigned int y = 0; y < format.height; y++) {
				for (unsigned int x = 0; x < format.width; x++) {
					unsigned int i = 1 + x + y * actualWidth;
					pixels[x + y * format.width].r = (unsigned char) ((*palette)[dataStream[i]] >> 16 & 0xFF);
					pixels[x + y * format.width].g = (unsigned char) ((*palette)[dataStream[i]] >> 8 & 0xFF);
					pixels[x + y * format.width].b = (unsigned char) ((*palette)[dataStream[i]] & 0xFF);
				}
			}
			
			data = (unsigned char*) pixels;
			format.colorFormat = VIVID_IMAGE_FORMAT_RGB;
		} else if (format.colorFormat == 2) {
			PixelRGB* pixels = new PixelRGB[format.width * format.height];
			
			unsigned int actualWidth = 1 + format.width * 3;
			for (unsigned int y = 0; y < format.height; y++) {
				for (unsigned int x = 0; x < format.width; x++) {
					unsigned int i = 1 + 3 * x + y * actualWidth;
					pixels[x + y * format.width].r = (unsigned char) dataStream[i + 0];
					pixels[x + y * format.width].g = (unsigned char) dataStream[i + 1];
					pixels[x + y * format.width].b = (unsigned char) dataStream[i + 2];
				}
			}
			
			data = (unsigned char*) pixels;
			format.colorFormat = VIVID_IMAGE_FORMAT_RGB;
		} else if (format.colorFormat == 6) {
			PixelRGBA* pixels = new PixelRGBA[format.width * format.height];
			
			unsigned int actualWidth = 1 + format.width * 4;
			for (unsigned int y = 0; y < format.height; y++) {
				for (unsigned int x = 0; x < format.width; x++) {
					unsigned int i = 1 + 4 * x + y * actualWidth;
					pixels[x + y * format.width].r = (unsigned char) dataStream[i + 0];
					pixels[x + y * format.width].g = (unsigned char) dataStream[i + 1];
					pixels[x + y * format.width].b = (unsigned char) dataStream[i + 2];
					pixels[x + y * format.width].a = (unsigned char) dataStream[i + 3];
				}
			}
			
			data = (unsigned char*) pixels;
			format.colorFormat = VIVID_IMAGE_FORMAT_RGBA;
		}
	}
	
	Image::~Image() {
		delete[] data;
	}
	
	void Image::loadChunks(std::vector<Chunk>& chunks, const unsigned char* data, unsigned int size) {
		unsigned int offset = 8;
		while (offset < size)
			chunks.push_back(loadChunk(data, offset));
	}
	
	Chunk Image::loadChunk(const unsigned char* data, unsigned int& offset) {
		unsigned int chunkLength = (data[offset + 0] << 24) | (data[offset + 1] << 16) | (data[offset + 2] << 8) | (data[offset + 3]);
		offset += 4;
		
		char charArray[5];
		charArray[0] = data[offset + 0];
		charArray[1] = data[offset + 1];
		charArray[2] = data[offset + 2];
		charArray[3] = data[offset + 3];
		charArray[4] = 0;
		std::string chunkType(charArray);
		offset += 4;
		
		std::vector<unsigned char> chunkData;
		chunkData.reserve(chunkLength);
		
		for (int p = 0; p < chunkLength; p++) {
			chunkData.push_back(data[offset + p]);
		}
		offset += chunkLength;
		
		unsigned int chunkCRC = (data[offset + 0] << 24) | (data[offset + 1] << 16) | (data[offset + 2] << 8) | (data[offset + 3]);
		offset += 4;
		
		return Chunk(chunkLength, chunkType, chunkData, chunkCRC);
	}
	
}}
