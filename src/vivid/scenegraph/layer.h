//
// Created by Ole on 01.10.2017.
//

#pragma once

#include "gameobject.h"

namespace vivid { namespace graphics {
	
	class Layer {
	private:
		GameObject root;
		Renderer2D* renderer;
	public:
		Layer();
		
		void setRenderer(Renderer2D* renderer);
		
		void update();
		void render();
		
		void addChild(GameObject& child);
		void removeChild(GameObject& child);
	};
	
}}
