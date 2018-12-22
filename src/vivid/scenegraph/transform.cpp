//
// Created by Ole on 07.10.2017.
//

#include "transform.h"


namespace vivid {
	
	Transform* Transform::setPosition(glm::vec3 position) {
		this->position = position;
		return this;
	}
	
	Transform* Transform::setRotation(glm::quat rotation) {
		this->rotation = rotation;
		return this;
	}
	
	Transform* Transform::setScale(glm::vec3 scale) {
		this->scale = scale;
		return this;
	}

}
