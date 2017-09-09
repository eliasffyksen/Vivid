//
// Created by Ole on 29.08.2017.
//

#pragma once

#include <glm/glm.hpp>
#include "../vivid.h"
#include <unordered_map>

namespace vivid {
	namespace graphics {
		
		class Shader {
		public:
			static GLuint createShader(const char* vertex_file_path, const char* fragment_file_path);
		private:
			GLuint programID;
			std::unordered_map<std::string, int> uniformLocations;
		public:
			explicit Shader(std::string path);
			~Shader();
			
			bool loadUniform(const std::string& name);
			
			void setUniform(const std::string& name, const float& value);
			void setUniform(const std::string& name, const float& x, const float& y);
			void setUniform(const std::string& name, const glm::vec2& vec);
			void setUniform(const std::string& name, const float& x, const float& y, const float& z);
			void setUniform(const std::string& name, const glm::vec3& vec);
			void setUniform(const std::string& name, const float& x, const float& y, const float& z, const float& w);
			void setUniform(const std::string& name, const glm::vec4& vec);
			void setUniform(const std::string& name, const glm::mat4& vec);
			
			void bind() const;
		private:
			int getUniformLocation(const std::string& name);
		};
		
	}
}
