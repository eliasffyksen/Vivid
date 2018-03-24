//
// Created by Ole on 07.09.2017.
//

#pragma once

#include "glm/glm.hpp"

namespace vivid { namespace graphics {
	
	struct Vertex {
	public:
		glm::vec3 position;
		unsigned int color;
		glm::vec2 textureCoordinates;
	};
	
	class Renderable2D {
		glm::vec3 position;
		glm::vec2 size;
		glm::vec4 color;
	public:
		Renderable2D(float x, float y, float width, float height, const glm::vec4& color)
				: position(x, y, 0), size(width, height), color(color) {}
		
		Renderable2D(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
				: position(position), size(size), color(color) {}
		
		virtual ~Renderable2D() = default;
		
		inline glm::vec3& getPosition() const { return (glm::vec3&) position; }
		inline glm::vec2& getSize() const { return (glm::vec2&)  size; }
		inline glm::vec4& getColor() const { return (glm::vec4&)  color; }
	};
	
}}