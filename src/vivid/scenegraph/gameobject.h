//
// Created by Ole on 17.09.2017.
//

#pragma once

#include <vector>
#include <vivid/graphics/renderer2D.h>
#include <vivid/input/input.h>
#include <vivid/util/maths.h>
#include "transform.h"

namespace vivid {

	class GameObject {
	protected:
		GameObject *parent = nullptr;
	private:
		std::vector<GameObject *> children;

		Transform transform;
	public:
		GameObject() = default;

		virtual ~GameObject() = default;

		virtual void addChild(GameObject &child) final;

		virtual void removeChild(GameObject &child) final;

		virtual void updateObject(const Input &input) final;

		virtual void renderObject(graphics::Renderer2D *renderer) final;

		inline Transform &getTransform() {
			return transform;
		}

		virtual const vdm::mat4 getModelMatrix() final;

	public:
		virtual void update(const Input &input) {}

		virtual void render(const graphics::Renderer2D *renderer) {}
	};

}

