//
// Created by Ole on 29.08.2017.
//

#pragma once

#include <string>
#include <iostream>

#include "../vivid.h"

namespace vivid { namespace graphics {
	
	class Window {
	public:
		GLFWwindow* window;
	private:
		std::string title;
		int width, height;
	public:
		Window(std::string title, int width, int height);
		~Window();
		
		void update();
		void clear() const;
		bool isClosed() const;
		
		inline int getWidth() const { return width; }
		inline int getHeight() const { return height; }
	private:
		bool init();
		
		static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	};
	
}}
