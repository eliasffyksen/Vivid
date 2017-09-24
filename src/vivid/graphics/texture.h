//
// Created by Ole on 09.09.2017.
//

#pragma once

#include <string>
#include <GL/glew.h>

namespace vivid { namespace graphics {
	
	class Texture {
	private:
		const std::string path;
		GLuint textureID;
		unsigned int width, height;
	public:
		Texture(const std::string& path);
		~Texture();
		
		void bind() const;
		const unsigned int& getWidth() const;
		const unsigned int& getHeight() const;
	private:
		void init();
	};
	
}}


