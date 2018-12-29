//
// Created by Ole on 01.10.2017.
//

#pragma once

#include <vivid/scenegraph/gameobject.h>
#include <vivid/scenegraph/camera.h>
#include <vivid/util/maths.h>

namespace vivid {

	class Layer {
	private:
		GameObject root;
		graphics::Renderer2D *renderer;
		Camera *currentCamera;
	public:
		Layer(graphics::Renderer2D *renderer);

		vdm::mat4 getViewMatrix();

		void update(const Input &input);

		void render();

		void addChild(GameObject &child);

		void removeChild(GameObject &child);
	};

}
