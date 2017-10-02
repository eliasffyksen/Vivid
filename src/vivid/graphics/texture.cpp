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
				255, 0, 255, 100
		};
		unsigned char* pp = (unsigned char*) image.getPixels();
		LOG((unsigned int) pp[0] << " " << (unsigned int) image.getPixels()[0].red);
		LOG((unsigned int) pp[1] << " " << (unsigned int) image.getPixels()[0].green);
		LOG((unsigned int) pp[2] << " " << (unsigned int) image.getPixels()[0].blue);
		LOG((unsigned int) pp[3] << " " << (unsigned int) image.getPixels()[0].alpha);
		std::printf("%08X\n", image.getPixels()[0].color());
		
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, (const void*) pixels);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (const void*) image.getPixels());
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		
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
