//
// Created by Ole on 07.09.2017.
//

#include "vertexarray.h"


namespace vivid { namespace graphics {
	
	VertexArray::VertexArray() {
		glGenVertexArrays(1, &arrayID);
	}
	
	VertexArray::~VertexArray() {
		for(int i = 0; i < buffers.size(); i++)
			delete buffers[i];
	}
	
	void VertexArray::addBuffer(Buffer* buffer, GLuint index) {
		bind();
		buffer->bind();
		
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
		
		buffer->unbind();
		unbind();
		
		buffers.push_back(buffer);
	}
	
	void VertexArray::bind() const {
		glBindVertexArray(arrayID);
	}
	
	void VertexArray::unbind() const {
		glBindVertexArray(0);
	}
	
}}
