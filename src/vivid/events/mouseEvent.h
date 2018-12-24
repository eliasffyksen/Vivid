//
// Created by stroh on 24/12/2018.
//

#pragma once

#include <vivid/events/event.h>
#include <sstream>

namespace vivid { namespace event {

	class MouseMoveEvent : public Event {
	public:
		EVENT_TYPE(MouseMove)

		inline MouseMoveEvent(float xPos, float yPos)
				: xPos(xPos), yPos(yPos) {}

		inline std::string toString() {
			std::stringstream ss;
			ss << "[" << getName() << "Event] " << xPos << ", " << yPos;
			return ss.str();
		}
	public:
		double xPos;
		double yPos;
	};

	class MouseButtonPressEvent : public Event {
	public:
		EVENT_TYPE(MouseButtonPress)

		inline MouseButtonPressEvent(int button)
				: button(button) {}

		inline std::string toString() {
			std::stringstream ss;
			ss << "[" << getName() << "Event] " << button;
			return ss.str();
		}
	public:
		int button;
	};

	class MouseButtonReleaseEvent : public Event {
	public:
		EVENT_TYPE(MouseButtonRelease)

		inline MouseButtonReleaseEvent(int button)
				: button(button) {}

		inline std::string toString() {
			std::stringstream ss;
			ss << "[" << getName() << "Event] " << button;
			return ss.str();
		}
	public:
		int button;
	};

	class MouseScrollEvent : public Event {
		EVENT_TYPE(MouseScroll)

		inline MouseScrollEvent(float xOffset, float yOffset)
				: xPos(xOffset), yPos(yOffset) {}

		inline std::string toString() {
			std::stringstream ss;
			ss << "[" << getName() << "Event] " << xPos << ", " << yPos;
			return ss.str();
		}
	public:
		double xPos;
		double yPos;
	};

}}
