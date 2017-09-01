//
// Created by Elias on 31.08.2017.
//

#ifndef CONFIG_H
#define CONFIG_H

#define VERSION_MAJOR 0
#define VERSION_MINOR 2
#define DEBUG false
#define PLATFORM WIN64

#if DEBUG
	#define LOG(x) std::cout << x  << std::endl
#else
	#define LOG(x)
#endif

#endif
