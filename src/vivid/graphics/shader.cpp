//
// Created by Ole on 29.08.2017.
//

#include "shader.h"

#include <vector>
#include <fstream>
#include <algorithm>

namespace vivid {
	namespace graphics {
		
		GLuint Shader::LoadShaders(const char* vertex_file_path, const char* fragment_file_path) { // Not my code:))
			// Create the shaders
			GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
			GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
			
			// Read the Vertex Shader code from the file
			std::string VertexShaderCode;
			std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
			if (VertexShaderStream.is_open()) {
				std::string Line = "";
				while (getline(VertexShaderStream, Line))
					VertexShaderCode += "\n" + Line;
				
				VertexShaderStream.close();
			} else {
				printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n",
				       vertex_file_path);
				getchar();
				return 0;
			}
			
			// Read the Fragment Shader code from the file
			std::string FragmentShaderCode;
			std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
			if (FragmentShaderStream.is_open()) {
				std::string Line;
				while (getline(FragmentShaderStream, Line))
					FragmentShaderCode += "\n" + Line;
				
				FragmentShaderStream.close();
			} else {
				printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n",
				       vertex_file_path);
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
				: programID(
				Shader::LoadShaders((path + std::string(".vs")).c_str(), (path + std::string(".fs")).c_str())) {}
		
		Shader::~Shader() {
			glDeleteProgram(programID);
		}
		
		void Shader::bind() const {
			glUseProgram(programID);
		}
		
	}
}