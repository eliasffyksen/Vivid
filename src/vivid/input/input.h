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
	};
}




