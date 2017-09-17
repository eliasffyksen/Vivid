//
// Created by Ole on 17.09.2017.
//

#include "gameobject.h"
#include <algorithm>
#include <iostream>

namespace vivid { namespace graphics {
	
	void GameObject::addChild(GameObject& child) {
		if(std::find(children.begin(), children.end(), &child) != children.end())
			children.push_back(&child);
	}
	
	void GameObject::removeChild(GameObject& child) {
		auto it = std::find(children.begin(), children.end(), &child);
		if(it != children.end())
			children.erase(it);
	}
	
	void GameObject::updateObject(const Input& input) {
		update(input);
		
		for(int i = 0; i < children.size(); i++)
			children[i]->updateObject(input);
	}
	
	void GameObject::renderObject(const Renderer2D& renderer) {
		//push matrix
		
		render(renderer);
		
		for(int i = 0; i < children.size(); i++)
			children[i]->renderObject(renderer);
		
		//pop matrix
	}
	
}}