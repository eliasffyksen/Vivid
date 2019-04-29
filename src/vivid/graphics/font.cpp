//
// Created by stroh on 29/12/2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <math.h>
#include "font.h"
#include "vivid/scenegraph/textureatlas.h"

namespace vivid { namespace graphics {

#define ON_CURVE_BIT (1 << 0)
#define X_SHORT_VEC_BIT (1 << 1)
#define Y_SHORT_VEC_BIT (1 << 2)
#define REPEAT_BIT (1 << 3)
#define SAME_X_OR_SIGN_BIT (1 << 4)
#define SAME_Y_OR_SIGN_BIT (1 << 5)

	static float abs(float a) { return (a >= 0 ? a : -a); }

	void hexdump(const unsigned char *data, const unsigned int &start, const unsigned int &length) {
		for (int i = start; i < start + 16 * (length / 16); ++i) {
			if ((i - start) % 16 == 0) {
				std::printf("%03X: ", i);
			}
			std::printf("%02X ", data[i]);
			if ((i - start + 1) % 16 == 0) {
				printf(" ");
				printf("|");
				for (int j = i - 15; j <= i; j++) {
					printf("%c", (data[j] >= 32 && data[j] < 127 ? data[j] : '.'));
				}
				printf("|");
				std::printf("\n");
			}
		}
		if (length % 16 == 0)
			return;
		std::printf("%03X: ", start + length - length % 16);
		for (int i = start + length - length % 16; i < start + length; i++) {
			std::printf("%02X ", data[i]);
		}
		for (int s = 0; s < 1 + 3 * (16 - length % 16); s++) {
			printf(" ");
		}
		printf("|");
		for (int i = start + length - length % 16; i < start + length; i++) {
			printf("%c", (data[i] >= 32 && data[i] < 127 ? data[i] : '.'));
		}
		printf("|");
		printf("\n");
	}

	void hexdump(const unsigned char *data, const unsigned int &length) { hexdump(data, 0, length); }

	std::string UINT32ToTag(const unsigned int &tag) {
		std::stringstream ss;
		ss << (unsigned char) (tag >> 24 & 0xFF) << (unsigned char) (tag >> 16 & 0xFF)
		   << (unsigned char) (tag >> 8 & 0xFF) << (unsigned char) (tag & 0xFF);
		return ss.str();
	}

	unsigned int tagToUINT32(const std::string &tag) {
		return (unsigned int) ((tag[0] << 24) | (tag[1] << 16) | (tag[2] << 8) | tag[3]);
	}

	unsigned long long int getUINT64(const unsigned char *data) {
		return ((unsigned long long int) data[0] << 56) |
		       ((unsigned long long int) data[1] << 48) |
		       ((unsigned long long int) data[2] << 40) |
		       ((unsigned long long int) data[3] << 32) |
		       ((unsigned long long int) data[4] << 24) |
		       ((unsigned long long int) data[5] << 16) |
		       ((unsigned long long int) data[6] << 8) |
		       ((unsigned long long int) data[7]);
	}

