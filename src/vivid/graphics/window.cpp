//
// Created by Ole on 29.08.2017.
//

#include "window.h"

#include <vivid/input/input.h>
#include <vivid/events/windowEvent.h>
#include <vivid/events/keyEvent.h>
#include <vivid/events/mouseEvent.h>

namespace vivid { namespace graphics {

	Window::Window(std::string title, int width, int height) {
		data.title = std::move(title);
		data.width = width;
		data.height = height;
		if (!init())
			glfwTerminate();
	}

	Window::~Window() {
		glfwTerminate();
	}

	bool Window::init() {
		data.eventCallback = nullptr;

		if (!glfwInit()) {
			LOGE("Failed to initialize GLFW.\n");
			return false;
		}

		glfwWindowHint(GLFW_SAMPLES, 16); // TODO: Make this configurable
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		data.window = glfwCreateWindow(data.width, data.height, data.title.c_str(), nullptr, nullptr);
		if (!data.window) {
			glfwTerminate();
			std::cout << "Failed to create window..." << std::endl;
			return false;
		}

		glfwMakeContextCurrent(data.window);
		glfwSetWindowUserPointer(data.window, &data);

		glfwSetWindowCloseCallback(data.window, Window::windowCloseCallback);
		glfwSetWindowFocusCallback(data.window, Window::windowFocusCallback);
		glfwSetFramebufferSizeCallback(data.window, Window::framebufferSizeCallback);
		glfwSetKeyCallback(data.window, Window::keyCallback);
		glfwSetMouseButtonCallback(data.window, Window::mouseButtonCallback);
		glfwSetCursorPosCallback(data.window, Window::cursorPositionCallback);
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

	void Window::update() {
		glfwSwapBuffers(data.window);
		glfwPollEvents();
	}

	void Window::clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::close() {
		glfwSetWindowShouldClose(data.window, GL_TRUE);
		event::WindowCloseEvent event;
		data.eventCallback(event);
	}

	bool Window::isClosed() const {
		return glfwWindowShouldClose(data.window) == 1;
	}

	void Window::setEventCallback(EventCallbackFunction eventCallback) {
		data.eventCallback = std::move(eventCallback);
	}

	void Window::windowCloseCallback(GLFWwindow *window) {
		WindowData& win = *(WindowData*) glfwGetWindowUserPointer(window);
		event::WindowCloseEvent event;
		win.eventCallback(event);
	}

	void Window::windowFocusCallback(GLFWwindow *window, int gainedFocus) {
		WindowData& win = *(WindowData*) glfwGetWindowUserPointer(window);
		event::WindowFocusEvent event(gainedFocus == 1);
		win.eventCallback(event);
	}

	void Window::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
		WindowData& win = *(WindowData*) glfwGetWindowUserPointer(window);
		win.width = width;
		win.height = height;
		event::WindowResizeEvent event(width, height);
		win.eventCallback(event);
	}

	void Window::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
		WindowData& win = *(WindowData*) glfwGetWindowUserPointer(window);
		switch (action) {
			case GLFW_PRESS: {
				event::KeyPressEvent event(key, 0);
				win.eventCallback(event);
				break;
			}
			case GLFW_RELEASE: {
				event::KeyReleaseEvent event(key);
				win.eventCallback(event);
				break;
			}
			case GLFW_REPEAT: {
				event::KeyPressEvent event(key, 1);
				win.eventCallback(event);
				break;
			}
			default:
				break;
		}
	}

	void Window::cursorPositionCallback(GLFWwindow *window, double xPos, double yPos) {
		WindowData& win = *(WindowData*) glfwGetWindowUserPointer(window);
		event::MouseMoveEvent event((float) xPos, (float) yPos);
		win.eventCallback(event);
	}

	void Window::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
		WindowData& win = *(WindowData*) glfwGetWindowUserPointer(window);
		switch (action) {
			case GLFW_PRESS: {
				event::MouseButtonPressEvent event(button);
				win.eventCallback(event);
				break;
			}
			case GLFW_RELEASE: {
				event::MouseButtonReleaseEvent event(button);
				win.eventCallback(event);
				break;
			}
			default:
				break;
		}
	}

}}
