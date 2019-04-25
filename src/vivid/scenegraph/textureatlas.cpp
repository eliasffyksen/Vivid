//
// Created by stroh on 24/04/2019.
//

#include <tuple>
#include "textureatlas.h"


namespace vivid {

	bool overlaps(unsigned int x0, unsigned int y0, unsigned int w0, unsigned int h0, unsigned int x1, unsigned int y1, unsigned int w1, unsigned int h1) {
		return (x0 + w0 <= x1) || (x1 + w1 <= x0) || (y0 + h0 <= y1) || (y1 + h1 <= y0);
	}

	unsigned int clamp(unsigned int value, unsigned int low, unsigned int high) {
		if (value <= low)
			return low;
		if (value >= high)
			return high;
		return value;
	}

	ImagePosition::ImagePosition(unsigned long long id, unsigned int x, unsigned int y)
			: id(id), x(x), y(y) {}

	TextureHandle::TextureHandle(unsigned long long id)
			: id(id), uvMin(0, 0), uvMax(0, 0) {}

	TextureAtlas::TextureAtlas(const unsigned int &border)
	: border(border), invalidated(false) {}

	TextureAtlas::~TextureAtlas() {
		if (atlasTexture != nullptr)
			delete atlasTexture;
	}

	void TextureAtlas::update() {
		if(!invalidated)
			return;

		invalidated = false;
		std::vector<unsigned int> sortedImages;
		sortedImages.reserve(textures.size());
		std::vector<bool> used(textures.size(), false);

		for (unsigned int p = 0; p < textures.size(); p++) {
			unsigned int biggestSize = 0;
			unsigned int biggestIndex = 0;
			for (unsigned int t = 0; t < textures.size(); t++) {
				if (used[t])
					continue;

				unsigned int size = 1 + textures[t].first->getWidth() * textures[t].first->getHeight();
				if (size > biggestSize) {
					biggestSize = size;
					biggestIndex = t;
				}
			}
			used[biggestIndex] = true;
			sortedImages.push_back(biggestIndex);
		}

//		for (int i = 0; i < sortedImages.size(); i++) {
//			std::cout << i << ": " << sortedImages[i] << " has " << textures[sortedImages[i]].first->getWidth() * textures[sortedImages[i]].first->getWidth() << std::endl;
//		}

		unsigned int sizeIncrement = 128;
		unsigned int atlasSize = sizeIncrement;

		std::vector<ImagePosition> positions;

		for (int t = 0; t < sortedImages.size(); t++) {
			bool couldPlace = false;
			unsigned int xp = 0;
			unsigned int yp = 0;

			for (unsigned int y = 0; (y + textures[sortedImages[t]].first->getHeight() + 2 * border <= atlasSize) && !couldPlace; y++) {
				unsigned int ym = UINT32_MAX;
				for (unsigned int x = 0; (x + textures[sortedImages[t]].first->getWidth() + 2 * border <= atlasSize) && !couldPlace; x++) {
					bool valid = true;
					for (unsigned int p = 0; (p < t) && valid; p++) {
						if (!overlaps(x, y, textures[sortedImages[t]].first->getWidth() + 2 * border, textures[sortedImages[t]].first->getHeight() + 2 * border, positions[p].x, positions[p].y, textures[positions[p].id].first->getWidth() + 2 * border, textures[positions[p].id].first->getHeight() + 2 * border)) {
							valid = false;
							x = positions[p].x + textures[positions[p].id].first->getWidth() + 2 * border - 1;
							unsigned int yextent = positions[p].y + textures[positions[p].id].first->getHeight() + 2 * border;
							if (ym > yextent)
								ym = yextent;
						}
					}
					if (valid) {
						couldPlace = true;
						xp = x;
						yp = y;
					}
				}
				y = ym - 1;
			}

			if (!couldPlace) {
				atlasSize += sizeIncrement;
				t--;
			} else {
				positions.emplace_back(sortedImages[t], xp, yp);
			}
		}
//		std::cout << std::endl;
//		std::cout << "Final size of atlas: " << atlasSize << "x" << atlasSize << std::endl;
//		for (int i = 0; i < positions.size(); i++) {
//			std::cout << positions[i].id << " (" << textures[positions[i].id].first->getWidth() << "x" << textures[positions[i].id].first->getHeight() << ") is placed at (" << positions[i].x << ", " << positions[i].y << ")" << std::endl;
//		}

		unsigned int pixels[atlasSize * atlasSize];
		for (int i = 0; i < atlasSize * atlasSize; i++) {
			pixels[i] = 0xFF000000;
		}

		for (int t = 0; t < positions.size(); t++) {
			textures[positions[t].id].second->uvMin.u = (float) (positions[t].x + border) / atlasSize;
			textures[positions[t].id].second->uvMin.v = (float) (positions[t].y + border) / atlasSize;
			textures[positions[t].id].second->uvMax.u = (float) (positions[t].x + border + textures[positions[t].id].first->getWidth()) / atlasSize;
			textures[positions[t].id].second->uvMax.v = (float) (positions[t].y + border + textures[positions[t].id].first->getHeight()) / atlasSize;
			for (unsigned int y = 0; y < textures[positions[t].id].first->getHeight() + 2 * border; y++) {
				for (unsigned int x = 0; x < textures[positions[t].id].first->getWidth() + 2 * border; x++) {
					int ax = clamp(x, border, textures[positions[t].id].first->getWidth() + border - 1) - border;
					int ay = clamp(y, border, textures[positions[t].id].first->getHeight() + border - 1) - border;
					pixels[(positions[t].x + x) + (positions[t].y + y) * atlasSize] = textures[positions[t].id].first->getPixel(ax, ay).color();
				}
			}
		}

//		for (int t = 0; t < textures.size(); t++) {
//			std::cout << t << ": " << textures[t].second->uvMin << " -> " << textures[t].second->uvMax << std::endl;
//		}

		Image image(pixels, atlasSize, atlasSize, VIVID_IMAGE_FORMAT_RGBA);
		atlasTexture = new graphics::Texture(image);
	}

	void TextureAtlas::bind(const unsigned int &index) const {
		atlasTexture->bind(index);
	}

	void TextureAtlas::unbind() const {
		atlasTexture->unbind();
	}

	TextureHandle *TextureAtlas::registerTexture(Image &image) {
		if(image.getWidth() == 0 || image.getHeight() == 0)
			return nullptr;

		invalidated = true;
		TextureHandle *handle = new TextureHandle(textures.size());
		textures.emplace_back(&image, handle);
		return handle;
	}

	void TextureAtlas::remove(TextureHandle *handle) {
		auto pair = textures[textures.size() - 1];
		pair.second->id = handle->id;
		textures[handle->id] = pair;
		delete textures.back().second;
		textures.pop_back();
	}

}