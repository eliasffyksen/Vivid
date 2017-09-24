//
// Created by Ole on 07.09.2017.
//

#include "batchrenderer2D.h"

#include <cstddef>

namespace vivid { namespace graphics {
	
	BatchRenderer2D::BatchRenderer2D() {
		init();
	}
	
	BatchRenderer2D::~BatchRenderer2D() {
		delete ibo;
		glDeleteBuffers(1, &vbo);
	}
	
	void BatchRenderer2D::init() {
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, BATCH_RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
		
		glEnableVertexAttribArray(SHADER_POSITION_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);
		glVertexAttribPointer(SHADER_POSITION_INDEX, 3, GL_FLOAT, GL_FALSE, BATCH_RENDERER_VERTEX_SIZE, (const GLvoid*) 0);
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, BATCH_RENDERER_VERTEX_SIZE, (const GLvoid*) (offsetof(Vertex, Vertex::color)));
		
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		
		GLuint indices[BATCH_RENDERER_INDICES_SIZE];
		unsigned int offset = 0;
		for (int i = 0; i < BATCH_RENDERER_INDICES_SIZE; i += 6) {
			indices[i + 0] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;
			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;
			
			offset += 4;
		}
		
		ibo = new IndexBuffer(indices, BATCH_RENDERER_INDICES_SIZE);
		
		glBindVertexArray(0);
	}
	
	void BatchRenderer2D::begin() {
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		buffer = (Vertex*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}
	
	void BatchRenderer2D::submit(const Renderable2D* renderable) const {
		if (indexCount >= BATCH_RENDERER_INDICES_SIZE)
			return;
		
		const glm::vec3& position = renderable->getPosition();
		const glm::vec2& size = renderable->getSize();
		const glm::vec4& color = renderable->getColor();
		
		unsigned int r = (unsigned int) (color.x * 255.0f);
		unsigned int g = (unsigned int) (color.y * 255.0f);
		unsigned int b = (unsigned int) (color.z * 255.0f);
		unsigned int a = (unsigned int) (color.w * 255.0f);
		
		unsigned int c = a << 24 | b << 16 | g << 8 | r;
		
		buffer->position = glm::vec3(currentTransformation * glm::vec4(position, 1));
		buffer->color = c;
		buffer++;
		
		buffer->position = glm::vec3(currentTransformation * glm::vec4(position.x, position.y + size.y, position.z, 1));
		buffer->color = c;
		buffer++;
		
		buffer->position = glm::vec3(currentTransformation * glm::vec4(position.x + size.x, position.y + size.y, position.z, 1));
		buffer->color = c;
		buffer++;
		
		buffer->position = glm::vec3(currentTransformation * glm::vec4(position.x + size.x, position.y, position.z, 1));
		buffer->color = c;
		buffer++;
		
		indexCount += 6;
	}
	
	void BatchRenderer2D::end() {
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
	void BatchRenderer2D::flush() {
		glBindVertexArray(vao);
		ibo->bind();
		
		glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
		
		ibo->unbind();
		glBindVertexArray(0);
		
		indexCount = 0;
	}
	
}}