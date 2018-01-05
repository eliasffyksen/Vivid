//
// Created by Ole on 07.09.2017.
//

#pragma once

#include "glm/glm.hpp"
#include "../graphics/renderable2D.h"
#include "gameobject.h"

namespace vivid { namespace graphics {
	
	class Sprite : public GameObject {
	private:
		Renderable2D renderable;
	public:
		Sprite(float x, float y, float width, float height, const glm::vec4& color);
	private:
		void render(const Renderer2D* renderer) override;
	};
	
}}