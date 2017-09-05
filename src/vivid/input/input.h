//
// Created by Elias on 05.09.2017.
//

#pragma once

#include "../vivid.h"

//#undef DELETE

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
		enum Keys {
				A = 65, B, C, D, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
				Zero = 48, One, Two, Three, Four, Five, Six, Seven, Eight, Nine,
				Space = 32, Apostrophe = 39,
				Comma = 44, Minus, Period, Slash,
				Semi_colon = 59, Equal = 61,
				Left_bracket = 91, Backslash, Right_bracket,
				Escape = 256, Tab, Backspace, Delete,
				Right, Left, Down, Up,
				Page_up, Page_down, Home, End,
				Caps_lock = 280, Scroll_lock, Print_screen, Pause,
				F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,F11,F12,F13,F14,F15,F16,F17,F18,F19,F20,F21,F22,F23,F24,F25,
				KP0 = 320, KP1,KP2,KP3,KP4,KP5,KP6,KP7,KP8,KP9,
				KP_Decimal, KP_Divide, KP_Multiply, KP_Subtract, KP_Add, KP_Enter, KP_Equal,
				Left_shift = 340, Left_control, Left_alt, Left_super,
				Right_shift, Right_control, Right_alt, Right_super, Menu
		};
	};
}




