//
// Created by Ole on 07.09.2017.
//

#include "indexbuffer.h"

namespace vivid { namespace graphics {
	
	IndexBuffer::IndexBuffer(GLuint* data, GLuint count)
			: count(count) {
		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	
	IndexBuffer::~IndexBuffer() {
		glDeleteBuffers(1, &bufferID);
	}
	
	void IndexBuffer::bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	}
	
	void IndexBuffer::unbind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	
}}
