//
// Created by stroh on 16/12/2018.
//

#pragma once

#include <vivid/util/config.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace vivid {

	std::string loadTextFile(std::string filePath);

	void initWindowPointer(GLFWwindow *window);

	template<typename P>
	P *getWindowPointer(GLFWwindow *window, int pointerID);

	void setWindowPointer(GLFWwindow *window, int pointerID, void *pointer);

}
