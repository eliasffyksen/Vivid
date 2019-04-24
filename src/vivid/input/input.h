//
// Created by Elias on 05.09.2017.
//

#pragma once

#include <unordered_map>
#include <vivid/util/resource.h>
#include <vivid/graphics/window.h>

#include <vivid/events/keyEvent.h>
#include <vivid/events/mouseEvent.h>
#include <vivid/util/maths.h>

namespace vivid {

	class Input {

#define VIVID_MAX_KEYS 1024
#define VIVID_MAX_MOUSE_BUTTONS 32

	private:
		int frameWidth, frameHeight;

		bool keys[VIVID_MAX_KEYS];
		bool mouseButtons[VIVID_MAX_MOUSE_BUTTONS];

		unsigned int inputCounter;

		unsigned int keysDown[VIVID_MAX_KEYS];
		unsigned int keysUp[VIVID_MAX_KEYS];
		unsigned int mouseButtonsDown[VIVID_MAX_MOUSE_BUTTONS];
		unsigned int mouseButtonsUp[VIVID_MAX_MOUSE_BUTTONS];

		float mouseX, mouseY;
		float xScrollOffset, yScrollOffset;

		mutable std::unordered_map<std::string, int> keyAliasMap;
	public:
		Input();

		bool keyDown(int) const;
		bool keyPressed(int) const;
		bool keyReleased(int) const;
		bool mouseButtonDown(int) const;
		bool mouseButtonPressed(int) const;
		bool mouseButtonReleased(int) const;

		bool keyDown(const std::string &alias) const;
		bool keyPressed(const std::string &alias) const;
		bool keyReleased(const std::string &alias) const;
		bool mouseButtonDown(const std::string &alias) const;
		bool mouseButtonPressed(const std::string &alias) const;
		bool mouseButtonReleased(const std::string &alias) const;

		void getCursorPosition(float &xPos, float & yPos) const;
		void getCursorPosition(vdm::vec2& pos) const;
		void getMouseScroll(float &xOffset, float &yOffset) const;
		void getMouseScroll(vdm::vec2& scroll) const;

		void registerKeyAlias(const std::string &alias, int key) const;
		void deleteKeyAlias(const std::string &alias) const;

		void setFrameSize(const int& width, const int &height);

		void clear();
	public:
		bool keyPressCallback(event::KeyPressEvent& event);
		bool keyReleaseCallback(event::KeyReleaseEvent& event);
		bool mouseMoveCallback(event::MouseMoveEvent& event);
		bool mouseButtonPressCallback(event::MouseButtonPressEvent& event);
		bool mouseButtonReleaseCallback(event::MouseButtonReleaseEvent& event);
		bool mouseScrollCallback(event::MouseScrollEvent& event);
	public:
		enum : int {
			A = 65, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
			ZERO = 48, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
			SPACE = 32, APOSTROPHE = 39,
			COMMA = 44, MINUS, PERIOD, SLASH,
			SEMI_COLON = 59, EQUAL = 61,
			LEFT_BRACKET = 91, BACKSLASH, RIGHT_BRACKET,
			ESCAPE = 256, ENTER, TAB, BACKSPACE, INSERT, DELETE,
			RIGHT, LEFT, DOWN, UP,
			PAGE_UP, PAGE_DOWN, HOME, END,
			CAPS_LOCK = 280, SCROLL_LOCK, PRINT_SCREEN, PAUSE,
			F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,F11,F12,F13,F14,F15,F16,F17,F18,F19,F20,F21,F22,F23,F24,F25,
			KP0 = 320, KP1,KP2,KP3,KP4,KP5,KP6,KP7,KP8,KP9,
			KP_DECIMAL, KP_DIVIDE, KP_MULTIPLY, KP_SUBTRACT, KP_ADD, KP_ENTER, KP_EQUAL,
			LEFT_SHIFT = 340, LEFT_CONTROL, LEFT_ALT, LEFT_SUPER,
			RIGHT_SHIFT, RIGHT_CONTROL, RIGHT_ALT, RIGHT_SUPER, MENU
		};
	};

}
