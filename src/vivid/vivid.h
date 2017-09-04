//
// Created by Elias on 04.09.2017.
//

#pragma once

#include <GLFW/glfw3.h>

#include "graphics/window.h"
#include "graphics/shader.h"

#define VIVID_PNTR_MAX 16

#define VIVID_WINDOW_PNTR 0
#define VIVID_INPUT_PNTR 1

namespace vivid{

	template <typename P>
	inline static void initWindowPointer(GLFWwindow* window){ glfwSetWindowUserPointer(window, new void*[VIVID_PNTR_MAX]);}

	template <typename P>
	static P* getWindowPointer(GLFWwindow* window, int pointerID){
		P** ptrList = glfwGetWindowUserPointer(window);
		P* ptr = ptrList[pointerID];
		return ptr;
	}

	static void setWindowPointer(GLFWwindow* window, int pointerID, void* pointer){
		void** ptrList = (void **) glfwGetWindowUserPointer(window);
		ptrList[pointerID] = pointer;
	}
}