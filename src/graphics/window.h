//
// Created by Ole on 29.08.2017.
//

#pragma once

#include <GLFW/glfw3.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include "../config.h"

namespace vivid {
	namespace graphics {

#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 32

		class Window {
		private:
			const char *title;
			int width, height;

			GLFWwindow *window;

			mutable std::unordered_map<std::string, int> aliases;
			bool keys_down[MAX_KEYS];
			bool keys_clicked[MAX_KEYS];
			bool mouseButtons_down[MAX_MOUSE_BUTTONS];
			bool mouseButtons_clicked[MAX_MOUSE_BUTTONS];
			double mouseX, mouseY;
		public:
			Window(const char *name, int width, int height);
			~Window();

			void update();
			void clear() const;
			bool isClosed() const;

			void resetInput();
			bool isKeyPressed(int key) const;
			bool isKeyPressed(const std::string &alias) const;
			bool isKeyClicked(int key) const;
			bool isKeyClicked(const std::string &alias) const;
			bool isMouseButtonPressed(int button) const;
			bool isMouseButtonPressed(const std::string &alias) const;
			bool isMouseButtonClicked(int button) const;
			bool isMouseButtonClicked(const std::string &alias) const;

			bool aliasExists(const std::string &alias) const;
			void registerAlias(const std::string &alias, int key) const;
			void deleteAlias(const std::string &alias) const;

			void getCursorPosition(double &x, double &y) const;

			inline int getWidth() const { return width; }
			inline int getHeight() const { return height; }

			enum KEYS {
				A = 65, B, D, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
				ZERO = 48, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
				SPACE = 32, APOSTROPHE = 39,
				COMMA = 44, MINUES, PERIOD, SLASH,
				SEMI_COLON = 59, EQUAL = 61,
				LEFT_BRACKET = 91, BACKSLASH, RIGHT_BRACKET,
				ESCAPE = 256, TAB, BACKSPACE, DELETE,
				RIGHT, LEFT, DOWN, UP,
				PAGE_UP, PAGE_DOWN, HOME, END,
				CAPS_LOCK = 280, SCROLL_LOCK, PRINT_SCREEN, PAUSE,
				F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,F11,F12,F13,F14,F15,F16,F17,F18,F19,F20,F21,F22,F23,F24,F25,
				KP0 = 320, KP1,KP2,KP3,KP4,KP5,KP6,KP7,KP8,KP9,
				KP_DECIMAL, KP_DIVIDE, KP_MULTIPLY, KP_SUBTRACT, KP_ADD, KP_ENTER, KP_EQUAL,
				LEFT_SHIFT = 340, LEFT_CONTROL, LEFT_ALT, LEFT_SUPER,
				RIGHT_SHIFT, RIGHT_CONTROL, RIGHT_ALT, RIGHT_SUPER, MENU
			};
		private:
			bool init();

			static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
			static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
			static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
			static void cursorPositionCallback(GLFWwindow *window, double xpos, double ypos);
		};

	}
}