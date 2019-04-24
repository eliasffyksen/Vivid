//
// Created by Ole on 07.09.2017.
//

#pragma once

#include <vivid/util/maths.h>
#include <vivid/scenegraph/textureatlas.h>

namespace vivid { namespace graphics {

	struct Vertex {
	public:
		vdm::vec3 position;
		vdm::vec2 textureCoordinates;
	};

	class Quad {
	private:
		vdm::vec3 position;
		vdm::vec2 size;
		TextureHandle* handle;
	public:
		Quad(float x, float y, float width, float height, TextureHandle *handle)
				: position(x, y, 0), size(width, height), handle(handle) {}

		Quad(float x, float y, float width, float height)
				: position(x, y, 0), size(width, height), handle(0) {}

		Quad(const vdm::vec3 &position, const vdm::vec2 &size, TextureHandle *handle)
				: position(position), size(size), handle(handle) {}

		Quad(const vdm::vec3 &position, const vdm::vec2 &size)
				: position(position), size(size), handle(0) {}

		virtual ~Quad() = default;

		inline vdm::vec3 &getPosition() const { return (vdm::vec3 &) position; }
		inline vdm::vec2 &getSize() const { return (vdm::vec2 &) size; }
		inline TextureHandle *getTextureHandle() const { return handle; }
	};

}}