//
// Created by stroh on 24/12/2018.
//

#pragma once

#include <vivid/core.h>
#include <vivid/graphics/window.h>
#include <vivid/input/input.h>

#include <string>
#include <vivid/events/windowEvent.h>

namespace vivid {

	class VividApplication {
	public:
		VividApplication(const std::string& title, const int &width, const int &height);
		~VividApplication();

		void start();
		bool isRunning();

		graphics::Window& getWindow();
		Input& getInput();
	private:
		void handleEvent(event::Event& event);

		bool windowCloseCallback(event::WindowCloseEvent &event);
		bool windowResizeCallback(event::WindowResizeEvent &event);
	private:
		bool running;
		graphics::Window window;
		Input input;
	};

}
