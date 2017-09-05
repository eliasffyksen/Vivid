//
// Created by Elias on 05.09.2017.
//

#pragma once

#include "../vivid.h"

namespace vivid {

	class Input {

#define VIVID_MAX_KEYS 1024
#define VIVID_MAX_MOUSE_BUTTONS 32

	private:
		bool keys[VIVID_MAX_KEYS];
		bool mouseButtons[VIVID_MAX_MOUSE_BUTTONS];

		unsigned int inputCounter = 1;

		unsigned int keysDown[VIVID_MAX_KEYS];
		unsigned int keysUp[VIVID_MAX_KEYS];
		unsigned int mouseButtonsDown[VIVID_MAX_MOUSE_BUTTONS];
		unsigned int mouseButtonsUp[VIVID_MAX_MOUSE_BUTTONS];

		double mouseX, mouseY;

	public:
		Input(GLFWwindow*);

		bool keyDown(int);
		bool keyPressed(int);
		bool keyRelease(int);
		bool mouseButtonDown(int);
		bool mouseButtonPressed(int);
		bool mouseButtonReleased(int);

		void getCursorPosition(double &, double &);
		void clear();
	private:
		static void keyCallback(GLFWwindow *, int, int, int, int);
		static void cursorPositionCallback(GLFWwindow*, double, double);
		static void mouseButtonCallback(GLFWwindow*, int, int, int);
	public:
		enum KeyCodes : int {
			A = 65, B, C, D, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
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




