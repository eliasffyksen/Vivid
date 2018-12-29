//
// Created by Ole on 07.10.2017.
//

#pragma once

#include <vivid/util/maths.h>

namespace vivid {

	class Transform {
	private:
		vdm::vec3 position;
		vdm::quat rotation;
		vdm::vec3 scale;
	public:
		Transform()
				: position(0.0f, 0.0f, 0.0f), rotation(vdm::quat()), scale(1.0f, 1.0f, 1.0f) {}

		Transform *setPosition(vdm::vec3 position);
		Transform *setRotation(vdm::quat rotation);
		Transform *setScale(vdm::vec3 scale);

		inline vdm::vec3 &getPosition() { return position; }
		inline vdm::quat &getRotation() { return rotation; }
		inline vdm::vec3 &getScale() { return scale; }

		inline const vdm::mat4 getModelMatrix() {
			return vdm::mat4::translation(position) * vdm::mat4::rotation(rotation) * vdm::mat4::scale(scale);
		}
	};

}
