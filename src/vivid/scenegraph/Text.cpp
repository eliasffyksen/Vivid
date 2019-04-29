//
// Created by stroh on 28/04/2019.
//

#include "Text.h"
#include "sprite.h"

namespace vivid {

	Text::Text(const graphics::Font &font, const std::string &s) {
		float x = 0.0f;
		for (auto &c : s) {
			float width = font.getWidth(c);
			float height = font.getHeight(c);
			Sprite *characterSprite = new Sprite(x + font.getLeftSideBearing(c), font.getTopSideBearing(c), width, height, &font.getTexture(c));
			addChild(*characterSprite);
			x += font.getAdvanceWidth(c);

//			std::cout << "'" << c << "': " << width << ", " << height << "" << std::endl;
//			std::cout << "Advance: " << font.getAdvanceWidth(c) << std::endl;
//			std::cout << "Horizontal Bearing: " << font.getLeftSideBearing(c) << std::endl;
//			std::cout << "Vertical Bearing: " << font.getTopSideBearing(c) << std::endl;
		}
	}

}