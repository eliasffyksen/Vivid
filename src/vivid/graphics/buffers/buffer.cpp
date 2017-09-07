//
// Created by Ole on 07.09.2017.
//

#include "buffer.h"

namespace vivid { namespace graphics {

	Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
	: componentCount(componentCount) {
		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
	Buffer::~Buffer() {
		glDeleteBuffers(1, &bufferID);
	}
	
	void Buffer::bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	}
	
	void Buffer::unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}}