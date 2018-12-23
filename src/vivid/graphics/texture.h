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
		Texture(const std::string &path);
		~Texture();

		void bind(const unsigned int &index) const;
		void unbind() const;

		inline const unsigned int &getWidth() const { return width; }
		inline const unsigned int &getHeight() const { return height; }
	private:
		void init();
	};

}}


