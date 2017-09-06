//
// Created by Ole on 04.09.2017.
//

#pragma once

#include <chrono>
#include "../vivid.h"

namespace vivid {
	
	class Timer {
	private:
		std::chrono::high_resolution_clock timer;
		std::chrono::time_point<std::chrono::system_clock> start;
	public:
		Timer()
		: start(timer.now())
		{}
		
		void reset() {
			start = timer.now();
		}
		
		float elapsed() {
			auto current = timer.now();
			float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(current - start).count() / 1000000.0f;
			start = current;
			return deltaTime;
		}
		
		float time() {
			float dt = std::chrono::duration_cast<std::chrono::microseconds>(timer.now() - start).count() / 1000000.0f;
		}
		
	};
	
}