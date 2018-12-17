//
// Created by Ole on 17.09.2017.
//

#pragma once

#include <glm/glm.hpp>
#include "gameobject.h"

namespace vivid { namespace graphics {
	
	class Camera : public GameObject {};

	Camera* currentCamera;

	glm::mat4 getViewMatrix() {
		return currentCamera->getModelMatrix();
	}

}}


