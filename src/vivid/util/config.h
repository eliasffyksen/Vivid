//
// Created by Elias on 31.08.2017.
//

#pragma once

#define VIVID_VERSION_MAJOR 0
#define VIVID_VERSION_MINOR 1
#define VIVID_DEBUG true
#define VIVID_PLATFORM WIN64
#define VIVID_OPENGL

#if VIVID_DEBUG
	#include <iostream>
	#define LOG(x) std::cout << x << std::endl
	#define LOGE(x) std::cerr << x << std::endl
#else
	#define LOG(x)
	#define LOGE(x)
#endif
