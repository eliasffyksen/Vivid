//
// Created by stroh on 24/12/2018.
//

#pragma once

#include <vivid/events/event.h>
#include <sstream>

namespace vivid { namespace event {

	class WindowResizeEvent : public Event {
	public:
		EVENT_TYPE(WindowResize)

		inline WindowResizeEvent(int width, int height)
				: width(width), height(height) {}

		inline virtual std::string toString() override {
			std::stringstream ss;
			ss << "[" << getName() << "Event] " << width << ", " << height;
			return ss.str();
		}

	public:
		int width;
		int height;
	};

	class WindowCloseEvent : public Event {
	public:
		EVENT_TYPE(WindowClose)

		inline virtual std::string toString() override {
			std::stringstream ss;
			ss << "[" << getName() << "Event] Closing Window";
			return ss.str();
		}

		inline WindowCloseEvent() = default;
	};

}}
