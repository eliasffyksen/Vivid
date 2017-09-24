//
// Created by Ole on 09.09.2017.
//

#include "texture.h"


namespace vivid { namespace graphics {
	
	Texture::Texture(const std::string& path)
	: path(path)
	{
		init();
	}
	
	void Texture::init() {
	
	}
	
	Texture::~Texture() {
		glDeleteTextures(1, &textureID);
	}
	
	void Texture::bind() const {
	
	}
	
	const unsigned int& Texture::getWidth() const {
	
	}
	
	const unsigned int& Texture::getHeight() const {
	
	}
	
	
}}
