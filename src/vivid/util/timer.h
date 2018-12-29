//
// Created by Ole on 04.09.2017.
//

#pragma once

#include <chrono>
#include <vivid/core.h>

namespace vivid {

	class Timer {
	private:
		std::chrono::high_resolution_clock timer;
		std::chrono::time_point<std::chrono::system_clock> last;
		std::chrono::time_point<std::chrono::system_clock> start;
	public:
		Timer()
				: last(timer.now()), start(timer.now()) {}

		void reset() {
			start = timer.now();
		}

		double elapsed() {
			auto now = timer.now();
			double deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - last).count() / 1000000.0;
			last = now;
			return deltaTime;
		}

		double time() {
			return std::chrono::duration_cast<std::chrono::microseconds>(timer.now() - start).count() / 1000000.0;
		}

	};

}