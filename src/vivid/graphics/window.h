//
// Created by Ole on 29.08.2017.
//

#pragma once

#include <vivid/vivid.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

namespace vivid { namespace graphics {

	class Window {
	public:
		GLFWwindow *window;
	private:
		std::string title;
		int width, height;
	public:
		Window(std::string title, int width, int height);
		~Window();

		void update();
		void clear();
		void close();
		bool isClosed() const;

		template<typename P>
		P *getWindowPointer(int pointerID);
		void setWindowPointer(int pointerID, void *pointer);

		void registerInputListener(void *input);

		inline int getWidth() const { return width; }

		inline int getHeight() const { return height; }

	private:
		bool init();

		static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
		static void keyCallback(GLFWwindow *window, int, int, int, int);
		static void cursorPositionCallback(GLFWwindow *window, double, double);
		static void mouseButtonCallback(GLFWwindow *window, int, int, int);

		static void setWindowPointer(GLFWwindow *window, int pointerID, void *pointer);
		template<typename P>
		static P *getWindowPointer(GLFWwindow *window, int pointerID);
	};

}}
