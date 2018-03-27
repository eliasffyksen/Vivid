//
// Created by Ole on 07.10.2017.
//

#pragma once

#include "glm/gtx/transform.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/glm.hpp"

namespace vivid { namespace graphics {
	
	class Transform {
	private:
		glm::vec3 position;
		glm::quat rotation;
		glm::vec3 scale;
	public:
		Transform()
				: position(glm::vec3()), rotation(glm::quat()), scale(glm::vec3()) {}
		
		Transform* setPosition(glm::vec3 position);
		Transform* setRotation(glm::quat rotation);
		Transform* setScale(glm::vec3 scale);
		
		inline glm::vec3& getPosition() { return position; }
		inline glm::quat& getRotation() { return rotation; }
		inline glm::vec3& getScale() { return scale; }
		
		inline const glm::mat4 getModelMatrix() { return glm::translate(position) * glm::toMat4(rotation) * glm::scale(scale); }
	};
	
}}
