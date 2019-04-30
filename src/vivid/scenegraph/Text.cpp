#include <utility>

//
// Created by stroh on 28/04/2019.
//

#include "Text.h"
#include <vivid/graphics/quad.h>

namespace vivid {

	Text::Text(const graphics::Font &font, std::string s)
			: font(&font), text(std::move(s)) {}

	void Text::render(const vivid::graphics::Renderer2D *renderer) {
		float x = 0.0f;
		for (auto &c : text) {
			graphics::Quad character(x + font->getLeftSideBearing(c), font->getTopSideBearing(c), font->getWidth(c), font->getHeight(c), &font->getTexture(c));
			renderer->submit(&character);
			x += font->getAdvanceWidth(c);
		}
	}

	void Text::setText(std::string text) {
		this->text = std::move(text);
	}

	void Text::setFont(const graphics::Font &font) {
		this->font = &font;
	}

}