//
// Created by Ole on 29.08.2017.
//

#ifndef GLTEST_WINDOW_H
#define GLTEST_WINDOW_H

#include <GLFW/glfw3.h>


namespace vivid {
	namespace graphics {

#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 32

		class Window {
		private:
			const char *title;
			int width, height;

            GLFWwindow* window;

            bool keys[MAX_KEYS];
            bool mouseButtons[MAX_MOUSE_BUTTONS];
            double mouseX, mouseY;
		public:
			Window(const char *name, int width, int height);
			~Window();

			void update();
			void clear() const;
			bool isClosed() const;

            inline bool isKeyPressed(int key){ if(key < MAX_KEYS && key > 0) return keys[key];}
			inline bool isMouseButtonPressed(int button){ if(button < MAX_MOUSE_BUTTONS && button > 0) return mouseButtons[button];}

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
