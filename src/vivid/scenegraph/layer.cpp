//
// Created by Ole on 01.10.2017.
//

#include "layer.h"

namespace vivid { namespace graphics {
	
	Layer::Layer() {}
	
	void Layer::setRenderer(Renderer2D* renderer) {
		this->renderer = renderer;
	}
	
	void Layer::update() {
	
	}
	
	void Layer::render() {
		renderer->begin();
		root.renderObject(renderer);
		renderer->end();
		renderer->flush();
	}
	
	void Layer::addChild(GameObject& child) {
		root.addChild(child);
	}
	
	void Layer::removeChild(GameObject& child) {
		root.removeChild(child);
	}
	
}}
