//
// Created by Elias on 05.09.2017.
//

#include "input.h"

namespace vivid {
	
	Input::Input(GLFWwindow* window) {
		setWindowPointer(window, VIVID_INPUT_POINTER, this);
		
		for (int i = 0; i < VIVID_MAX_KEYS; i++) {
			keys[i] = false;
			keysDown[i] = 0;
			keysUp[i] = 0;
		}
		for (int i = 0; i < VIVID_MAX_MOUSE_BUTTONS; i++) {
			mouseButtons[i] = false;
			mouseButtonsUp[i] = 0;
			mouseButtonsDown[i] = 0;
		}
		
		mouseX = 0;
		mouseY = 0;
		
		glfwSetKeyCallback(window, Input::keyCallback);
		glfwSetCursorPosCallback(window, Input::cursorPositionCallback);
		glfwSetMouseButtonCallback(window, Input::mouseButtonCallback);
	}
	
	bool Input::keyDown(int key) const {
		return keys[key];
	}
	
	bool Input::keyPressed(int key) const {
		return keysDown[key] == inputCounter;
	}
	
	bool Input::keyReleased(int key) const {
		return keysUp[key] == inputCounter;
	}
	
	bool Input::mouseButtonDown(int button) const {
		return mouseButtons[button];
	}
	
	bool Input::mouseButtonPressed(int button) const {
		return mouseButtonsDown[button] == inputCounter;
	}
	
	bool Input::mouseButtonReleased(int button) const {
		return mouseButtonsUp[button] == inputCounter;
	}
	
	bool Input::keyDown(const std::string& alias) const {
		auto it = keyAliasMap.find(alias);
		if (it != keyAliasMap.end()) {
			keyDown(keyAliasMap[alias]);
		}
	}
	
	bool Input::keyPressed(const std::string& alias) const {
		auto it = keyAliasMap.find(alias);
		if (it != keyAliasMap.end()) {
			keyPressed(keyAliasMap[alias]);
		}
	}
	
	bool Input::keyReleased(const std::string &alias) const {
		auto it = keyAliasMap.find(alias);
		if (it != keyAliasMap.end()) {
			keyReleased(keyAliasMap[alias]);
		}
	}
	
	bool Input::mouseButtonDown(const std::string& alias) const {
		auto it = keyAliasMap.find(alias);
		if (it != keyAliasMap.end()) {
			mouseButtonDown(keyAliasMap[alias]);
		}
	}
	
	bool Input::mouseButtonPressed(const std::string& alias) const {
		auto it = keyAliasMap.find(alias);
		if (it != keyAliasMap.end()) {
			mouseButtonPressed(keyAliasMap[alias]);
		}
	}
	
	bool Input::mouseButtonReleased(const std::string& alias) const {
		auto it = keyAliasMap.find(alias);
		if (it != keyAliasMap.end()) {
			mouseButtonReleased(keyAliasMap[alias]);
		}
	}
	
	void Input::getCursorPosition(double& x, double& y) const {
		x = mouseX;
		y = mouseY;
	}
	
	void Input::registerKeyAlias(const std::string& alias, int key) const {
		keyAliasMap[alias] = key;
	}
	
	void Input::deleteKeyAlias(const std::string& alias) const {
		keyAliasMap.erase(alias);
	}
	
	void Input::clear() {
		inputCounter++;
		if (inputCounter == 0) {
			inputCounter = 1;
			for (int i = 0; i < VIVID_MAX_KEYS; i++) {
				keysDown[i] = 0;
				keysUp[i] = 0;
			}
			for (int i = 0; i < VIVID_MAX_MOUSE_BUTTONS; i++) {
				mouseButtonsDown[i] = 0;
				mouseButtonsUp[i] = 0;
			}
		}
	}
	void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		
		Input* input = getWindowPointer<Input>(window, VIVID_INPUT_POINTER);

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
		Input *input = getWindowPointer<Input>(window, VIVID_INPUT_POINTER);

		input->mouseX = xpos;
		input->mouseY = ypos;
	}

	void Input::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
		Input *input = getWindowPointer<Input>(window, VIVID_INPUT_POINTER);

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