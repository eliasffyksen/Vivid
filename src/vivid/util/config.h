//
// Created by Elias on 31.08.2017.
//

#pragma once

#define VIVID_POINTER_MAX 16

#define VIVID_WINDOW_POINTER 0
#define VIVID_INPUT_POINTER 1

#define VIVID_VERSION_MAJOR 0
#define VIVID_VERSION_MINOR 1
#define VIVID_DEBUG true
#define VIVID_PLATFORM WIN64
#define VIVID_OPENGL

#if VIVID_DEBUG
	#include <iostream>
	#define LOG(x) std::cout << x << std::endl
	#define LOGE(x) std::cerr << x << std::endl
	#define ASSERT(x) if(!(x)) __debugbreak()
#else
	#define LOG(x)
	#define LOGE(x)
	#define ASSERT(x)
#endif

#if VIVID_BUILD
	#define VIVID_API __declspec(dllexport)
#else
	#define VIVID_API __declspec(dllimport)
#endif
