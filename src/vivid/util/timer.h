//
// Created by Ole on 04.09.2017.
//

#pragma once

#include <Windows.h>

namespace vivid {
	
	class Timer {
	private:
		LARGE_INTEGER start;
		double frequency;
	public:
		Timer() {
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			this->frequency = 1.0 / frequency.QuadPart;
			QueryPerformanceCounter(&start);
		}
		
		void reset() {
			QueryPerformanceCounter(&start);
		}
		
		float elapsed() {
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned __int64 cycles = current.QuadPart - start.QuadPart;
			start = current;
			return (float) (cycles * frequency);
					}
		
		float time() {
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned __int64 cycles = current.QuadPart - start.QuadPart;
			return (float) (cycles * frequency);
		}
		
	};
	
}