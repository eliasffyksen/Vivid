//
// Created by Ole on 17.09.2017.
//

#pragma once

#include <vector>
#include "../graphics/renderer2D.h"
#include "../input/input.h"
#include "transform.h"

namespace vivid { namespace graphics {
	
	class GameObject {
	protected:
		GameObject* parent = nullptr;
	private:
		std::vector<GameObject*> children;
		
		Transform transform;
	public:
		GameObject() = default;
		virtual ~GameObject() = default;
		
		virtual void addChild(GameObject& child) final;
		virtual void removeChild(GameObject& child) final;
		
		virtual void updateObject(const Input& input) final;
		virtual void renderObject(Renderer2D* renderer) final;
		
		virtual const glm::mat4& getModelMatrix() final;
	private:
		virtual void update(const Input& input) {}
		virtual void render(const Renderer2D* renderer) {}
		
		GameObject(GameObject& other) {}
		void operator=(GameObject& other) {}
	};
	
}}

