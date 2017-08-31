//
// Created by Ole on 29.08.2017.
//

#ifndef GLTEST_SHADER_H
#define GLTEST_SHADER_H

#include <iostream>
#include "GL/glew.h"

namespace vivid {
	namespace graphics {

		class Shader {
		public:
			static GLuint LoadShaders(const char *vertex_file_path, const char *fragment_file_path);

		private:
			GLuint programID;
		public:
			Shader(std::string path);

			~Shader();

			void bind() const;
		};

	}
}


#endif //GLTEST_SHADER_H
