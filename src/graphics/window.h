//
// Created by Ole on 29.08.2017.
//

#ifndef GLTEST_WINDOW_H
#define GLTEST_WINDOW_H

#include <GLFW/glfw3.h>


namespace vivid {
	namespace graphics {

		class Window {
		private:
			const char *title;
			int width, height;

			GLFWwindow *window;
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
		};

	}
}

#endif //GLTEST_WINDOW_H
