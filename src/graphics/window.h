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
			const char* title;
			int width, height;
			
			GLFWwindow* window;
			
			mutable std::unordered_map<std::string, int> aliases;
			bool keys_down[MAX_KEYS];
			bool keys_clicked[MAX_KEYS];
			bool mouseButtons_down[MAX_MOUSE_BUTTONS];
			bool mouseButtons_clicked[MAX_MOUSE_BUTTONS];
			double mouseX, mouseY;
		public:
			Window(const char* name, int width, int height);
			~Window();
			
			void update();
			void clear() const;
			
			bool isClosed() const;
			
			void resetInput();
			bool isKeyPressed(int key) const;
			bool isKeyPressed(const std::string& alias) const;
			bool isKeyClicked(int key) const;
			bool isKeyClicked(const std::string& alias) const;
			bool isMouseButtonPressed(int button) const;
			bool isMouseButtonPressed(const std::string& alias) const;
			bool isMouseButtonClicked(int button) const;
			bool isMouseButtonClicked(const std::string& alias) const;
			
			bool aliasExists(const std::string& alias) const;
			void registerAlias(const std::string& alias, int key) const;
			void deleteAlias(const std::string& alias) const;
			
			void getCursorPosition(double& x, double& y) const;
			
			inline int getWidth() const { return width; }
			inline int getHeight() const { return height; }
		private:
			bool init();
			
			static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
			static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
			static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
		};
		
		enum KEYS {
		
		};
		
	}
}
