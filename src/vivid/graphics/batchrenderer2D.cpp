//
// Created by Ole on 07.09.2017.
//

#include "batchrenderer2D.h"

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
		glBufferData(GL_ARRAY_BUFFER, BATCH_RENDERER_BUFFER_SIZE, nullptr, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(SHADER_POSITION_INDEX);
		glEnableVertexAttribArray(SHADER_TEXCOORDS_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);

		glVertexAttribPointer(SHADER_POSITION_INDEX, 3, GL_FLOAT, GL_FALSE, BATCH_RENDERER_VERTEX_SIZE, (const GLvoid *) nullptr);
		glVertexAttribPointer(SHADER_TEXCOORDS_INDEX, 2, GL_FLOAT, GL_FALSE, BATCH_RENDERER_VERTEX_SIZE, (const GLvoid *) (offsetof(Vertex, Vertex::textureCoordinates)));

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		GLuint indices[BATCH_RENDERER_INDICES_SIZE];
		for (unsigned int offset = 0, i = 0; i < BATCH_RENDERER_INDICES_SIZE; i += 6) {
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
		buffer = (Vertex *) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}

	void BatchRenderer2D::submit(const Quad *quad) const {
		if (indexCount >= BATCH_RENDERER_INDICES_SIZE)
			return;

		if (buffer == nullptr) {
			LOGE("[ERROR] Render buffer is a nullptr, may be caused by opening more than one renderer at the same time");
			return;
		}

		const vdm::vec3 &position = quad->getPosition();
		const vdm::vec2 &size = quad->getSize();

		float uvLeft = 0.0f;
		float uvTop = 0.0f;
		float uvRight = 1.0f;
		float uvBottom = 1.0f;

		if(quad->getTextureHandle() != nullptr) {
			uvLeft = quad->getTextureHandle()->uvMin.u;
			uvTop = quad->getTextureHandle()->uvMin.v;
			uvRight = quad->getTextureHandle()->uvMax.u;
			uvBottom = quad->getTextureHandle()->uvMax.v;
		}

		buffer->position = (currentTransformation * vdm::vec4(position, 1)).xyz();
		buffer->textureCoordinates = vdm::vec2(uvLeft, uvBottom);
		buffer++;

		buffer->position = (currentTransformation * vdm::vec4(position.x, position.y + size.y, position.z, 1)).xyz();
		buffer->textureCoordinates = vdm::vec2(uvLeft, uvTop);
		buffer++;

		buffer->position = (currentTransformation * vdm::vec4(position.x + size.x, position.y + size.y, position.z, 1)).xyz();
		buffer->textureCoordinates = vdm::vec2(uvRight, uvTop);
		buffer++;

		buffer->position = (currentTransformation * vdm::vec4(position.x + size.x, position.y, position.z, 1)).xyz();
		buffer->textureCoordinates = vdm::vec2(uvRight, uvBottom);
		buffer++;

		indexCount += 6;
	}

	void BatchRenderer2D::end() {
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void BatchRenderer2D::flush() {
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		ibo->bind();

		glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);

		ibo->unbind();
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		indexCount = 0;
	}

}}