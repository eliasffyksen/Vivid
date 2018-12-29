//
// Created by Elias on 05.09.2017.
//

#include "input.h"

namespace vivid {

	Input::Input() {
		inputCounter = 1;
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

	void Input::getCursorPosition(float &x, float &y) const {
		x = (2 * mouseX - frameWidth) / frameHeight;
		y = (frameHeight - 2 * mouseY) / frameHeight;
	}

	void Input::getCursorPosition(vdm::vec2& pos) const {
		getCursorPosition(pos.x, pos.y);
	}

	void Input::getMouseScroll(float &xOffset, float &yOffset) const {
		xOffset = xScrollOffset;
		yOffset = yScrollOffset;
	}

	void Input::getMouseScroll(vdm::vec2& scroll) const {
		getMouseScroll(scroll.x, scroll.y);
	}

	void Input::registerKeyAlias(const std::string &alias, int key) const {
		keyAliasMap[alias] = key;
	}

	void Input::deleteKeyAlias(const std::string &alias) const {
		keyAliasMap.erase(alias);
	}

	void Input::setFrameSize(const int &width, const int &height) {
		frameWidth = width;
		frameHeight = height;
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

	bool Input::keyPressCallback(event::KeyPressEvent &event) {
		keys[event.key] = true;
		if (event.repeats == 0) {
			keysDown[event.key] = inputCounter;
		}

		return true;
	}

	bool Input::keyReleaseCallback(event::KeyReleaseEvent &event) {
		keys[event.key] = false;
		keysUp[event.key] = inputCounter;

		return true;
	}

	bool Input::mouseMoveCallback(event::MouseMoveEvent &event) {
		mouseX = (float) event.xPos;
		mouseY = (float) event.yPos;

		return true;
	}

	bool Input::mouseButtonPressCallback(event::MouseButtonPressEvent &event) {
		mouseButtons[event.button] = true;
		mouseButtonsDown[event.button] = inputCounter;

		return true;
	}

	bool Input::mouseButtonReleaseCallback(event::MouseButtonReleaseEvent &event) {
		mouseButtons[event.button] = false;
		mouseButtonsUp[event.button] = inputCounter;

		return true;
	}

	bool Input::mouseScrollCallback(event::MouseScrollEvent &event) {
		xScrollOffset = (float) event.xOffset;
		yScrollOffset = (float) event.yOffset;

		return true;
	}

}