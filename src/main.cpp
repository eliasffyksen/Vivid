// Include standard headers
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "graphics/window.h"
#include "graphics/shader.h"

#include "config.h"

int main() {
	using namespace vivid;
	using namespace graphics;
	
	Window window("Window!!", 800, 600);
	
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		ERROR("Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	
	Shader simple("shaders/simple");
	
	static const GLfloat g_vertex_buffer_data[] = {
			-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
	};
	
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	
	window.registerAlias("A", 65);
	
	while (!window.isClosed()) {
		
		LOG(window.isKeyPressed("A"));
		
		window.clear();
		simple.bind();
		
		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(
				0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				nullptr            // array buffer offset
		);
		
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
		
		window.update();
	}
	
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	
	return 0;
}

