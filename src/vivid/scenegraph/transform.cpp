//
// Created by Ole on 07.10.2017.
//

#include "transform.h"

namespace vivid {

	Transform *Transform::setPosition(vdm::vec3 position) {
		this->position = position;
		return this;
	}

	Transform *Transform::setRotation(vdm::quat rotation) {
		this->rotation = rotation;
		return this;
	}

	Transform *Transform::setScale(vdm::vec3 scale) {
		this->scale = scale;
		return this;
	}

}
