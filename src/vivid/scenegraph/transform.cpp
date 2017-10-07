//
// Created by Ole on 07.10.2017.
//

#include "transform.h"


namespace vivid { namespace graphics {
	
	void Transform::updateModelMatrix(Transform* parent) {
		if(parent != nullptr)
			modelMatrix = parent->getModelMatrix() * glm::translate(position) * glm::toMat4(rotation) * glm::scale(scale);
		else
			modelMatrix = glm::translate(position) * glm::toMat4(rotation) * glm::scale(scale);
			
	}
	
}}
