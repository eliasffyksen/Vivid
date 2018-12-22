//
// Created by stroh on 15/12/2018.
//

#pragma once

#include "vivid/vivid.h"


namespace vivid { namespace maths {

	class vec2;

	class vec3;

	class vec4;

	class quat;

	class mat4;

	class vec2 {
	public:
		union {
			struct { float x, y; };
			struct { float u, v; };
			struct { float m[2]; };
		};

		vec2();

		vec2(const float &x, const float &y);

		vec2(const vec2 &other) = default;

		float length();
		vec2 &normalize();

		float dot(const vec2 &right);
		vec2 &rotate(float angle);

		vec2 &add(const vec2 &right);
		vec2 &sub(const vec2 &right);
		vec2 &mul(const vec2 &right);
		vec2 &div(const vec2 &right);
	};

	class vec3 {
	public:
		union {
			struct { float x, y, z; };
			struct { float r, g, b; };
			struct { float m[3]; };
		};

		vec3();

		vec3(const float &x, const float &y, const float &z);

		vec3(const vec3 &other) = default;

		vec2 xy() { return vec2(x, y); }

		float length();
		vec3 &normalize();

		float dot(const vec3 &right);
		vec3 cross(const vec3 &right);

		vec3 &rotate(const quat &q);

		vec3 &add(const vec3 &right);
		vec3 &sub(const vec3 &right);
		vec3 &mul(const vec3 &right);
		vec3 &div(const vec3 &right);
	};

	class vec4 {
	public:
		union {
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
			struct { float m[4]; };
		};

		vec4();

		vec4(const float &x, const float &y, const float &z, const float &w);

		vec4(const vec3 &other, float w);

		vec4(const vec4 &other) = default;

		vec3 xyz() { return vec3(x, y, z); }

		float length();
		vec4 &normalize();

		float dot(const vec4 &right);

		vec4 &add(const vec4 &right);
		vec4 &sub(const vec4 &right);
		vec4 &mul(const vec4 &right);
		vec4 &div(const vec4 &right);
	};

	class quat {
	public:
		float w, x, y, z;

		quat();
		quat(const float &w, const float &x, const float &y, const float &z);
		quat(const float &angle, vec3 axis);
		quat(const quat &other) = default;

		float length() const;
		quat &normalize();
		quat conjugate() const;

		quat mul(const quat &right) const;
		quat mul(const vec3 &vec) const;
	};

	class mat4 {
	public:
		union {
			float m[16];
			vec4 r[4];
		};

		explicit mat4(const float &d = 1);
		mat4(const mat4 &other) = default;

		mat4 transpose();

		mat4 mul(const mat4 &right) const;
		vec4 mul(const vec4 &vec) const;
		vec4 mul(const vec3 &vec, const float& w) const;
	public:
		static mat4 translation(const vec3 &translation);
		static mat4 rotation(const quat &rotation);
		static mat4 scale(const vec3 &scale);

	public:

	};

	std::ostream &operator<<(std::ostream &o, const vec2 &vec);
	std::ostream &operator<<(std::ostream &o, const vec3 &vec);
	std::ostream &operator<<(std::ostream &o, const vec4 &vec);
	std::ostream &operator<<(std::ostream &o, const quat &q);

}}