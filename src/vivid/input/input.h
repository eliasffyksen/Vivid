//
// Created by Elias on 05.09.2017.
//

#pragma once

#include "../vivid.h"

namespace vivid{
	class Input {

#define VIVID_MAX_KEYS 1024

	private:
		bool keys[VIVID_MAX_KEYS];


	public:
		Input(GLFWwindow*);

		bool getKey(int);

		static void keyCallback(GLFWwindow *, int, int, int, int);
	};
}




