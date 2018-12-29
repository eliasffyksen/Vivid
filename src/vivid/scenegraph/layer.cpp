//
// Created by Ole on 01.10.2017.
//

#include "layer.h"

namespace vivid {

	Layer::Layer(graphics::Renderer2D *renderer)
			: renderer(renderer) {}

	vdm::mat4 Layer::getViewMatrix() {
		return currentCamera->getModelMatrix();
	}

	void Layer::update(const Input &input) {
		root.updateObject(input);
	}

	void Layer::render() {
		renderer->begin();
		root.renderObject(renderer);
		renderer->end();
		renderer->flush();
	}

	void Layer::addChild(GameObject &child) {
		root.addChild(child);
	}

	void Layer::removeChild(GameObject &child) {
		root.removeChild(child);
	}

}
