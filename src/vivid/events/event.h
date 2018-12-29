//
// Created by stroh on 23/12/2018.
//

#pragma once

#include <string>
#include <functional>

namespace vivid { namespace event {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus,
		KeyPress, KeyRelease,
		MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll,
		EventCount
	};

#define EVENT_TYPE(x) public:\
inline static EventType getStaticEventType() { return EventType::x; }\
inline virtual EventType getEventType() override { return EventType::x; }\
inline virtual const char* getName() override { return #x; }

#define BIND(x) std::bind(&x, this, std::placeholders::_1)
//#define BIND(x, y) std::bind(&x, y, std::placeholders::_1)

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
		template<typename T>
		using EventFunction = std::function<bool(T&)>;
	public:

		inline EventDispatcher(Event &event)
				: event(event) {}

		template<typename T>
		inline bool dispatch(EventFunction<T> handle) {
			if (event.getEventType() == T::getStaticEventType()) {
				event.handled = handle((T &) event);
				return true;
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
