//
// Created by Ole on 07.09.2017.
//

#include "sprite.h"

namespace vivid {

	Sprite::Sprite(float x, float y, float width, float height, TextureHandle* handle)
			: quad(x, y, width, height, handle) {}

	void Sprite::render(const graphics::Renderer2D *renderer) {
		renderer->submit(&quad);
	}

}