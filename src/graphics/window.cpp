//
// Created by Ole on 29.08.2017.
//

#include "window.h"
#include <iostream>

namespace vivid {
    namespace graphics {

        Window::Window(const char *title, int width, int height) {
            this->title = title;
            this->width = width;
            this->height = height;

            if (!init())
                glfwTerminate();

            for (int i = 0; i < MAX_KEYS; i++)
                keys[i] = false;
            for (int i = 0; i < MAX_MOUSE_BUTTONS; i++)
                mouseButtons[i] = false;

        }

        bool Window::init() {
            if (!glfwInit()) {
                std::cout << "Failed to initialize GLFW." << std::endl;

                return false;
            }

            glfwWindowHint(GLFW_SAMPLES, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            window = glfwCreateWindow(width, height, title, NULL, NULL);
            if (!window) {
                glfwTerminate();
                std::cout << "Failed to create window..." << std::endl;
                return false;
            }

            glfwMakeContextCurrent(window);
            glfwSetWindowUserPointer(window, this);
            glfwSetFramebufferSizeCallback(window, Window::framebuffer_size_callback);
            glfwSetKeyCallback(window, Window::key_callback);

            return true;
        }

        Window::~Window() {
            glfwTerminate();
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

        void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
            Window *win = (Window *)glfwGetWindowUserPointer(window);
            win->width = width;
            win->height = height;

            glViewport(0, 0, width, height);
        }

        void Window::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
            Window *win = (Window *)glfwGetWindowUserPointer(window);
            if(action == GLFW_PRESS)
                win->keys[key] = true;
            else if(action == GLFW_RELEASE)
                win->keys[key] = false;
        }

    }
}