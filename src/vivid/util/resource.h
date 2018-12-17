//
// Created by stroh on 16/12/2018.
//

#pragma once

#define VIVID_PNTR_MAX 16

#define VIVID_WINDOW_PNTR 0
#define VIVID_INPUT_PNTR 1

#include "../vivid.h"

namespace vivid {

	inline void initWindowPointer(GLFWwindow *window) {
		glfwSetWindowUserPointer(window, new void *[VIVID_PNTR_MAX]);
	}

	template<typename P>
	inline P *getWindowPointer(GLFWwindow *window, int pointerID) {
		P **ptrList = (P **) glfwGetWindowUserPointer(window);
		P *ptr = ptrList[pointerID];
		return ptr;
	}

	inline void setWindowPointer(GLFWwindow *window, int pointerID, void *pointer) {
		void **ptrList = (void **) glfwGetWindowUserPointer(window);
		ptrList[pointerID] = pointer;
	}

}
