//
// Created by stroh on 29/12/2018.
//

#pragma once

#include <string>
#include <vector>
#include <vivid/graphics/texture.h>

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
		int xMin;
		int xMax;
		int yMin;
		int yMax;
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
		explicit Font(const std::string &path);
		~Font();

		void init();

		Texture &getTexture(const unsigned char &character);

		void renderBitmap(unsigned int *pixels, const unsigned int &width, const unsigned int &height, const unsigned char &character);
		void renderBitmapOutline(unsigned int *pixels, const unsigned int &width, const unsigned int &height, const unsigned char &character);
	private:
		Texture *textures[128];

		LOCAtable loca;
		CMAPtable cmap;
		GLYFtable *glyf;
	};

}}
