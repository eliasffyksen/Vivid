//
// Created by Ole on 07.09.2017.
//

#pragma once

#include "glm/glm.hpp"
#include "vivid/graphics/quad.h"
#include "gameobject.h"

namespace vivid {

	class Sprite : public GameObject {
	private:
		graphics::Quad quad;
	public:
		Sprite(float x, float y, float width, float height, const glm::vec4 &color);

		inline const graphics::Quad &getQuad() const { return quad; }

	public:
		void render(const graphics::Renderer2D *renderer) override;
	};

}