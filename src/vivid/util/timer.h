//
// Created by Ole on 04.09.2017.
//

#pragma once

#include <chrono>
#include <vivid/core.h>

namespace vivid {

	using clock = std::chrono::high_resolution_clock;

	class Timer {
	private:
		std::chrono::time_point<std::chrono::system_clock> last;
		std::chrono::time_point<std::chrono::system_clock> start;
	public:
		inline Timer()
				: last(clock::now()), start(clock::now()) {}

		inline void reset() {
			start = clock::now();
		}

		inline float elapsed() {
			auto now = clock::now();
			float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - last).count() / 1000000.0f;
			if(deltaTime != 0.0f)
				last = now;
			return deltaTime;
		}

		inline float time() {
			return std::chrono::duration_cast<std::chrono::microseconds>(clock::now() - start).count() / 1000000.0f;
		}

	};

}