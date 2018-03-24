//
// Created by Elias on 31.08.2017.
//

#pragma once

#define VERSION_MAJOR 0
#define VERSION_MINOR 1
#define DEBUG false
#define PLATFORM WIN64

#if DEBUG
	#define LOG(x) std::cout << x << std::endl
	#define LOGE(x) std::cerr << x << std::endl
#else
	#define LOG(x)
	#define LOGE(x)
#endif
