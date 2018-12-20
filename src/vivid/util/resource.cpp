//
// Created by stroh on 16/12/2018.
//

#include "resource.h"

#include <fstream>

namespace vivid {

	std::string loadTextFile(std::string filePath) {
		std::string res;
		std::ifstream fileStream(filePath, std::ios::in);
		if (fileStream.is_open()) {
			std::string line;
			while (getline(fileStream, line))
				res += "\n" + line;

			fileStream.close();
		} else {
			LOGE("Could not open " << filePath);
			return "";
		}

		return res;
	}

	void initWindowPointer(GLFWwindow *window) {
		glfwSetWindowUserPointer(window, new void *[VIVID_POINTER_MAX]);
	}

	template<typename P>
	P *getWindowPointer(GLFWwindow *window, int pointerID) {
		P **ptrList = (P **) glfwGetWindowUserPointer(window);
		P *ptr = ptrList[pointerID];
		return ptr;
	}

	void setWindowPointer(GLFWwindow *window, int pointerID, void *pointer) {
		void **ptrList = (void **) glfwGetWindowUserPointer(window);
		ptrList[pointerID] = pointer;
	}

}