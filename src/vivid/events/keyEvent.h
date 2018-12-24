//
// Created by stroh on 24/12/2018.
//

#pragma once

#include <vivid/events/event.h>
#include <sstream>

namespace vivid { namespace event {

	class KeyPressEvent : public Event {
	public:
		EVENT_TYPE(KeyPress);

		inline KeyPressEvent(int key, int repeats)
				: key(key), repeats(repeats) {}

		inline virtual std::string toString() override {
			std::stringstream ss;
			ss << "[" << getName() << "Event] " << key << " (" << repeats << ")";
			return ss.str();
		}
	public:
		int key;
		int repeats;
	};

	class KeyReleaseEvent : public Event {
	public:
		EVENT_TYPE(KeyRelease);

		inline KeyReleaseEvent(int key)
				: key(key) {}

		inline virtual std::string toString() override {
			std::stringstream ss;
			ss << "[" << getName() << "Event] " << key;
			return ss.str();
		}
	public:
		int key;
	};

}}
