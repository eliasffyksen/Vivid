//
// Created by stroh on 21/12/2018.
//

#include "scene.h"

namespace vivid {

	Layer* Scene::createLayer(const int& priority) {
		SortedLayer sortedLayer;

		int index = 0;
		while(index < layers.size() && layers[index].priority < priority) { // todo: binary search - gotta get that O(logn) insert boi
			index++;
		}
		layers.push_back(sortedLayer);
//			layers.insert(layers.begin() + index, sortedLayer); // todo: this is probably O(n) :/
		return &(layers[index].layer);
	}

	void Scene::update(const Input& input) {
		for(SortedLayer& sortedLayer : layers) {
			sortedLayer.layer.update(input);
		}
	}

	void Scene::render() {
		for(SortedLayer& sortedLayer : layers) {
			sortedLayer.layer.render();
		}
	}

}