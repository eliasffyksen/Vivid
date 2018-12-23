//
// Created by stroh on 21/12/2018.
//

#include "scene.h"

namespace vivid {

	Layer* Scene::createLayer(graphics::Renderer2D* renderer, const int& priority) {
		auto* sortedLayer = new SortedLayer(renderer, priority);

		int index = 0;
		while(index < layers.size() && layers[index]->priority < priority) { // todo: binary search - gotta get that O(logn) insert boi
			index++;
		}
		layers.insert(layers.begin() + index, sortedLayer); // todo: this is probably O(n) :/
		return &(layers[index]->layer);
//        layers.push_back(sortedLayer);
//		return &(layers[layers.size()-1]->layer);
	}

	std::vector<SortedLayer*>& Scene::getLayers() {
		return layers;
	}

	void Scene::update(const Input& input) {
		for(SortedLayer* sortedLayer : layers) {
			sortedLayer->layer.update(input);
		}
	}

	void Scene::render() {
		for(SortedLayer* sortedLayer : layers) {
			sortedLayer->layer.render();
		}
	}

}