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
			static GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
		private:
			GLuint programID;
			std::unordered_map<std::string, int> uniformLocations;
		public:
			explicit Shader(std::string path);
			~Shader();
			
			void loadUniform(const std::string& name);
			
			inline void setUniform(const std::string& name, float& value);
			inline void setUniform(const std::string& name, float& x, float& y);
			inline void setUniform(const std::string& name, glm::vec2& vec);
			inline void setUniform(const std::string& name, float& x, float& y, float& z);
			inline void setUniform(const std::string& name, glm::vec3& vec);
			inline void setUniform(const std::string& name, float& x, float& y, float& z, float& w);
			inline void setUniform(const std::string& name, glm::vec4& vec);
			inline void setUniform(const std::string& name, glm::mat4& vec);
			
			void bind() const;
		private:
			int getUniformLocation(const std::string& name);
		};
		
	}
}
