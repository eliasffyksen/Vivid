//
// Created by Elias on 05.09.2017.
//

#include "input.h"

namespace vivid {

	Input::Input(graphics::Window &window)
			: window(&window) {

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

		window.registerInputListener(this);
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

	bool Input::keyDown(const std::string &alias) const {
		auto it = keyAliasMap.find(alias);
		if (it != keyAliasMap.end()) {
			return keyDown(keyAliasMap[alias]);
		}
		return false;
	}

	bool Input::keyPressed(const std::string &alias) const {
		auto it = keyAliasMap.find(alias);
		if (it != keyAliasMap.end()) {
			return keyPressed(keyAliasMap[alias]);
		}
		return false;
	}

	bool Input::keyReleased(const std::string &alias) const {
		auto it = keyAliasMap.find(alias);
		if (it != keyAliasMap.end()) {
			return keyReleased(keyAliasMap[alias]);
		}
		return false;
	}

	bool Input::mouseButtonDown(const std::string &alias) const {
		auto it = keyAliasMap.find(alias);
		if (it != keyAliasMap.end()) {
			return mouseButtonDown(keyAliasMap[alias]);
		}
		return false;
	}

	bool Input::mouseButtonPressed(const std::string &alias) const {
		auto it = keyAliasMap.find(alias);
		if (it != keyAliasMap.end()) {
			return mouseButtonPressed(keyAliasMap[alias]);
		}
		return false;
	}

	bool Input::mouseButtonReleased(const std::string &alias) const {
		auto it = keyAliasMap.find(alias);
		if (it != keyAliasMap.end()) {
			return mouseButtonReleased(keyAliasMap[alias]);
		}
		return false;
	}

	void Input::getCursorPosition(double &x, double &y) const {
		x = mouseX;
		y = mouseY;
	}

	void Input::registerKeyAlias(const std::string &alias, int key) const {
		keyAliasMap[alias] = key;
	}

	void Input::deleteKeyAlias(const std::string &alias) const {
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

	void Input::keyCallback(int key, int scancode, int action, int mods) {
		switch (action) {
			case GLFW_PRESS:
				keys[key] = true;
				keysDown[key] = inputCounter;
				break;
			case GLFW_RELEASE:
				keys[key] = false;
				keysUp[key] = inputCounter;
				break;
			default:
				break;
		}
	}

	void Input::cursorPositionCallback(double xpos, double ypos) {
		mouseX = xpos;
		mouseY = ypos;
	}

	void Input::mouseButtonCallback(int button, int action, int mods) {
		switch (action) {
			case GLFW_PRESS:
				mouseButtons[button] = true;
				mouseButtonsDown[button] = inputCounter;
				break;
			case GLFW_RELEASE:
				mouseButtons[button] = false;
				mouseButtonsUp[button] = inputCounter;
				break;
			default:
				break;
		}
	}

}