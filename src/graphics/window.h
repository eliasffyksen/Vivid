//
// Created by Ole on 29.08.2017.
//

#ifndef GLTEST_WINDOW_H
#define GLTEST_WINDOW_H

#include <GLFW/glfw3.h>


namespace vivid {
	namespace graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

		class Window {
		private:
			const char *title;
			int width, height;

            GLFWwindow* window;

            static bool keys[MAX_KEYS];
            static bool buttons[MAX_BUTTONS];
            static double mouseX, mouseY;
		public:
			Window(const char *name, int width, int height);
			~Window();

			void update();
			void clear() const;
			bool isClosed() const;

			inline int getWidth() const { return width; }
			inline int getHeight() const { return height; }

		private:
			bool init();
            static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
            static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		};

	}
}

#endif //GLTEST_WINDOW_H
