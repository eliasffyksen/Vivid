//
// Created by Ole on 07.09.2017.
//

#pragma once

#include <vivid/graphics/renderer2D.h>
#include <vivid/scenegraph/sprite.h>
#include <vivid/graphics/buffers/buffers.h>

namespace vivid { namespace graphics {

#define BATCH_RENDERER_MAX_SPRITES 50000
#define BATCH_RENDERER_VERTEX_SIZE sizeof(Vertex)
#define BATCH_RENDERER_SPRITE_SIZE (BATCH_RENDERER_VERTEX_SIZE * 4)
#define BATCH_RENDERER_BUFFER_SIZE (BATCH_RENDERER_SPRITE_SIZE * BATCH_RENDERER_MAX_SPRITES)
#define BATCH_RENDERER_INDICES_SIZE (BATCH_RENDERER_MAX_SPRITES * 6)

#define SHADER_POSITION_INDEX 0
#define SHADER_TEXCOORDS_INDEX 1
#define SHADER_COLOR_INDEX 2
	
	class BatchRenderer2D : public Renderer2D {
	private:
		GLuint vao;
		GLuint vbo;
		IndexBuffer* ibo;
		mutable GLsizei indexCount;
		mutable Vertex* buffer;
	public:
		BatchRenderer2D();
		~BatchRenderer2D();
		
		void begin() override;
		void submit(const Quad* quad) const override;
		void end() override;
		void flush() override;
	private:
		void init();
	};
	
}}
