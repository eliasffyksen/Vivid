//
// Created by Elias on 05.09.2017.
//

#include "input.h"

namespace vivid {

	Input::Input(GLFWwindow *window) {
		setWindowPointer(window, VIVID_INPUT_PNTR, this);

		for (int i = 0; i < VIVID_MAX_KEYS; i++) {
			keys    [i] = false;
			keysDown[i] = 0;
			keysUp  [i] = 0;
		}
		for (int i = 0; i < VIVID_MAX_MOUSE_BUTTONS; i++) {
			mouseButtons    [i] = false;
			mouseButtonsUp  [i] = 0;
			mouseButtonsDown[i] = 0;
		}

		mouseX = 0;
		mouseY = 0;

		glfwSetKeyCallback        (window, Input::keyCallback);
		glfwSetCursorPosCallback  (window, Input::cursorPositionCallback);
		glfwSetMouseButtonCallback(window, Input::mouseButtonCallback);
	}

	bool Input::keyDown(int key) {
		return keys[key];
	}

	bool Input::keyPressed(int key) {
		return keysDown[key] == inputCounter;
	}

	bool Input::keyRelease(int key) {
		return keysUp[key] == inputCounter;
	}

	bool Input::mouseButtonDown(int button) {
		return mouseButtons[button];
	}

	bool Input::mouseButtonPressed(int button) {
		return mouseButtonsDown[button] == inputCounter;
	}

	bool Input::mouseButtonReleased(int button) {
		return mouseButtonsUp[button] == inputCounter;
	}

	void Input::getCursorPosition(double &x, double &y) {
		x = mouseX;
		y = mouseY;
	}

	void Input::clear() {
		inputCounter++;
		if (inputCounter == 0) {
			inputCounter = 1;
			for (int i = 0; i < VIVID_MAX_KEYS; i++) {
				keysDown[i] = 0;
				keysUp  [i] = 0;
			}
			for (int i = 0; i < VIVID_MAX_MOUSE_BUTTONS; i++) {
				mouseButtonsDown[i] = 0;
				mouseButtonsUp  [i] = 0;
			}
		}
	}

	void Input::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
		Input *input = getWindowPointer<Input>(window, VIVID_INPUT_PNTR);

		switch (action) {
			case GLFW_PRESS:
				input->keys[key] = true;
				input->keysDown[key] = input->inputCounter;
				break;
			case GLFW_RELEASE:
				input->keys[key] = false;
				input->keysUp[key] = input->inputCounter;
				break;
		}
	}

	void Input::cursorPositionCallback(GLFWwindow *window, double xpos, double ypos) {
		Input *input = getWindowPointer<Input>(window, VIVID_INPUT_PNTR);

		input->mouseX = xpos;
		input->mouseY = ypos;
	}

	void Input::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
		Input *input = getWindowPointer<Input>(window, VIVID_INPUT_PNTR);

		switch (action) {
			case GLFW_PRESS:
				input->mouseButtons[button] = true;
				input->mouseButtonsDown[button] = input->inputCounter;
				break;
			case GLFW_RELEASE:
				input->mouseButtons[button] = false;
				input->mouseButtonsUp[button] = input->inputCounter;
				break;
		}
	}

}