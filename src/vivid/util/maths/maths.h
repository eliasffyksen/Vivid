//
// Created by stroh on 15/12/2018.
//

#pragma once

#include "../../vivid.h"


namespace vivid { namespace maths {

	class vec2 {
	public:
		union {
			struct { float x, y; };
			struct { float u, v; };
			struct { float m[2]; };
		};

		vec2()
				: x(0), y(0) {}

		vec2(float x, float y)
				: x(x), y(y) {}

		vec2(const vec2 &other) = default;

		float length();

		vec2 add(const vec2 &right);

		vec2 sub(const vec2 &right);

		vec2 mul(const vec2 &right);

		vec2 div(const vec2 &right);
	};

	class vec3 {
	public:
		union {
			struct { float x, y, z; };
			struct { float r, g, b; };
			struct { float m[3]; };
		};

		vec3()
				: x(0), y(0), z(0) {}

		vec3(float x, float y, float z)
				: x(x), y(y), z(z) {}

		vec3(const vec3 &other) = default;

		vec2 xy() { return vec2(x, y); }

		float length();

		vec3 add(const vec3 &right);

		vec3 sub(const vec3 &right);

		vec3 mul(const vec3 &right);

		vec3 div(const vec3 &right);
	};

	class vec4 {
	public:
		union {
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
			struct { float m[4]; };
		};

		vec4()
				: x(0), y(0), z(0), w(0) {}

		vec4(float x, float y, float z, float w)
				: x(x), y(y), z(z), w(w) {}

		vec4(const vec3 &other, float w)
				: x(other.x), y(other.y), z(other.z), w(w) {}

		vec4(const vec4 &other) = default;

		vec3 xyz() { return vec3(x, y, z); }

		float length();

		vec4 add(const vec4 &right);

		vec4 sub(const vec4 &right);

		vec4 mul(const vec4 &right);

		vec4 div(const vec4 &right);
	};

	class mat4 {
	public:
		union {
			float m[16];
			vec4 r[4];
		};

		explicit mat4(float d = 1);

		mat4(const mat4 &other) = default;

		mat4 mul(const mat4 &right);

		vec4 mul(const vec4 &vec);
	};

	std::ostream &operator<<(std::ostream &o, const vec4 &vec);

}}