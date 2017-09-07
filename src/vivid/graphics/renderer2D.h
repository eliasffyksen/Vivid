//
// Created by Ole on 07.09.2017.
//

#pragma once

#include "renderable2D.h"

namespace vivid { namespace graphics {
	
	class Renderer2D {
	public:
		virtual void begin() {}
		virtual void submit(const Renderable2D*) = 0;
		virtual void end() {}
		virtual void flush() = 0;
	};
	
}}