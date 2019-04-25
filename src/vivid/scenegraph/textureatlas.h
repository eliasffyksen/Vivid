//
// Created by stroh on 24/04/2019.
//

#pragma once

#include <VividImage/image.h>
#include <vivid/util/maths.h>
#include "vivid/graphics/texture.h"

namespace vivid {

	struct ImagePosition {
		ImagePosition(unsigned long long id, unsigned int x, unsigned int y);

		unsigned long long id;
		unsigned int x;
		unsigned int y;
	};

	struct TextureHandle {
		TextureHandle(unsigned long long id);

		unsigned long long id;
		vdm::vec2 uvMin;
		vdm::vec2 uvMax;
	};

	class TextureAtlas {
	public:
		TextureAtlas(const unsigned int &border = 1);
		~TextureAtlas();

		void update();

		void bind(const unsigned int &index) const;
		void unbind() const;

		TextureHandle* registerTexture(Image &image);
		void remove(TextureHandle *handle);
	private:
		unsigned int border;
		bool invalidated;

		std::vector<std::pair<Image*, TextureHandle*>> textures;
		graphics::Texture* atlasTexture;
	};

}
