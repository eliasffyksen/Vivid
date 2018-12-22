//
// Created by stroh on 21/12/2018.
//

#pragma once

#include <vector>
#include <vivid/scenegraph/layer.h>
#include <vivid/scenegraph/gameobject.h>
#include <vivid/input/input.h>

namespace vivid {

	struct SortedLayer {
		Layer layer;
		int priority; // higher means closer to screen

		SortedLayer() = default;
	};

	class Scene {
	private:
		std::vector<SortedLayer> layers;
	public:
		Scene() = default;
		virtual ~Scene() = default;

		Layer* createLayer(const int& priority);

		void update(const Input& input);
		void render();
	};

}
