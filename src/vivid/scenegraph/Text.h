//
// Created by stroh on 28/04/2019.
//

#pragma once

#include <string>
#include <vivid/scenegraph/gameobject.h>
#include <vivid/graphics/font.h>

namespace vivid {

	class Text : public GameObject {
	public:
		Text(const graphics::Font &font, std::string s);

		void render(const vivid::graphics::Renderer2D *renderer) override;

		void setText(std::string text);
		void setFont(const graphics::Font &font);
	private:
		const graphics::Font * font;
		std::string text;
	};

}