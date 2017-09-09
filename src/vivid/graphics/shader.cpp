//
// Created by Ole on 29.08.2017.
//

#include "shader.h"

#include <vector>
#include <fstream>

namespace vivid { namespace graphics {
		
		GLuint Shader::createShader(const char* vertex_file_path, const char* fragment_file_path) { // Not my code:))
			// Create the shaders
			GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
			GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
			
			// Read the Vertex Shader code from the file
			std::string VertexShaderCode;
			std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
			if (VertexShaderStream.is_open()) {
				std::string line;
				while (getline(VertexShaderStream, line))
					VertexShaderCode += "\n" + line;
				
				VertexShaderStream.close();
			} else {
				printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
				getchar();
				return 0;
			}
			
			// Read the Fragment Shader code from the file
			std::string FragmentShaderCode;
			std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
			if (FragmentShaderStream.is_open()) {
				std::string line;
				while (getline(FragmentShaderStream, line))
					FragmentShaderCode += "\n" + line;
				
				FragmentShaderStream.close();
			} else {
				printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
				getchar();
				return 0;
			}
			
			GLint Result = GL_FALSE;
			int InfoLogLength;
			
			// Compile Vertex Shader
			char const* VertexSourcePointer = VertexShaderCode.c_str();
			glShaderSource(VertexShaderID, 1, &VertexSourcePointer, nullptr);
			glCompileShader(VertexShaderID);
			
			// Check Vertex Shader
			glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
			glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0) {
				std::vector<char> VertexShaderErrorMessage((unsigned long long int) (InfoLogLength + 1));
				glGetShaderInfoLog(VertexShaderID, InfoLogLength, nullptr, &VertexShaderErrorMessage[0]);
				printf("%s\n", &VertexShaderErrorMessage[0]);
			}
			
			// Compile Fragment Shader
			char const* FragmentSourcePointer = FragmentShaderCode.c_str();
			glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, nullptr);
			glCompileShader(FragmentShaderID);
			
			// Check Fragment Shader
			glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
			glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0) {
				std::vector<char> FragmentShaderErrorMessage((unsigned long long int) (InfoLogLength + 1));
				glGetShaderInfoLog(FragmentShaderID, InfoLogLength, nullptr, &FragmentShaderErrorMessage[0]);
				printf("%s\n", &FragmentShaderErrorMessage[0]);
			}
			
			// Link the program and loads the shader code
			GLuint ProgramID = glCreateProgram();
			glAttachShader(ProgramID, VertexShaderID);
			glAttachShader(ProgramID, FragmentShaderID);
			glLinkProgram(ProgramID);
			
			// Check the program
			glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
			glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0) {
				std::vector<char> ProgramErrorMessage((unsigned long long int) (InfoLogLength + 1));
				glGetProgramInfoLog(ProgramID, InfoLogLength, nullptr, &ProgramErrorMessage[0]);
				printf("%s\n", &ProgramErrorMessage[0]);
			}
			
			// Detaches the shader
			glDetachShader(ProgramID, VertexShaderID);
			glDetachShader(ProgramID, FragmentShaderID);
			
			// Deletes the shaders
			glDeleteShader(VertexShaderID);
			glDeleteShader(FragmentShaderID);
			
			return ProgramID;
		}
		
		Shader::Shader(std::string path)
				: programID(Shader::createShader((path + std::string(".vs")).c_str(), (path + std::string(".fs")).c_str())) {}
		
		Shader::~Shader() {
			glDeleteProgram(programID);
		}
		
		bool Shader::loadUniform(const std::string& name) {
			GLint location = glGetUniformLocation(programID, name.c_str());
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
			glUseProgram(programID);
		}
		
		int Shader::getUniformLocation(const std::string& name) {
			auto it = uniformLocations.find(name);
			if (it != uniformLocations.end()) {
				return it->second;
			}
			return -1;
		}
		
}}
