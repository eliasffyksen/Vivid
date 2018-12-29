//
// Created by Ole on 17.09.2017.
//

#include "gameobject.h"
#include <algorithm>
#include <iostream>

namespace vivid {

	void GameObject::addChild(GameObject &child) {
		if (std::find(children.begin(), children.end(), &child) == children.end()) {
			children.push_back(&child);
			child.parent = this;
		}
	}

	void GameObject::removeChild(GameObject &child) {
		auto it = std::find(children.begin(), children.end(), &child);
		if (it != children.end()) {
			children.erase(it);
			child.parent = 0;
		}
	}

	void GameObject::updateObject(const Input &input) {
		update(input);

		for (int i = 0; i < children.size(); i++)
			children[i]->updateObject(input);
	}

	void GameObject::renderObject(graphics::Renderer2D *renderer) {
		renderer->pushMatrix(transform.getModelMatrix());

		render(renderer);

		for (int i = 0; i < children.size(); i++)
			children[i]->renderObject(renderer);

		renderer->popMatrix();
	}

	const vdm::mat4 GameObject::getModelMatrix() {
		if (parent == nullptr) {
			return parent->getModelMatrix() * transform.getModelMatrix();
		} else {
			return transform.getModelMatrix();
		}
	}

}