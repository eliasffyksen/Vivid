//
// Created by stroh on 23/12/2018.
//

#pragma once

#include <string>
#include <functional>

namespace vivid { namespace event {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus,
		KeyPress, KeyRelease,
		MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll,
		EventCount
	};

#define EVENT_TYPE(x) inline static EventType getStaticEventType() { return EventType::x; }\
inline virtual EventType getEventType() override { return EventType::x; }\
inline virtual const char* getName() override { return #x; }

#define BIND(x) [](auto event) { return x(event); }

	class Event {
	public:
		virtual EventType getEventType() = 0;
		virtual const char *getName() = 0;
		virtual std::string toString() { return getName(); }
	protected:
		inline Event()
				: handled(false) {}
	public:
		bool handled;
	};

	class EventDispatcher {
	public:

		inline EventDispatcher(Event &event)
				: event(event) {}

		template<typename T>
		inline bool dispatch(bool (*func)(T &)) {
			if (event.getEventType() == T::getStaticEventType()) {
				event.handled = func((T &) event);
			}
			return false;
		}

	private:
		Event &event;
	};

	inline std::ostream &operator<<(std::ostream &o, Event &event) {
		o << event.toString();
		return o;
	}

}}