	unsigned int getUINT32(const unsigned char *data) {
		return (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
	}

	unsigned short getUINT16(const unsigned char *data) { return (data[0] << 8) | data[1]; }

	unsigned char getUINT8(const unsigned char *data) { return data[0]; }

	int getINT32(const unsigned char *data) { return (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3]; }

	short getINT16(const unsigned char *data) { return (data[0] << 8) | data[1]; }

	char getINT8(const unsigned char *data) { return data[0]; }

	float getFixed(const unsigned char *data) { return getUINT32(data) / (2 ^ 16); }

	void parseData(std::vector<Table> &tables, unsigned char *data) {
		const unsigned char *startOfSFNT = data;
		unsigned int scalerType = getUINT32(data);
		data += 4;
		unsigned int numTables = getUINT16(data);
		data += 2;
//		unsigned int searchRange = getUINT16(data);
		data += 2;
//		unsigned int entrySelector = getUINT16(data);
		data += 2;
//		unsigned int rangeShift = getUINT16(data);
		data += 2;

//		printf("Scaler type: %08X\n", scalerType);
//		printf("num Tables: %d\n", numTables);
//		printf("Search Range: %d\n", searchRange);
//		printf("Entry Selector: %d\n", entrySelector);
//		printf("Range Shift: %d\n", rangeShift);
//		printf("\n");

		while (numTables-- > 0) {
			unsigned int tag = getUINT32(data);
			data += 4;
			unsigned int checkSum = getUINT32(data);
			data += 4;
			unsigned int offset = getUINT32(data);
			data += 4;
			unsigned int length = getUINT32(data);
			data += 4;

//			printf("Tag:   %c%c%c%c\n", tag >> 24, tag >> 16 & 0xFF, tag >> 8 & 0xFF, tag & 0xFF);
//			printf("Checksum: %u\n", checkSum);

//			unsigned int calculatedCheckSum = 0;
//			auto *table = (unsigned int *) (startOfSFNT + offset);
//			unsigned int nInts = (length + 3) / 4;
//			printf("%d", nInts);
//			while (nInts-- > 0) {
//				if (!(tag == tagToUINT32("head") && nInts == 11))
//					calculatedCheckSum += getUINT32((unsigned char *) table);
//				table++;
//			}

//			printf("Checksum: %s\n", (calculatedCheckSum == checkSum) ? "Correct" : "Wrong!");
//			printf("Offset: %d\n", offset);
//			printf("Length: %d\n", length);
			tables.emplace_back(tag, checkSum, offset, length, startOfSFNT + offset);
		}
	}

	HEADtable parseHEADtable(const Table &table) {
		const unsigned char *p = table.table;

		HEADtable head{};

		head.version = getFixed(p);
		p += 4;
		head.fontRevision = getFixed(p);
		p += 4;
		head.checkSumAdjustment = getUINT32(p);
		p += 4;
		head.magicNumber = getUINT32(p);
		p += 4;
		head.flags = getUINT16(p);
		p += 2;
		head.unitsPerEm = getUINT16(p);
		p += 2;
		head.created = getUINT64(p);
		p += 8;
		head.modified = getUINT64(p);
		p += 8;
		head.xMin = getINT16(p);
		p += 2;
		head.yMin = getINT16(p);
		p += 2;
		head.xMax = getINT16(p);
		p += 2;
		head.yMax = getINT16(p);
		p += 2;
		head.macStyle = getUINT16(p);
		p += 2;
		head.lowestRecPPEM = getUINT16(p);
		p += 2;
		head.fontDirectionHint = getINT16(p);
		p += 2;
		head.indexToLocFormat = getINT16(p);
		p += 2;
		head.glpyhDataFormat = getINT16(p);
		p += 2;

//		printf("version: %f\n", head.version);
//		printf("fontRevision: %f\n", head.fontRevision);
//		printf("checkSumAdjustment: %u\n", head.checkSumAdjustment);
//		printf("magicNumber: %08X\n", head.magicNumber);
//		printf("flags: " BYTE_TO_BINARY_PATTERN"" BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(head.flags >> 8), BYTE_TO_BINARY(head.flags));
//		printf("UnitsPerEm: %u\n", head.unitsPerEm);
//		printf("created: %llu\n", head.created);
//		printf("modified: %llu\n", head.modified);
//		printf("xMin: %d\n", head.xMin);
//		printf("xMax: %d\n", head.xMax);
//		printf("yMin: %d\n", head.yMin);
//		printf("yMax: %d\n", head.yMax);
//		printf("macStyle: " BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(head.macStyle));
//		printf("lowestRecPPEM: %u\n", head.lowestRecPPEM);
//		printf("fontDirectionHint: %d\n", head.fontDirectionHint);
//		printf("indexToLocFormat: %d\n", head.indexToLocFormat);
//		printf("glpyhDataFormat: %d\n", head.glpyhDataFormat);

		return head;
	}

	NAMEtable parseNAMEtable(const Table &table) {
		const unsigned char *tablep = table.table;
		unsigned int format = getUINT16(tablep);
		tablep += 2;
		unsigned int count = getUINT16(tablep);
		tablep += 2;
		unsigned int stringOffset = getUINT16(tablep);
		tablep += 2;

		printf("format: %u\n", format);
		printf("count: %u\n", count);
		printf("stringOffset: %u\n", stringOffset);

		NAMEtable nametable;

		while (count-- > 0) {
			NameRecord record;
			record.platformID = getUINT16(tablep);
			tablep += 2;
			record.platformSpecificID = getUINT16(tablep);
			tablep += 2;
			record.languageID = getUINT16(tablep);
			tablep += 2;
			record.nameID = getUINT16(tablep);
			tablep += 2;
			unsigned int length = getUINT16(tablep);
			tablep += 2;
			unsigned int offset = getUINT16(tablep);
			tablep += 2;

			std::stringstream ss;
			for (int c = 0; c < length; c++) {
				ss << *(table.table + stringOffset + offset + c);
			}
			record.literal = ss.str();

			nametable.strings.push_back(record);

			printf("String %u:\n", count);
			printf("platformID %u\n", record.platformID);
			printf("platformSpecificID %u\n", record.platformSpecificID);
			printf("languageID %u\n", record.languageID);
			printf("nameID %u\n", record.nameID);
			printf("length %u\n", length);
			printf("offset %u\n", offset);
			printf("String literal: ");
			std::cout << record.literal << std::endl;
			printf("\n");
		}

		return nametable;
	}

	MAXPtable parseMAXPtable(const Table &table) {
		const unsigned char *p = table.table;

		MAXPtable maxp{};

		maxp.version = getFixed(p);
		p += 4;
		maxp.numGlyphs = getUINT16(p);
		p += 2;
		maxp.maxPoints = getUINT16(p);
		p += 2;
		maxp.maxContours = getUINT16(p);
		p += 2;
		maxp.maxComponentPoints = getUINT16(p);
		p += 2;
		maxp.maxComponentContours = getUINT16(p);
		p += 2;
		maxp.maxZones = getUINT16(p);
		p += 2;
		maxp.maxTwilightPoints = getUINT16(p);
		p += 2;
		maxp.maxStorage = getUINT16(p);
		p += 2;
		maxp.maxFunctionDefs = getUINT16(p);
		p += 2;
		maxp.maxInstructionDefs = getUINT16(p);
		p += 2;
		maxp.maxStackElements = getUINT16(p);
		p += 2;
		maxp.maxSizeOfInstructions = getUINT16(p);
		p += 2;
		maxp.maxComponentElements = getUINT16(p);
		p += 2;
		maxp.maxComponentDepth = getUINT16(p);
		p += 2;

//		printf("version: %f\n", maxp.version);
//		printf("numGlyphs: %u\n", maxp.numGlyphs);
//		printf("maxPoints: %u\n", maxp.maxPoints);
//		printf("maxContours: %u\n", maxp.maxContours);
//		printf("maxComponentPoints: %u\n", maxp.maxComponentPoints);
//		printf("maxComponentContours: %u\n", maxp.maxComponentContours);
//		printf("maxZones: %u\n", maxp.maxZones);
//		printf("maxTwilightPoints: %u\n", maxp.maxTwilightPoints);
//		printf("maxStorage: %u\n", maxp.maxStorage);
//		printf("maxFunctionDefs: %u\n", maxp.maxFunctionDefs);
//		printf("maxInstructionDefs: %u\n", maxp.maxInstructionDefs);
//		printf("maxStackElements: %u\n", maxp.maxStackElements);
//		printf("maxSizeOfInstructions: %u\n", maxp.maxSizeOfInstructions);
//		printf("maxComponentElements: %u\n", maxp.maxComponentElements);
//		printf("maxComponentDepth: %u\n", maxp.maxComponentDepth);

		return maxp;
	}

	CMAPtable parseCMAPtable(const Table &table) {
		const unsigned char *p = table.table;
		unsigned int version = getUINT16(p);
		p += 2;
		unsigned int nSubtables = getUINT16(p);
		p += 2;

//		printf("version: %u\n", version);
//		printf("nSubtables: %u\n", nSubtables);
//		printf("\n");

		CMAPtable cmap{};

		while (nSubtables-- > 0) {
			unsigned int platformID = getUINT16(p);
			p += 2;
			unsigned int platformSpecificID = getUINT16(p);
			p += 2;
			unsigned int offset = getUINT32(p);
			p += 4;
			if (platformID == 0) {

//				printf("platformID: %u\n", platformID);
//				printf("platformSpecificID: %u\n", platformSpecificID);
//				printf("offset: %u\n", offset);

				const unsigned char *subtable = table.table + offset;
				unsigned int format = getUINT16(subtable);
				subtable += 2;

				if (format == 4) {
//					printf("Subtable format: %u\n", format);
					unsigned int length = getUINT16(subtable);
					subtable += 2;
					unsigned int language = getUINT16(subtable);
					subtable += 2;
					unsigned int segCountX2 = getUINT16(subtable);
					subtable += 2;
//					unsigned int searchRange = getUINT16(subtable);
					subtable += 2;
//					unsigned int entrySelector = getUINT16(subtable);
					subtable += 2;
//					unsigned int rangeShift = getUINT16(subtable);
					subtable += 2;
					unsigned int endCode[segCountX2 / 2];
					for (int e = 0; e < segCountX2 / 2; e++) {
						endCode[e] = getUINT16(subtable);
						subtable += 2;
					}
//					unsigned int reservedPad = getUINT16(subtable);
					subtable += 2;
					unsigned int startCode[segCountX2 / 2];
					for (int e = 0; e < segCountX2 / 2; e++) {
						startCode[e] = getUINT16(subtable);
						subtable += 2;
					}
					unsigned int idDelta[segCountX2 / 2];
					for (int e = 0; e < segCountX2 / 2; e++) {
						idDelta[e] = getUINT16(subtable);
						subtable += 2;
					}
					unsigned int idRangeOffset[segCountX2 / 2];
					for (int e = 0; e < segCountX2 / 2; e++) {
						idRangeOffset[e] = getUINT16(subtable);
						subtable += 2;
					}

//					printf("length: %u\n", length);
//					printf("language: %u\n", language);
//					printf("segCount: %u\n", segCountX2 / 2);

					for (unsigned int c = 0; c < 0xFF; c++) {
						unsigned int seg = 0;
						while (c > endCode[seg++]);
						seg--;
						unsigned int glyphIndex = 0;
						if (startCode[seg] <= c) {
							if (idRangeOffset[seg] == 0) {
								glyphIndex = (idDelta[seg] + c) & 0xFFFF;
							} else {
								glyphIndex = *(subtable - segCountX2 / 2 + seg + idRangeOffset[seg] +
								               2 * (c - startCode[seg]));
								if (glyphIndex != 0) {
									glyphIndex += idDelta[seg];
									glyphIndex &= 0xFFFF;
								}
							}
						}
						cmap.glyphIndices[c] = glyphIndex;
					}
				}
			}

//			printf("\n");
		}

		return cmap;
	}

	HHEAtable parseHHEAtable(const Table &table) {
		const unsigned char *p = table.table;
		HHEAtable hhea;
		hhea.version = getFixed(p);
		p += 4;
		hhea.ascent = getINT16(p);
		p += 2;
		hhea.descent = getINT16(p);
		p += 2;
		hhea.lineGap = getINT16(p);
		p += 2;
		hhea.advanceWidthMax = getUINT16(p);
		p += 2;
		hhea.minLeftSideBearing = getINT16(p);
		p += 2;
		hhea.minRightSideBearing = getINT16(p);
		p += 2;
		hhea.xMaxExtent = getINT16(p);
		p += 2;
		hhea.caretSlopeRise = getINT16(p);
		p += 2;
		hhea.caretSlopeRun = getINT16(p);
		p += 2;
		hhea.caretOffset = getINT16(p);
		p += 2;
		p += 4 * 2;
		hhea.metricDataFormat = getINT16(p);
		p += 2;
		hhea.numOfLongHorMetrics = getUINT16(p);

		return hhea;
	}

	HMTXtable parseHMTXtable(const Table &table, const HHEAtable &hhea, const MAXPtable &maxp) {
		const unsigned char *p = table.table;
		HMTXtable hmtx;
		hmtx.advanceWidth.resize(maxp.numGlyphs);
		hmtx.leftSideBearing.resize(maxp.numGlyphs);

		for (int g = 0; g < hhea.numOfLongHorMetrics; g++) {
			hmtx.advanceWidth[g] = getUINT16(p);
			p += 2;
			hmtx.leftSideBearing[g] = getINT16(p);
			p += 2;
		}
		for (int g = hhea.numOfLongHorMetrics; g < maxp.numGlyphs; g++) {
			hmtx.advanceWidth[g] = hmtx.advanceWidth[hhea.numOfLongHorMetrics - 1];
			hmtx.leftSideBearing[g] = getINT16(p);
			p += 2;
		}

		return hmtx;
	}

	VHEAtable parseVHEAtable(const Table &table) {
		const unsigned char *p = table.table;
		VHEAtable vhea;
		vhea.version = getFixed(p);
		p += 4;
		vhea.vertTypoAscender = getINT16(p);
		p += 2;
		vhea.vertTypoDescender = getINT16(p);
		p += 2;
		vhea.vertTypeLineGap = getINT16(p);
		p += 2;
		vhea.advanceHeightMax = getUINT16(p);
		p += 2;
		vhea.minTopSideBearing = getINT16(p);
		p += 2;
		vhea.minBottomSideBearing = getINT16(p);
		p += 2;
		vhea.yMaxExtent = getINT16(p);
		p += 2;
		vhea.caretSlopeRise = getINT16(p);
		p += 2;
		vhea.caretSlopeRun = getINT16(p);
		p += 2;
		vhea.caretOffset = getINT16(p);
		p += 2;
		p += 4 * 2;
		vhea.metricDataFormat = getINT16(p);
		p += 2;
		vhea.numOfLongVerMetrics = getUINT16(p);

		return vhea;
	}

	VMTXtable parseVMTXtable(const Table &table, const VHEAtable &vhea, const MAXPtable &maxp) {
		const unsigned char *p = table.table;
		VMTXtable vmtx;
		vmtx.advanceHeight.resize(maxp.numGlyphs);
		vmtx.topSideBearing.resize(maxp.numGlyphs);

		for (int g = 0; g < vhea.numOfLongVerMetrics; g++) {
			vmtx.advanceHeight[g] = getUINT16(p);
			p += 2;
			vmtx.topSideBearing[g] = getINT16(p);
			p += 2;
		}
		for (int g = vhea.numOfLongVerMetrics; g < maxp.numGlyphs; g++) {
			vmtx.advanceHeight[g] = vmtx.advanceHeight[vhea.numOfLongVerMetrics - 1];
			vmtx.topSideBearing[g] = getINT16(p);
			p += 2;
		}

		return vmtx;
	}

	LOCAtable parseLOCAtable(const Table &table, const HEADtable &head, const MAXPtable &maxp) {
		const unsigned char *p = table.table;
		LOCAtable loca;

		for (int i = 0; i < maxp.numGlyphs + 1; i++) {
			if (head.indexToLocFormat == 1) {
				loca.offsets.push_back(getUINT32(p));
				p += 4;
			} else {
				loca.offsets.push_back(2 * (unsigned int) getUINT16(p));
				p += 2;
			}
		}

		return loca;
	}

	void readSimpleGlyph(const unsigned char *p, const unsigned int &nContours, Glyph &glyph, const float &scale) {
		glyph.endPoints.resize(nContours);
		for (int c = 0; c < nContours; c++) {
			glyph.endPoints[c] = getUINT16(p);
			p += 2;
//			printf("endpoint[%d]: %u\n", c, glyph.endPoints[c]);
		}
		int numPoints = glyph.endPoints[nContours - 1] + 1;
		unsigned int instructionLength = getUINT16(p);
		p += 2;
		unsigned int instructions[instructionLength];
		for (int i = 0; i < instructionLength; i++) {
			instructions[i] = getUINT8(p);
			p += 1;
		}
//		printf("instructionLength: %u\n", instructionLength);

		unsigned int flags[numPoints];
		for (int pi = 0; pi < numPoints; pi++) {
			flags[pi] = getUINT8(p);
			p += 1;
//			printf("flags(%d): " BYTE_TO_BINARY_PATTERN"\n", pi, BYTE_TO_BINARY(flags[pi]));
			if (flags[pi] & REPEAT_BIT) {
				unsigned int repeat = getUINT8(p);
				p += 1;
				while (repeat-- > 0) {
					pi++;
					flags[pi] = flags[pi - 1];
				}
			}
		}

//		for (int i = 0; i < numPoints; i++) {
//			printf("flags(%d): " BYTE_TO_BINARY_PATTERN"\n", i, BYTE_TO_BINARY(flags[i]));
//		}


		glyph.xCoords.resize((size_t) numPoints);
		glyph.yCoords.resize((size_t) numPoints);
		glyph.onGlyph.resize((size_t) numPoints);

		int xMaxActual = 0;
		int xMinActual = 0;
		int yMaxActual = 0;
		int yMinActual = 0;

		for (int xc = 0; xc < numPoints; xc++) {
			unsigned int flag = flags[xc];
			glyph.onGlyph[xc] = flag & ON_CURVE_BIT;
			if (flag & X_SHORT_VEC_BIT) {
				int x = -getUINT8(p);
				p += 1;
				if (flag & SAME_X_OR_SIGN_BIT) {
					x = -x;
				}
				glyph.xCoords[xc] = (xc == 0 ? (float) x : glyph.xCoords[xc - 1]) + (float) x;
			} else {
				if (flag & SAME_X_OR_SIGN_BIT) {
					if (xc > 0)
						glyph.xCoords[xc] = glyph.xCoords[xc - 1];
					else {
						glyph.xCoords[xc] = 0;
					}
				} else {
					short x = getINT16(p);
					p += 2;
					glyph.xCoords[xc] = (xc == 0 ? (float) x : glyph.xCoords[xc - 1]) + (float) x;
				}
			}
			if (xc == 0) {
				xMinActual = glyph.xCoords[0];
				xMaxActual = glyph.xCoords[0];
			} else {
				if (glyph.xCoords[xc] > xMaxActual)
					xMaxActual = glyph.xCoords[xc];
				if (glyph.xCoords[xc] < xMinActual)
					xMinActual = glyph.xCoords[xc];
			}
		}

		for (int yc = 0; yc < numPoints; yc++) {
			unsigned int flag = flags[yc];
			if (flag & Y_SHORT_VEC_BIT) {
				int y = -getUINT8(p);
				p += 1;
				if (flag & SAME_Y_OR_SIGN_BIT) {
					y = -y;
				}
				glyph.yCoords[yc] = (yc == 0 ? (float) y : glyph.yCoords[yc - 1]) + (float) y;
			} else {
				if (flag & SAME_Y_OR_SIGN_BIT) {
					if (yc > 0)
						glyph.yCoords[yc] = glyph.yCoords[yc - 1];
					else
						glyph.yCoords[yc] = 0;
				} else {
					short y = getINT16(p);
					p += 2;
					glyph.yCoords[yc] = (yc == 0 ? (float) y : glyph.yCoords[yc - 1]) + (float) y;
				}
			}
			if (yc == 0) {
				yMinActual = (int) glyph.yCoords[0];
				yMaxActual = (int) glyph.yCoords[0];
			} else {
				if (glyph.yCoords[yc] > yMaxActual)
					yMaxActual = (int) glyph.yCoords[yc];
				if (glyph.yCoords[yc] < yMinActual)
					yMinActual = (int) glyph.yCoords[yc];
			}
		}

		std::cout << glyph.yMax << std::endl;
		std::cout << glyph.yMin << std::endl;
		std::cout << std::endl;

		xMaxActual -= xMinActual;
		yMaxActual -= yMinActual;
		glyph.xMax = xMaxActual;
		glyph.yMax = yMaxActual;
		for (int c = 0; c < glyph.xCoords.size(); c++) {
			glyph.xCoords[c] = ((float) (glyph.xCoords[c] - xMinActual)) / yMaxActual;
			glyph.yCoords[c] = ((float) (glyph.yCoords[c] - yMinActual)) / yMaxActual;
		}
	}

	void readCompoundGlyph(const unsigned char *p, const int &nContours, Glyph &glyph) {

	}

	void parseGLYFtable(GLYFtable &glyf, const LOCAtable &loca, const unsigned int &g) {
//		for (int g = 0; g < loca.offsets.size(); g++) {
//			if (g == 26)
//				printf("\nGlyph %d:\n", g);
		const unsigned char *p = glyf.table.table + loca.offsets[g];
		int nContours = getINT16(p);
		p += 2;
		glyf.glyphs[g].xMin = getINT16(p);
		p += 2;
		glyf.glyphs[g].yMin = getINT16(p);
		p += 2;
		glyf.glyphs[g].xMax = getINT16(p);
		p += 2;
		glyf.glyphs[g].yMax = getINT16(p);
		p += 2;

//		printf("nContours: %d\n", nContours);
//		printf("xMin: %d\n", glyf.glyphs[g].xMin);
//		printf("xMax: %d\n", glyf.glyphs[g].xMax);
//		printf("yMin: %d\n", glyf.glyphs[g].yMin);
//		printf("yMax: %d\n", glyf.glyphs[g].yMax);
		if (nContours > 0) {
			readSimpleGlyph(p, (unsigned int) nContours, glyf.glyphs[g], 1000);
		} else if (nContours < 0) {
			readCompoundGlyph(p, (unsigned int) -nContours, glyf.glyphs[g]);
		}
	}

	void setPixel(unsigned int *pixels, int width, int height, float x, float y, float intensity = 1.0f) {
		int ix = (int) x;
		int iy = (int) y;
		if (ix >= 0 && ix < width && iy >= 0 && iy < height) {
			int curInt = (int) (intensity * 0xFF);
			if (curInt > 0xFF)
				curInt = 0xFF;
			pixels[ix + iy * width] = 0xFF000000 | curInt << 16 | curInt << 8 | curInt;
		}
	}

	void setPixelAA(unsigned int *pixels, int width, int height, float x, float y) {
		float fx = x - (int) x;
		float fy = y - (int) y;

		setPixel(pixels, width, height, x, y, 1.0);
//		setPixel(pixels, width, height, x-0.75f, y, .45);
//		setPixel(pixels, width, height, x-0.75f, y+0.75f, .45);
//		setPixel(pixels, width, height, x-0.75f, y-0.75f, .45);
//		setPixel(pixels, width, height, x, y-0.75f, .45);
//		setPixel(pixels, width, height, x+0.75f, y-0.75f, .45);
//		setPixel(pixels, width, height, x+0.75f, y, .45);
//		setPixel(pixels, width, height, x, y+0.75f, .45);
//		setPixel(pixels, width, height, x+0.75f, y+0.75f, .45);
	}

	void drawLine(unsigned int *pixels, int width, int height, int x0, int y0, int x1, int y1) {
		float dx = x1 - x0;
		float dy = y1 - y0;
		float step = 0;
		if (abs(dx) >= abs(dy)) {
			step = abs(dx);
		} else {
			step = abs(dy);
		}
		dx /= step;
		dy /= step;

		float x = x0, y = y0;

		int i = 0;
		while (i <= step) {
			setPixelAA(pixels, width, height, x, y);

			x += dx;
			y += dy;
			i++;
		}
	}

	int ipart(float x) {
		return (int) floor(x);
	}

	float fpart(float x) {
		return x - floor(x);
	}

	float rfpart(float x) {
		return 1 - fpart(x);
	}

	void drawLineAA(unsigned int *pixels, int width, int height, float x0, float y0, float x1, float y1) {
		bool steep = abs(y1 - y0) > abs(x1 - x0);

		if (steep) {
			float temp = x0;
			x0 = y0;
			y0 = temp;
			temp = x1;
			x1 = y1;
			y1 = temp;
		}
		if (x0 > x1) {
			float temp = x0;
			x0 = x1;
			y1 = temp;
			temp = y0;
			y0 = y1;
			y1 = temp;
		}

		float dx = x1 - x0;
		float dy = y1 - y0;
		float gradient = (dx == 0.0f ? 1.0f : dy / dx);

		int xend = (int) round(x0);
		float yend = y0 + gradient * (xend - x0);
		float xgap = rfpart(x0 + 0.5f);
		int xpxl1 = xend;
		int ypxl1 = ipart(yend);
		if (steep) {
			setPixel(pixels, width, height, ypxl1, xpxl1, rfpart(yend) * xgap);
			setPixel(pixels, width, height, ypxl1 + 1, xpxl1, fpart(yend) * xgap);
		} else {
			setPixel(pixels, width, height, xpxl1, ypxl1, rfpart(yend) * xgap);
			setPixel(pixels, width, height, xpxl1, ypxl1 + 1, fpart(yend) * xgap);
		}
		float intery = yend + gradient;

		xend = (int) round(x1);
		yend = y1 + gradient * (xend - x1);
		xgap = rfpart(x1 + 0.5f);
		int xpxl2 = xend;
		int ypxl2 = ipart(yend);
		if (steep) {
			setPixel(pixels, width, height, ypxl2, xpxl2, rfpart(yend) * xgap);
			setPixel(pixels, width, height, ypxl2 + 1, xpxl2, fpart(yend) * xgap);
		} else {
			setPixel(pixels, width, height, xpxl2, ypxl2, rfpart(yend) * xgap);
			setPixel(pixels, width, height, xpxl2, ypxl2 + 1, fpart(yend) * xgap);
		}

		if (steep) {
			for (int x = xpxl1 + 1; x <= xpxl2 - 1; x++) {
				setPixel(pixels, width, height, ipart(intery), x, rfpart(intery));
				setPixel(pixels, width, height, ipart(intery) + 1, x, fpart(intery));
				intery += gradient;
			}
		} else {
			for (int x = xpxl1 + 1; x <= xpxl2 - 1; x++) {
				setPixel(pixels, width, height, x, ipart(intery), rfpart(intery));
				setPixel(pixels, width, height, x, ipart(intery) + 1, fpart(intery));
				intery += gradient;
			}
		}
	}

	void drawBezier(unsigned int *pixels, const int &width, const int &height, int x0, int y0, int xc, int yc, int x1, int y1) {
		int steps = 100;
		for (int it = 0; it <= steps; it++) {
			float t = (float) it / steps;
			float x = (1 - t) * (1 - t) * x0 + 2 * t * (1 - t) * xc + t * t * x1;
			float y = (1 - t) * (1 - t) * y0 + 2 * t * (1 - t) * yc + t * t * y1;
			setPixel(pixels, width, height, (int) x, (int) y);
		}
	}

	int intersectsBezier(float x0, float y0, float xc, float yc, float x1, float y1, float xl, float ym) {
		float a = x0 - 2 * xc + x1;
		float b = 2 * (xc - x0);
		float c = x0 - xl;

		float discriminant = b * b - 4 * a * c;
		if (discriminant < 0.0f || a == 0)
			return 0;

		float t0 = (-b + sqrt(discriminant)) / (2 * a);
		float yt0 = (1 - t0) * (1 - t0) * y0 + 2 * t0 * (1 - t0) * yc + t0 * t0 * y1;
		float t1 = (-b - sqrt(discriminant)) / (2 * a);
		float yt1 = (1 - t1) * (1 - t1) * y0 + 2 * t1 * (1 - t1) * yc + t1 * t1 * y1;

		int intersections = 0;
		if (t0 > 0.0f && t0 < 1.0f && (int) (yt0 + 0.5f) <= ym)
			intersections++;
		if (t1 > 0.0f && t1 < 1.0f && (int) (yt1 + 0.5f) <= ym)
			intersections++;

		return intersections;
	}

	int intersectsLine(float x0, float y0, float x1, float y1, float xl, float ym) {
		if (std::abs(x0 - x1) < 1e-4) {
			return 0;
		}

		float t = (xl - x0) / (x1 - x0);
		float yt = (1 - t) * y0 + t * y1;

		if (t > 0.0f && t < 1.0f && yt < ym) {
			return 1;
		} else {
			return 0;
		}
	}

	int edgeIntersect(float x0, float xc, float yc, float x1, float xl, float ym) {
		if (xc == xl && yc < ym && ((x0 <= xl && xl < x1) || (x1 < xl && xl <= x0)))
			return 1;
		return 0;
	}

	bool inGlyph(const Glyph &glyph, const float &x, const float &y) {
		bool inGlyph = false;
		for (int c = 0; c < glyph.endPoints.size(); c++) {
			int intersections = 0;
			int s = (c == 0 ? 0 : glyph.endPoints[c - 1] + 1);

			int cur = s;
			do {
				int next = (cur + 1 > glyph.endPoints[c] ? cur - glyph.endPoints[c] + s : cur + 1);
				int dnext = (cur + 2 > glyph.endPoints[c] ? cur + 1 - glyph.endPoints[c] + s : cur + 2);
				int tnext = (cur + 3 > glyph.endPoints[c] ? cur + 2 - glyph.endPoints[c] + s : cur + 3);
				if (glyph.onGlyph[cur] && glyph.onGlyph[next]) {
					intersections += intersectsLine(glyph.xCoords[cur], glyph.yCoords[cur], glyph.xCoords[next], glyph.yCoords[next], x, y);
					intersections += edgeIntersect(glyph.xCoords[cur], glyph.xCoords[next], glyph.yCoords[next], glyph.xCoords[dnext], x, y);
				} else if (glyph.onGlyph[cur] && !glyph.onGlyph[next] && glyph.onGlyph[dnext]) {
					intersections += intersectsBezier(glyph.xCoords[cur], glyph.yCoords[cur], glyph.xCoords[next], glyph.yCoords[next], glyph.xCoords[dnext], glyph.yCoords[dnext], x, y);
					intersections += edgeIntersect(glyph.xCoords[next], glyph.xCoords[dnext], glyph.yCoords[dnext], glyph.xCoords[tnext], x, y);
					cur++;
				} else if (glyph.onGlyph[cur] && !glyph.onGlyph[next] && !glyph.onGlyph[dnext]) {
					intersections += intersectsBezier(glyph.xCoords[cur], glyph.yCoords[cur], glyph.xCoords[next], glyph.yCoords[next], (glyph.xCoords[next] + glyph.xCoords[dnext]) / 2, (glyph.yCoords[next] + glyph.yCoords[dnext]) / 2, x, y);
					intersections += edgeIntersect(glyph.xCoords[next], (glyph.xCoords[next] + glyph.xCoords[dnext]) / 2, (glyph.yCoords[next] + glyph.yCoords[dnext]) / 2, glyph.xCoords[dnext], x, y);
				} else if (!glyph.onGlyph[cur] && !glyph.onGlyph[next] && !glyph.onGlyph[dnext]) {
					intersections += intersectsBezier((glyph.xCoords[cur] + glyph.xCoords[next]) / 2, (glyph.yCoords[cur] + glyph.yCoords[next]) / 2, glyph.xCoords[next], glyph.yCoords[next], (glyph.xCoords[next] + glyph.xCoords[dnext]) / 2, (glyph.yCoords[next] + glyph.yCoords[dnext]) / 2, x, y);
					intersections += edgeIntersect(glyph.xCoords[next], (glyph.xCoords[next] + glyph.xCoords[dnext]) / 2, (glyph.yCoords[next] + glyph.yCoords[dnext]) / 2, glyph.xCoords[dnext], x, y);
				} else if (!glyph.onGlyph[cur] && !glyph.onGlyph[next] && glyph.onGlyph[dnext]) {
					intersections += intersectsBezier((glyph.xCoords[cur] + glyph.xCoords[next]) / 2, (glyph.yCoords[cur] + glyph.yCoords[next]) / 2, glyph.xCoords[next], glyph.yCoords[next], glyph.xCoords[dnext], glyph.yCoords[dnext], x, y);
					intersections += edgeIntersect(glyph.xCoords[next], glyph.xCoords[dnext], glyph.yCoords[dnext], glyph.xCoords[tnext], x, y);
					cur++;
				} else {
					printf("Nothing matches (%d%c, %d%c, %d%c)\n", cur, (glyph.onGlyph[cur] ? 'n' : 'f'), next, (glyph.onGlyph[next] ? 'n' : 'f'), dnext, (glyph.onGlyph[dnext] ? 'n' : 'f'));
				}
			} while (++cur <= glyph.endPoints[c]);

			if (intersections % 2 == 1)
				inGlyph = !inGlyph;
		}
		return inGlyph;
	}

	unsigned int grayscale(const float &intensity) {
		unsigned int curInt = (unsigned int) (intensity * 0xFF);
		if (curInt > 0xFF)
			curInt = 0xFF;
		return (curInt << 24) | (curInt << 16) | (curInt << 8) | curInt;
	}

	struct Edge {
		float x0, y0, x1, y1;

		Edge(const float &x0, const float &y0, const float &x1, const float &y1)
				: x0(x0), y0(y0), x1(x1), y1(y1) {}
	};

	void render(unsigned int *pixels, const unsigned int &width, const unsigned int &height, const Glyph &glyph) {
//		for (int y = 0; y < height; y++) {
//			for (int x = 0; x < width; x++) {
//				int hits = 0;
//				int total_hits = 8;
//				float offsets[8] = {5, 0, 3, 6, 2, 3, 4, 7};
//				for (int p = 0; p < total_hits; p++) {
//					if (inGlyph(glyph, x + offsets[p] / total_hits, y + p / total_hits))
//						hits++;
//				}
//				pixels[x + y * width] = grayscale(hits / 4.0f) | 0x00FFFFFF;
//			}
//		}

		const int edgeCount = glyph.xCoords.size();
		std::vector<Edge> sortedEdges;
		sortedEdges.reserve(edgeCount);
		std::vector<unsigned int> used(edgeCount, 0); // 0 - unused, 1 - used in sorting, 2 - out of bounds of scanline

		for (int c = 0; c < glyph.endPoints.size(); c++) {
			int s = (c == 0 ? 0 : glyph.endPoints[c - 1] + 1);
			for (unsigned int i = 0; i < edgeCount; i++) {
				unsigned int biggestYMax = 0;
				unsigned int biggestIndex = 0;
				float x0, y0, x1, y1;
				for (unsigned int e = 0; e < edgeCount; e++) {
					if (used[e] == 1)
						continue;

					int cur = s + e;
					int next = (cur + 1 > glyph.endPoints[c] ? cur - glyph.endPoints[c] + s : cur + 1);
					unsigned int yMax = std::max(glyph.yCoords[cur], glyph.yCoords[next]);
					if (yMax > biggestYMax) {
						biggestYMax = yMax;
						biggestIndex = cur;
						x0 = glyph.xCoords[cur];
						y0 = glyph.yCoords[cur];
						x1 = glyph.xCoords[next];
						y1 = glyph.yCoords[next];
					}
				}
				used[biggestIndex] = 1;
				sortedEdges.emplace_back(x0, y0, x1, y1);
			}
		}

		for (int y = height - 1; y >= 0; y--) {
			int A[width];
			int X[width];
			for(int k = 0; k < width; k++) {
				X[k] = 0;
			}
			for (int i = 0; i < edgeCount; i++) {
				Edge &e = sortedEdges[i];
				if (std::max(e.y0, e.y1) <= y)
					break;
				if (std::min(e.y0, e.y1) >= (y + 1))
					continue;

//				std::cout << "\t" << y << std::endl;
//				std::cout << "(" << e.x0 << ", " << e.y0 << ") -> (" << e.x1 << ", " << e.y1 << ")" << std::endl;
				if(e.y0 == e.y1)
					continue;
				// y = y0*(1-t) + t * y1
				// y = y0 + t * (y1 - y0)
				float tu = ((y+1) - e.y0) / (e.y1 - e.y0);
				if(tu < 0.0f)
					tu = 0.0f;
				if(tu > 1.0f)
					tu = 1.0f;
				float tl = (y - e.y0) / (e.y1 - e.y0);
				if(tl < 0.0f)
					tl = 0.0f;
				if(tl > 1.0f)
					tl = 1.0f;

				float xu = e.x0*(1-tu) + tu * e.x1;
				float xl = e.x0*(1-tl) + tl * e.x1;
				int xMin = (int) std::min(xu, xl);
				int xMax = (int) std::max(xu, xl);

				if(e.y0 <= e.y1) {
					X[xMin] += 1;
				} else {
					X[xMax] -= 1;
				}
			}
			int S = 0;
			for(int x = 0; x < width; x++) {
				S += X[x];
				if(S > 0)
//					pixels[x + y * width] = grayscale(S / 10);
					pixels[x + y * width] = 0xFFFFFFFF;
				else
					pixels[x + y * width] = 0xFF000000;
			}
		}
	}

	void renderOutline(unsigned int *pixels, const unsigned int &width, const unsigned int &height, const Glyph &glyph) {
		for (int c = 0; c < glyph.endPoints.size(); c++) {
			int s = (c == 0 ? 0 : glyph.endPoints[c - 1] + 1);

			int cur = s;
			do {
				int next = (cur + 1 > glyph.endPoints[c] ? cur - glyph.endPoints[c] + s : cur + 1);
				int dnext = (cur + 2 > glyph.endPoints[c] ? cur + 1 - glyph.endPoints[c] + s : cur + 2);
				if (glyph.onGlyph[cur] && glyph.onGlyph[next]) {
					drawLine(pixels, width, height, (int) glyph.xCoords[cur], (int) glyph.yCoords[cur], (int) glyph.xCoords[next], (int) glyph.yCoords[next]);
				} else if (glyph.onGlyph[cur] && !glyph.onGlyph[next] && glyph.onGlyph[dnext]) {
					drawBezier(pixels, width, height, (int) glyph.xCoords[cur], (int) glyph.yCoords[cur], (int) glyph.xCoords[next], (int) glyph.yCoords[next], (int) glyph.xCoords[dnext], (int) glyph.yCoords[dnext]);
					cur++;
				} else if (glyph.onGlyph[cur] && !glyph.onGlyph[next] && !glyph.onGlyph[dnext]) {
					drawBezier(pixels, width, height, (int) glyph.xCoords[cur], (int) glyph.yCoords[cur], (int) glyph.xCoords[next], (int) glyph.yCoords[next], (int) (glyph.xCoords[next] + glyph.xCoords[dnext]) / 2, (int) (glyph.yCoords[next] + glyph.yCoords[dnext]) / 2);
				} else if (!glyph.onGlyph[cur] && !glyph.onGlyph[next] && !glyph.onGlyph[dnext]) {
					drawBezier(pixels, width, height, (int) (glyph.xCoords[cur] + glyph.xCoords[next]) / 2, (int) (glyph.yCoords[cur] + glyph.yCoords[next]) / 2, (int) glyph.xCoords[next], (int) glyph.yCoords[next], (int) (glyph.xCoords[next] + glyph.xCoords[dnext]) / 2, (int) (glyph.yCoords[next] + glyph.yCoords[dnext]) / 2);
				} else if (!glyph.onGlyph[cur] && !glyph.onGlyph[next] && glyph.onGlyph[dnext]) {
					drawBezier(pixels, width, height, (int) (glyph.xCoords[cur] + glyph.xCoords[next]) / 2, (int) (glyph.yCoords[cur] + glyph.yCoords[next]) / 2, (int) glyph.xCoords[next], (int) glyph.yCoords[next], (int) glyph.xCoords[dnext], (int) glyph.yCoords[dnext]);
					cur++;
				} else {
					printf("Nothing matches (%d%c, %d%c, %d%c)\n", cur, (glyph.onGlyph[cur] ? 'n' : 'f'), next, (glyph.onGlyph[next] ? 'n' : 'f'), dnext, (glyph.onGlyph[dnext] ? 'n' : 'f'));
				}
			} while (++cur <= glyph.endPoints[c]);
		}
	}

	Font::Font(const std::string &path, TextureAtlas &atlas)
			: atlas(&atlas) {
		std::vector<Table> tables;
		unsigned char *fileData;
		{
			std::ifstream stream(path, std::ifstream::in | std::ifstream::ate | std::ifstream::binary);
			auto size = (unsigned int) stream.tellg();
			if (!stream.good()) {
				std::cerr << "Couldn't load file \'" << path << "\'" << std::endl;
				return;
			}
			stream.seekg(0, std::ifstream::beg);

			fileData = new unsigned char[size];
			unsigned int position = 0;
			char in;
			while (stream.get(in))
				fileData[position++] = (unsigned char) in;

			stream.close();

//			hexdump(fileData, 0, 320);

			parseData(tables, fileData);
		}

//		NAMEtable head = parseNAMEtable(tables[index]);

		int index = -1;
		while (tables[++index].tag != tagToUINT32("head"));
		head = parseHEADtable(tables[index]);
		index = -1;
		while (tables[++index].tag != tagToUINT32("maxp"));
		MAXPtable maxp = parseMAXPtable(tables[index]);
		index = -1;
		while (tables[++index].tag != tagToUINT32("loca"));
		loca = parseLOCAtable(tables[index], head, maxp);

		index = -1;
		while (tables[++index].tag != tagToUINT32("glyf"));
		glyf = new GLYFtable(tables[index], maxp);

		index = -1;
		while (tables[++index].tag != tagToUINT32("cmap"));
		cmap = parseCMAPtable(tables[index]);

		index = -1;
		while (tables[++index].tag != tagToUINT32("hhea"));
		HHEAtable hhea = parseHHEAtable(tables[index]);

		index = -1;
		while (tables[++index].tag != tagToUINT32("hmtx"));
		hmtx = parseHMTXtable(tables[index], hhea, maxp);

//		index = -1;
//		while (tables[++index].tag != tagToUINT32("vhea"));
//		VHEAtable vhea = parseVHEAtable(tables[index]);

//		index = -1;
//		while (tables[++index].tag != tagToUINT32("vmtx"));
//		vmtx = parseVMTXtable(tables[index], vhea, maxp);

		index = -1;
		while (tables[++index].tag != tagToUINT32("glyf"));
		const Table &table = tables[index];
//		hexdump(table.table, table.length);
	}

	Font::~Font() {
		delete glyf;
	}

	void Font::init(const unsigned int &pointSize) {
		this->pointSize = pointSize;

		std::string s = "A";
		std::cout << s << std::endl;
		for (const auto &c : s) {
			if (c >= MAX_GLYPHS)
				continue;

			std::cout << c << std::endl;

			Glyph &glyph = glyf->glyphs[cmap.glyphIndices[c]];
			if (!glyph.initialized)
				parseGLYFtable(*glyf, loca, cmap.glyphIndices[c]);

			float pixelSize = pointSize * 300.0f / 72.0f / head.unitsPerEm;

			unsigned int width = (unsigned int) (glyph.xMax * pixelSize * 2);
			unsigned int height = (unsigned int) (glyph.yMax * pixelSize * 2);
			unsigned int pixels[width * height];
			renderBitmap(pixels, width, height, c);
			Image *image = new Image(pixels, width, height, VIVID_IMAGE_FORMAT_RGBA);
			textures[c] = atlas->registerTexture(*image);
		}
	}

	TextureHandle &Font::getTexture(const unsigned char &character) const {
		if (character < 0 || character >= 128 || textures[character] == nullptr)
			return *(textures['X']);
		return *(textures[character]);
	}

	void Font::renderBitmap(unsigned int *pixels, const unsigned int &width, const unsigned int &height, const unsigned char &character) {
		Glyph &glyph = glyf->glyphs[cmap.glyphIndices[character]];
		for (int c = 0; c < glyph.xCoords.size(); c++) {
			glyph.xCoords[c] = ((float) glyph.xCoords[c] * (height - 1));
			glyph.yCoords[c] = height - 1 - ((float) glyph.yCoords[c] * (height - 1));
		}
		render(pixels, width, height, glyph);
	}

	void Font::renderBitmapOutline(unsigned int *pixels, const unsigned int &width, const unsigned int &height, const unsigned char &character) {
		Glyph &glyph = glyf->glyphs[cmap.glyphIndices[character]];
		if (!glyph.initialized)
			parseGLYFtable(*glyf, loca, cmap.glyphIndices[character]);

		for (int c = 0; c < glyph.xCoords.size(); c++) {
			glyph.xCoords[c] = (int) ((float) glyph.xCoords[c] * (width - 1));
			glyph.yCoords[c] = height - 1 - (int) ((float) glyph.yCoords[c] * (width - 1));
		}
		renderOutline(pixels, width, height, glyph);
	}

	float Font::getAdvanceHeight(const unsigned char &character) const {
//		return (float) vmtx.advanceHeight[cmap.glyphIndices[character]] / head.unitsPerEm;
		return 0;
	}

	float Font::getTopSideBearing(const unsigned char &character) const {
		return glyf->glyphs[cmap.glyphIndices[character]].yMin / head.unitsPerEm;
	}

	float Font::getWidth(const unsigned char &character) const {
		return (float) glyf->glyphs[cmap.glyphIndices[character]].xMax / head.unitsPerEm;
	}

	float Font::getHeight(const unsigned char &character) const {
		return (float) glyf->glyphs[cmap.glyphIndices[character]].yMax / head.unitsPerEm;
	}

	float Font::getAdvanceWidth(const unsigned char &character) const {
//		float pixelSize = size * pointSize * 300.0f / 72.0f / head.unitsPerEm;
		return (float) hmtx.advanceWidth[cmap.glyphIndices[character]] / head.unitsPerEm;
	}

	float Font::getLeftSideBearing(const unsigned char &character) const {
//		float pixelSize = size * pointSize * 300.0f / 72.0f / head.unitsPerEm;
		return (float) hmtx.leftSideBearing[cmap.glyphIndices[character]] / head.unitsPerEm;
	}

	float Font::getWidth(const std::string &s) const {
		float width = 0.0f;
		for (int c = 0; c < s.size(); c++) {
			if (c == s.size() - 1) {
				width += getWidth(s[c]);
			} else {
				width += getAdvanceWidth(s[c]);
			}
		}
		return width;
	}

}}
