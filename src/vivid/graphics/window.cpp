//
// Created by Ole on 29.08.2017.
//

#include "window.h"

#include <vivid/input/input.h>

namespace vivid { namespace graphics {

	Window::Window(std::string title, int width, int height)
			: title(std::move(title)), width(width), height(height) {
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

		glfwWindowHint(GLFW_SAMPLES, 16); // TODO: Make this configurable
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
		glfwSetWindowUserPointer(window, new void *[VIVID_POINTER_MAX]);
		setWindowPointer(window, VIVID_WINDOW_POINTER, this);

		glfwSetFramebufferSizeCallback(window, Window::framebufferSizeCallback);
		glfwSetKeyCallback(window, Window::keyCallback);
		glfwSetMouseButtonCallback(window, Window::mouseButtonCallback);
		glfwSetCursorPosCallback(window, Window::cursorPositionCallback);
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
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void Window::clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::close() {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	bool Window::isClosed() const {
		return glfwWindowShouldClose(window) == 1;
	}

	template<typename P>
	P *Window::getWindowPointer(int pointerID) {
		return getWindowPointer<P>(this->window, pointerID);
	}

	void Window::setWindowPointer(int pointerID, void *pointer) {
		setWindowPointer(this->window, pointerID, pointer);
	}

	void Window::registerInputListener(void *input) {
		setWindowPointer(VIVID_INPUT_POINTER, input);
	}

	void Window::setWindowPointer(GLFWwindow *window, int pointerID, void *pointer) {
		void **ptrList = (void **) glfwGetWindowUserPointer(window);
		ptrList[pointerID] = pointer;
	}

	template<typename P>
	P *Window::getWindowPointer(GLFWwindow *window, int pointerID) {
		P **ptrList = (P **) glfwGetWindowUserPointer(window);
		P *ptr = ptrList[pointerID];
		return ptr;
	}

	void Window::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
		auto win = getWindowPointer<Window>(window, VIVID_WINDOW_POINTER);
		if(win != nullptr) {
			win->width = width;
			win->height = height;
		}
		glViewport(0, 0, width, height);
	}

	void Window::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
		auto input = getWindowPointer<Input>(window, VIVID_INPUT_POINTER);
		if(input != nullptr)
			input->keyCallback(key, scancode, action, mods);
	}

	void Window::cursorPositionCallback(GLFWwindow *window, double xpos, double ypos) {
		auto input = getWindowPointer<Input>(window, VIVID_INPUT_POINTER);
		if(input != nullptr)
			input->cursorPositionCallback(xpos, ypos);
	}

	void Window::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
		auto input = getWindowPointer<Input>(window, VIVID_INPUT_POINTER);
		if(input != nullptr)
			input->mouseButtonCallback(button, action, mods);
	}

}}
