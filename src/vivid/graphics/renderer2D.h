//
// Created by Ole on 07.09.2017.
//

#pragma once

#include <vector>
#include <vivid/util/maths.h>
#include "quad.h"

namespace vivid { namespace graphics {

	class Renderer2D {
	private:
		mutable std::vector<vdm::mat4> transformationStack;
	protected:
		mutable vdm::mat4 currentTransformation;
	public:
		Renderer2D() {
			transformationStack.emplace_back(vdm::mat4());
			currentTransformation = transformationStack.back();
		}

		virtual void pushMatrix(const vdm::mat4 &matrix) final {
			currentTransformation = currentTransformation * matrix;
			transformationStack.push_back(currentTransformation);
		}

		virtual void popMatrix() final {
			if (transformationStack.size() > 1) {
				transformationStack.pop_back();
				currentTransformation = transformationStack.back();
			}
		}

		virtual void begin() {}
		virtual void submit(const Quad *) const = 0;
		virtual void end() {}
		virtual void flush() = 0;
	};

}}