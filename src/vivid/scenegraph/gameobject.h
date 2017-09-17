//
// Created by Ole on 17.09.2017.
//

#pragma once


#include <vector>
#include "../graphics/renderer2D.h"
#include "../input/input.h"
#include "glm/gtx/quaternion.hpp"

namespace vivid { namespace graphics {
	
	class GameObject {
	private:
		std::vector<GameObject*> children;
		
		glm::vec3 position;
		glm::quat rotation;
		glm::vec3 scale;
		glm::mat4 modelMatrix;
	public:
		GameObject() = default;
		virtual ~GameObject() = default;
		
		virtual void addChild(GameObject& child) final;
		virtual void removeChild(GameObject& child) final;
		
		virtual void updateObject(const Input& input) final;
		virtual void renderObject(Renderer2D& renderer) final;
		
		virtual void update(const Input& input) {}
		virtual void render(const Renderer2D& renderer) {}
		
		virtual const glm::mat4& getModelMatrix() final;
	private:
		GameObject(GameObject& other) {}
		void operator=(GameObject& other) {}
		
		void updateModelMatrix();
	};
	
}}

