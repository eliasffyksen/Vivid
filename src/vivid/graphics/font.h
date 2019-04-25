//
// Created by stroh on 29/12/2018.
//

#pragma once

#include <string>
#include <vector>
#include <vivid/graphics/texture.h>
#include <vivid/scenegraph/textureatlas.h>

namespace vivid { namespace graphics {

	struct Table {
		unsigned int tag;
		unsigned int checkSum;
		unsigned int offset;
		unsigned int length;
		const unsigned char *table;

		Table(unsigned int tag, unsigned int checkSum, unsigned int offset, unsigned int length, const unsigned char *table)
				: tag(tag), checkSum(checkSum), offset(offset), length(length), table(table) {}
	};

	struct HEADtable {
		float version;
		float fontRevision;
		unsigned int checkSumAdjustment;
		unsigned int magicNumber;
		unsigned int flags;
		unsigned int unitsPerEm;
		unsigned long long int created;
		unsigned long long int modified;
		int xMin;
		int xMax;
		int yMin;
		int yMax;
		unsigned int macStyle;
		unsigned int lowestRecPPEM;
		int fontDirectionHint;
		int indexToLocFormat;
		int glpyhDataFormat;
	};

	struct MAXPtable {
		float version;
		unsigned int numGlyphs;
		unsigned int maxPoints;
		unsigned int maxContours;
		unsigned int maxComponentPoints;
		unsigned int maxComponentContours;
		unsigned int maxZones;
		unsigned int maxTwilightPoints;
		unsigned int maxStorage;
		unsigned int maxFunctionDefs;
		unsigned int maxInstructionDefs;
		unsigned int maxStackElements;
		unsigned int maxSizeOfInstructions;
		unsigned int maxComponentElements;
		unsigned int maxComponentDepth;
	};

	struct HHEAtable {
		float version;
		int ascent;
		int descent;
		int lineGap;
		unsigned int advanceWidthMax;
		int minLeftSideBearing;
		int minRightSideBearing;
		int xMaxExtent;
		int caretSlopeRise;
		int caretSlopeRun;
		int caretOffset;
		int metricDataFormat;
		unsigned int numOfLongHorMetrics;
	};

	struct HMTXtable {
		std::vector<unsigned int> advanceWidth;
		std::vector<int> leftSideBearing;
	};

	struct LOCAtable {
		std::vector<unsigned int> offsets;

		inline unsigned int getLength(const unsigned int &index) { return offsets[index + 1] - offsets[index]; }
	};

	struct NameRecord {
		unsigned int platformID;
		unsigned int platformSpecificID;
		unsigned int languageID;
		unsigned int nameID;
		std::string literal;
	};

	struct NAMEtable {
		std::vector<NameRecord> strings;
	};

	struct CMAPtable {
		unsigned int glyphIndices[0xFF + 1] = {0};

//		CMAPtable() {
//			for(int i = 0; i < sizeof(glyphIndices) / sizeof(unsigned int); i++) {
//				glyphIndices[i] = 0;
//			}
//		}
	};

	struct Glyph {
		bool initialized = false;
		bool normalized = false;
		float xMin;
		float xMax;
		float yMin;
		float yMax;
		std::vector<unsigned int> endPoints;
		std::vector<float> xCoords;
		std::vector<float> yCoords;
		std::vector<bool> onGlyph;
	};

	struct GLYFtable {
		Table table;
		std::vector<Glyph> glyphs;

		GLYFtable(Table table, const MAXPtable &maxp)
				: table(table) {
			glyphs.resize(maxp.numGlyphs);
		}
	};

	class Font {
	public:
		explicit Font(const std::string &path, TextureAtlas &atlas);
		~Font();

		void init(const unsigned int &pointSize);

		TextureHandle &getTexture(const unsigned char &character);

		void renderBitmap(unsigned int *pixels, unsigned int &width, unsigned int &height, const unsigned char &character);
		void renderBitmapOutline(unsigned int *pixels, const unsigned int &width, const unsigned int &height, const unsigned char &character);
	private:
		float getAdvance(const unsigned char &character, const float &size);
		float getLeftSideBearing(const unsigned char &character, const float &size);
	private:
		unsigned int pointSize;

		TextureAtlas *atlas;
		TextureHandle *textures[128];

		HEADtable head;
		LOCAtable loca;
		CMAPtable cmap;
		GLYFtable *glyf;
		HHEAtable hhea;
		HMTXtable hmtx;
	};

}}
