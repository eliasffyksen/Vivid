//
// Created by Ole on 07.09.2017.
//

#pragma once

#include <vector>
#include "GL/glew.h"
#include "buffer.h"

namespace vivid { namespace graphics {
	
	class VertexArray {
	private:
		GLuint arrayID;
		std::vector<Buffer*> buffers;
	public:
		VertexArray();
		~VertexArray();
		
		void addBuffer(Buffer* buffer, GLuint index);
		void bind() const;
		void unbind() const;
	};
	
}}
