//
// Created by Ole on 07.09.2017.
//

#pragma once

#include "glm/glm.hpp"
#include "renderable2D.h"

namespace vivid { namespace graphics {
	
	class Sprite : public Renderable2D {
	public:
		Sprite(float x, float y, float width, float height, const glm::vec4& color);
	};
	
}}