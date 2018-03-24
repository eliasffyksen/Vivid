//
// Created by Ole on 07.09.2017.
//

#pragma once

#include "GL/glew.h"

namespace vivid { namespace graphics {
	
	class IndexBuffer {
	private:
		GLuint bufferID;
		GLuint count;
	public:
		IndexBuffer(GLuint* data, GLuint count);
		~IndexBuffer();
		
		void bind() const;
		void unbind() const;
		
		inline GLuint getCount() const { return count; }
	};
	
}}
