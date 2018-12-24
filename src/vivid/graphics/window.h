//
// Created by Ole on 29.08.2017.
//

#pragma once

#include <vivid/vivid.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <vivid/events/event.h>

namespace vivid { namespace graphics {

	struct WindowData {
		std::string title;
		int width, height;
		void (*eventCallback)(event::Event&);
	};

	class Window {
	public:
		GLFWwindow *window;
	private:
		WindowData data;
	public:
		Window(std::string title, int width, int height);
		~Window();

		void update();
		void clear();
		void close();
		bool isClosed() const;

		void setEventCallback(void(*eventCallbackFunction)(event::Event&));

		inline int getWidth() const { return data.width; }
		inline int getHeight() const { return data.height; }
	private:
		bool init();

		static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
		static void keyCallback(GLFWwindow *window, int, int, int, int);
		static void cursorPositionCallback(GLFWwindow *window, double, double);
		static void mouseButtonCallback(GLFWwindow *window, int, int, int);
	};

}}
