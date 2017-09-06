// Include standard headers
#include <iostream>
#include <unistd.h>

#include "vivid/vivid.h"

#include "config.h"

int main() {
	using namespace vivid;
	using namespace graphics;
	
	Window window("Window!!", 800, 600);
	Input input(window.window);
	
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	
	Shader simple("shaders/simple");
	
	static const GLfloat g_vertex_buffer_data[] = {
			-.5f, .5f, 0.0f,
			-.3f, .5f, 0.0f,
			0.0f, -.3f, 0.0f,
			0.3f, .5f, 0.0f,
			0.5f, .5f, 0.0f,
			.0f, -.5f, 0.0f,
	};
	
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	
	float fpsTimer = 0.0f;
	int fpsCount = 0;
	Timer timer;
	timer.reset();

	while (!window.isClosed()) {

		if(input.keyPressed(GLFW_KEY_SPACE))
			LOG("DOWN");
		input.clear();

		float delta = timer.elapsed();
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

		glDrawArrays(GL_TRIANGLES, 0, 6);
		glDisableVertexAttribArray(0);
		
		window.update();
		fpsTimer += delta;
		fpsCount++;
		if(fpsTimer >= 1) {
			fpsTimer--;
			LOG(fpsCount << " fps");
			fpsCount = 0;
		}
	}
	
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	
	return 0;
}

