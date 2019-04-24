//
// Created by Ole on 07.09.2017.
//

#pragma once

#include <vivid/util/maths.h>
#include <vivid/graphics/quad.h>
#include <vivid/scenegraph/gameobject.h>

namespace vivid {

	class Sprite : public GameObject {
	private:
		graphics::Quad quad;
	public:
		Sprite(float x, float y, float width, float height);

		inline const graphics::Quad &getQuad() const { return quad; }
	public:
		void render(const graphics::Renderer2D *renderer) override;
	};

}