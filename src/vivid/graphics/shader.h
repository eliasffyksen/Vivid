//
// Created by Ole on 29.08.2017.
//

#pragma once

#include "vivid/core.h"
#include <GL/glew.h>
#include <vivid/util/maths.h>
#include <unordered_map>

namespace vivid {
	namespace graphics {

		class Shader {
		private:
			unsigned int program;
			std::unordered_map<std::string, int> uniformLocations;
		public:
			explicit Shader(std::string path);
			~Shader();

			bool loadUniform(const std::string &name);

			void setUniform(const std::string &name, const float &value);
			void setUniform(const std::string &name, const float &x, const float &y);
			void setUniform(const std::string &name, const vdm::vec2 &vec);
			void setUniform(const std::string &name, const float &x, const float &y, const float &z);
			void setUniform(const std::string &name, const vdm::vec3 &vec);
			void setUniform(const std::string &name, const float &x, const float &y, const float &z, const float &w);
			void setUniform(const std::string &name, const vdm::vec4 &vec);
			void setUniform(const std::string &name, const vdm::mat4 &vec);

			void bind() const;
			void unbind() const;
		private:
			int getUniformLocation(const std::string &name);
		};

	}
}
