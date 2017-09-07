//
// Created by Ole on 07.09.2017.
//

#include "sprite.h"


namespace vivid { namespace graphics {
	
	Sprite::Sprite(float x, float y, float width, float height, const glm::vec4& color)
			: Renderable2D(x, y, width, height, color) {}
	
}}