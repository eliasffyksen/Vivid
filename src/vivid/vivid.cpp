//
// Created by stroh on 24/12/2018.
//

#include "vivid.h"

#include <functional>

namespace vivid {

	bool VividApplication::windowCloseCallback(event::WindowCloseEvent &event) {
		running = false;

		return true;
	}

	bool VividApplication::windowResizeCallback(event::WindowResizeEvent &event) {
		input.setFrameSize(event.width, event.height);
		glViewport(0, 0, event.width, event.height);

		return true;
	}

	void VividApplication::handleEvent(event::Event& event) {
		event::EventDispatcher dispatcher(event);
		bool res = false;
		res = res |	dispatcher.dispatch<event::WindowCloseEvent>(BIND(VividApplication::windowCloseCallback));
		res = res |	dispatcher.dispatch<event::WindowResizeEvent>(BIND(VividApplication::windowResizeCallback));

		res = res |	dispatcher.dispatch<event::KeyPressEvent>(std::bind(&Input::keyPressCallback, &input, std::placeholders::_1));
		res = res |	dispatcher.dispatch<event::KeyReleaseEvent>(std::bind(&Input::keyReleaseCallback, &input, std::placeholders::_1));
		res = res |	dispatcher.dispatch<event::MouseMoveEvent>(std::bind(&Input::mouseMoveCallback, &input, std::placeholders::_1));
		res = res |	dispatcher.dispatch<event::MouseButtonPressEvent>(std::bind(&Input::mouseButtonPressCallback, &input, std::placeholders::_1));
		res = res |	dispatcher.dispatch<event::MouseButtonReleaseEvent>(std::bind(&Input::mouseButtonReleaseCallback, &input, std::placeholders::_1));
		res = res |	dispatcher.dispatch<event::MouseScrollEvent>(std::bind(&Input::mouseScrollCallback, &input, std::placeholders::_1));

		if(!res)
			LOG("[Warning] Unhandled event: " << event);
	}

	VividApplication::VividApplication(const std::string& title, const int &width = 1280, const int &height = 720)
			: running(false), window(title, width, height) {
		window.setEventCallback(BIND(VividApplication::handleEvent));
		input.setFrameSize(width, height);
	}

	VividApplication::~VividApplication() = default;

	void VividApplication::start() {
		running = true;
	}

	bool VividApplication::isRunning() {
		return running;
	}

	graphics::Window& VividApplication::getWindow() {
		return window;
	}

	Input& VividApplication::getInput() {
		return input;
	}

}
