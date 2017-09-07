//
// Created by Ole on 29.08.2017.
//

#include "window.h"

namespace vivid { namespace graphics {

	Window::Window(std::string title, int width, int height)
			: title(title), width(width), height(height) {
		if (!init())
			glfwTerminate();
	}

	Window::~Window() {
		glfwTerminate();
	}

	bool Window::init() {
		if (!glfwInit()) {
			LOGE("Failed to initialize GLFW.\n");
			return false;
		}

		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (!window) {
			glfwTerminate();
			std::cout << "Failed to create window..." << std::endl;
			return false;
		}

		glfwMakeContextCurrent(window);
		initWindowPointer(window);
		setWindowPointer(window, VIVID_WINDOW_PNTR, this);

		glfwSetFramebufferSizeCallback(window, Window::framebufferSizeCallback);
		glfwSwapInterval(0); // disables VSync

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK) {
			LOGE("Failed to initialize GLEW\n");
			getchar();
			glfwTerminate();
			return false;
		}

		return true;
	}

	void Window::clear() const {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update() {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	bool Window::isClosed() const {
		return glfwWindowShouldClose(window) == 1;
	}

	void Window::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
		auto win = getWindowPointer<Window>(window, VIVID_WINDOW_PNTR);
		win->width = width;
		win->height = height;

		glViewport(0, 0, width, height);
	}

}}
