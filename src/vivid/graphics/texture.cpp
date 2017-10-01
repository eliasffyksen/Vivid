//
// Created by Ole on 09.09.2017.
//

#include "texture.h"
#include "VividImage/image.h"

namespace vivid { namespace graphics {
	
	Texture::Texture(const std::string& path)
			: path(path) {
		init();
	}
	
	void Texture::init() {
		Image image(path);
		width = image.getWidth();
		height = image.getHeight();
		
		unsigned char pixels[] = {
				255, 0, 255
		};
		
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, (void*) pixels);//image.getPixels());
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	
	Texture::~Texture() {
		glDeleteTextures(1, &textureID);
	}
	
	void Texture::bind(const unsigned int& index) const {
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureID);
	}
	
	void Texture::unbind() const {
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	
}}
