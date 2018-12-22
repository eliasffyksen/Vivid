//
// Created by stroh on 16/12/2018.
//

#include "resource.h"

#include <fstream>

namespace vivid {

	std::string loadTextFile(std::string filePath) {
		std::string res;
		std::ifstream fileStream(filePath, std::ios::in);
		if (fileStream.is_open()) {
			std::string line;
			while (getline(fileStream, line))
				res += "\n" + line;

			fileStream.close();
		} else {
			LOGE("Could not open " << filePath);
			return "";
		}

		return res;
	}
}