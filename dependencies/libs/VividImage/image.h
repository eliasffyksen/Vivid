//
// Created by Ole on 10.09.2017.
//

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define VIVID_OPENGL

#ifdef VIVID_OPENGL
#define VIVID_IMAGE_FORMAT_RGB 0x1907
#define VIVID_IMAGE_FORMAT_RGBA 0x1908
#else
#define VIVID_IMAGE_FORMAT_RGB 3
#define VIVID_IMAGE_FORMAT_RGBA 4
#endif

namespace vivid { namespace util {
	
	struct Chunk {
		unsigned int length;
		std::string type;
		std::vector<unsigned char> data;
		unsigned int crc;
		
		Chunk(unsigned int length, std::string type, std::vector<unsigned char>& data, unsigned int crc)
				: length(length), type(std::move(type)), data(data), crc(crc) {}
	};
	
	struct PixelRGB {
		union {
			struct {
				unsigned char red, green, blue;
			};
			struct {
				unsigned char r{}, g{}, b{};
			};
		};
		
		PixelRGB(unsigned char red, unsigned char green, unsigned char blue)
				: red(red), green(green), blue(blue) {}
		PixelRGB()
				: red(0), green(0), blue(0) {}
		
		unsigned int color() const { return ((unsigned int) 0xFF) << 24 | r << 16 | g << 8 | b; }
	};
	
	struct PixelRGBA {
		union {
			struct {
				unsigned char red, green, blue, alpha;
			};
			struct {
				unsigned char r{}, g{}, b{}, a{};
			};
		};
		
		PixelRGBA(unsigned char alpha, unsigned char red, unsigned char green, unsigned char blue)
				: alpha(alpha), red(red), green(green), blue(blue) {}
		PixelRGBA()
				: alpha(0), red(0), green(0), blue(0) {}
		PixelRGBA(const PixelRGB& pixelRGB)
				: alpha(255), red(pixelRGB.red), green(pixelRGB.green), blue(pixelRGB.blue) {}
		
		unsigned int color() const { return a << 24 | r << 16 | g << 8 | b; }
	};
	
	struct ImageFormat {
		unsigned int width;
		unsigned int height;
		unsigned int bitDepth;
		unsigned int colorFormat;
		unsigned int compressionMethod;
		unsigned int filterMethod;
		unsigned int interlaceMethod;
		
		ImageFormat()
				: width(0), height(0), bitDepth(0), colorFormat(0) {}
	};
	
	class Image {
	private:
		ImageFormat format;
		unsigned char* data;
	public:
		explicit Image(const std::string& path);
		~Image();
		
		inline const PixelRGBA getPixel(unsigned int& x, unsigned int& y) {
			if (getColorFormat() == VIVID_IMAGE_FORMAT_RGBA)
				return ((PixelRGBA*) data)[x + y * format.width];
			if (getColorFormat() == VIVID_IMAGE_FORMAT_RGB)
				return PixelRGBA(((PixelRGB*) data)[x + y * format.width]);
		}
		inline const unsigned char* const getPixels() const { return data; }
		inline const unsigned int& getWidth() const { return format.width; }
		inline const unsigned int& getHeight() const { return format.height; }
		inline const unsigned int& getBitDepth() const { return format.bitDepth; }
		inline const unsigned int& getColorFormat() const { return format.colorFormat; }
		
		inline const ImageFormat& getFormat() const { return format; }
	private:
		void loadChunks(std::vector<Chunk>& chunks, const unsigned char* data, unsigned int size);
		Chunk loadChunk(const unsigned char* data, unsigned int& offset);
	};
	
}}
