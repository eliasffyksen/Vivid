//
// Created by Ole on 29.08.2017.
//

#pragma once

#include <unordered_map>
#include <string>
#include <iostream>

#include "../vivid.h"
#include "../../config.h"

namespace vivid { namespace graphics {
	
	class Window {
	public:
		GLFWwindow* window;
	private:
		const char* title;
		int width, height;
	public:
		Window(const char* name, int width, int height);
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
