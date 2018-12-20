//
// Created by Ole on 29.08.2017.
//

#include "shader.h"

#include <vector>
#include <fstream>

namespace vivid { namespace graphics {

	unsigned int createShader(const unsigned int& type, const std::string& filePath) {
		GLuint shader = glCreateShader(type);

		const std::string vertexSource = loadTextFile(filePath);
		const char *const vertexPointer = vertexSource.c_str();
		glShaderSource(shader, 1, &vertexPointer, nullptr);
		glCompileShader(shader);

		GLint result = GL_FALSE; // TODO: only in debug builds pls
		glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE) {
			int length;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
			char *error = (char *) alloca(length * sizeof(char));
			glGetShaderInfoLog(shader, length, &length, error);
			LOGE("Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader:\n" << error);
			return 0;
		}

		return shader;
	}

	Shader::Shader(std::string path) {
		unsigned int vertexShader = createShader(GL_VERTEX_SHADER, path + ".vs");
		unsigned int fragmentShader = createShader(GL_FRAGMENT_SHADER, path + ".fs");

		program = glCreateProgram();
		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);
		glLinkProgram(program);

		GLint result = GL_FALSE;
		glGetProgramiv(program, GL_LINK_STATUS, &result);
		if (result == GL_FALSE) {
			int length;
			glGetShaderiv(program, GL_INFO_LOG_LENGTH, &length);
			char *error = (char *) alloca(length * sizeof(char));
			glGetShaderInfoLog(program, length, &length, error);
			LOGE("Failed to link program:\n" << error);
			return;
		}

		glDetachShader(program, vertexShader);
		glDetachShader(program, fragmentShader);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
	
	Shader::~Shader() {
		glDeleteProgram(program);
	}
	
	bool Shader::loadUniform(const std::string& name) {
		GLint location = glGetUniformLocation(program, name.c_str());
		if (location != -1) {
			uniformLocations[name] = location;
			return true;
		}
		return false;
	}
	
	void Shader::setUniform(const std::string& name, const float& value) {
		glUniform1f(getUniformLocation(name), value);
	}
	void Shader::setUniform(const std::string& name, const float& x, const float& y) {
		glUniform2f(getUniformLocation(name), x, y);
	}
	void Shader::setUniform(const std::string& name, const glm::vec2& vec) {
		glUniform2f(getUniformLocation(name), vec.x, vec.y);
	}
	void Shader::setUniform(const std::string& name, const float& x, const float& y, const float& z) {
		glUniform3f(getUniformLocation(name), x, y, z);
	}
	void Shader::setUniform(const std::string& name, const glm::vec3& vec) {
		glUniform3f(getUniformLocation(name), vec.x, vec.y, vec.z);
	}
	void Shader::setUniform(const std::string& name, const float& x, const float& y, const float& z, const float& w) {
		glUniform4f(getUniformLocation(name), x, y, z, w);
	}
	void Shader::setUniform(const std::string& name, const glm::vec4& vec) {
		glUniform4f(getUniformLocation(name), vec.x, vec.y, vec.z, vec.w);
	}
	void Shader::setUniform(const std::string& name, const glm::mat4& mat) {
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
	}
	
	void Shader::bind() const {
		glUseProgram(program);
	}
	
	void Shader::unbind() const {
		glUseProgram(0);
	}
	
	int Shader::getUniformLocation(const std::string& name) {
		auto it = uniformLocations.find(name);
		if (it != uniformLocations.end()) {
			return it->second;
		}
		return -1;
	}
	
}}
