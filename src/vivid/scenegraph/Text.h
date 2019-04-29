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
		Text(const graphics::Font &font, const std::string &s);
	};

}