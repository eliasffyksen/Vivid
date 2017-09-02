//
// Created by Ole on 29.08.2017.
//

#ifndef GLTEST_WINDOW_H
#define GLTEST_WINDOW_H

#include <GLFW/glfw3.h>
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

            bool keys[MAX_KEYS];
            bool mouseButtons[MAX_MOUSE_BUTTONS];
            double mouseX, mouseY;
        public:
            Window(const char *name, int width, int height);

            ~Window();

            void update();
            void clear() const;

            bool isClosed() const;
            bool isKeyPressed(int key) const;
            bool isMouseButtonPressed(int button) const;

            void getCursorPosition(double &x, double &y) const;

            inline int getWidth() const { return width; }
            inline int getHeight() const { return height; }

        private:
            bool init();

            static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
            static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
            static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
            static void cursorPositionCallback(GLFWwindow *window, double xpos, double ypos);
        };

    }
}

#endif //GLTEST_WINDOW_H
