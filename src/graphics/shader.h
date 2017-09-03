//
// Created by Ole on 29.08.2017.
//

#pragma once

#include <iostream>
#include "GL/glew.h"

namespace vivid {
	namespace graphics {
		
		class Shader {
		public:
			static GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
		
		private:
			GLuint programID;
		public:
			explicit Shader(std::string path);
			~Shader();
			
			void bind() const;
		};
		
	}
}
