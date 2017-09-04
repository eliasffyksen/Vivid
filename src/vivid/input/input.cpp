//
// Created by Elias on 05.09.2017.
//

#include "input.h"


namespace vivid {

	Input::Input(GLFWwindow * window) {

		setWindowPointer(window, VIVID_INPUT_PNTR, this);

		for(int i = 0; i < VIVID_MAX_KEYS; i++)
			keys[i] = false;

		glfwSetKeyCallback(window, Input::keyCallback);
	}

	bool Input::getKey(int key){
		return keys[key];
	}

	void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

		Input* input = getWindowPointer<Input>(window, VIVID_INPUT_PNTR);

		switch (action){
			case GLFW_PRESS:
				input->keys[key] = true;
				break;
			case GLFW_RELEASE:
				input->keys[key] = false;
				break;
		}
	}

}