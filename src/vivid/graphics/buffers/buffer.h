//
// Created by Ole on 07.09.2017.
//

#pragma once

#include "GL/glew.h"

namespace vivid { namespace graphics {
	
	class Buffer {
	private:
		GLuint bufferID;
		GLuint componentCount;
	public:
		Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
		~Buffer();
		
		void bind() const;
		void unbind() const;
		
		inline GLuint getComponentCount() const { return componentCount; }
	};
	
}}
