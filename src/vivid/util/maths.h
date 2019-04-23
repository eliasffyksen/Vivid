//
// Created by stroh on 15/12/2018.
//

#pragma once

#include "vivid/core.h"
#include <cmath>

#define VD_E        2.7182818284590452354f
#define VD_LOG2E    1.4426950408889634074f
#define VD_LOG10E   0.43429448190325182765f
#define VD_LN2      0.69314718055994530942f
#define VD_LN10     2.30258509299404568402f
#define VD_PI       3.14159265358979323846f
#define VD_PI_2     1.57079632679489661923f
#define VD_PI_4     0.78539816339744830962f
#define VD_1_PI     0.31830988618379067154f
#define VD_2_PI     0.63661977236758134308f
#define VD_2_SQRTPI 1.12837916709551257390f
#define VD_SQRT2    1.41421356237309504880f
#define VD_SQRT1_2  0.70710678118654752440f

namespace vivid { namespace vdm {

	class vec2;
	class vec3;
	class vec4;
	class quat;
	class mat4;

	float clamp(const float& value, float min, float max);
	float angle(const quat& q0, const quat& q1);

	vec2 lerp(const vec2 &v0, const vec2 &v1, const float &t);
	vec3 lerp(const vec3 &v0, const vec3 &v1, const float &t);
	vec4 lerp(const vec4 &v0, const vec4 &v1, const float &t);
	quat lerp(quat q0, quat q1, const float &t);
	quat slerp(quat q0, quat q1, float t);

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
		vec2 &mul(const float &multiplier);
		vec2 &div(const vec2 &right);
		vec2 &div(const float &multiplier);
	};

	class vec3 {
	public:
		union {
			struct { float x, y, z; };
			struct { float r, g, b; };
			struct { float m[3]; };
		};

		vec3();
		vec3(const float &v);
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
		vec3 &mul(const float &multiplier);
		vec3 &div(const vec3 &right);
		vec3 &div(const float &multiplier);
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
		vec4 &mul(const float &multiplier);
		vec4 &div(const vec4 &right);
		vec4 &div(const float &multiplier);
	};

	class quat {
	public:
		float w, x, y, z;

		quat();
		quat(const float &w, const float &x, const float &y, const float &z);
		quat(const float &angle, vec3 axis);
		quat(const quat &other) = default;

		float length() const;
		float dot(const quat& q) const;
		float angle(const quat& other) const;

		quat &normalize();
		quat conjugate() const;

		quat &add(const quat &right);
		quat &mul(const quat &right);
		quat mul(const vec3 &vec) const;
		quat &mul(const float &multiplier);
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
		vec4 mul(const vec3 &vec, const float &w) const;
	public:
		static mat4 translation(const vec3 &translation);
		static mat4 rotation(const quat &rotation);
		static mat4 scale(const vec3 &scale);

	public:

	};

	vec2 &operator+=(vec2 &left, const vec2 &right);
	vec3 &operator+=(vec3 &left, const vec3 &right);
	vec4 &operator+=(vec4 &left, const vec4 &right);
	quat &operator+=(quat &left, const quat &right);

	vec2 operator+(const vec2 &left, const vec2 &right);
	vec3 operator+(const vec3 &left, const vec3 &right);
	vec4 operator+(const vec4 &left, const vec4 &right);
	quat operator+(const quat &left, const quat &right);

	vec2 &operator-=(vec2 &left, const vec2 &right);
	vec3 &operator-=(vec3 &left, const vec3 &right);
	vec4 &operator-=(vec4 &left, const vec4 &right);
	quat &operator-=(quat &left, const quat &right);

	vec2 operator-(const vec2 &left, const vec2 &right);
	vec3 operator-(const vec3 &left, const vec3 &right);
	vec4 operator-(const vec4 &left, const vec4 &right);

	vec2 operator-(const vec2 &vec);
	vec3 operator-(const vec3 &vec);
	vec4 operator-(const vec4 &vec);
	quat operator-(const quat &q);

	vec2 operator*(const float &left, const vec2 &right);
	vec3 operator*(const float &left, const vec3 &right);
	vec4 operator*(const float &left, const vec4 &right);
	quat operator*(const quat &left, const quat &right);
	quat operator*(const float &left, const quat &right);
	mat4 operator*(const mat4 &left, const mat4 &right);

	vec2 operator*(const vec2 &left, const float &right);
	vec3 operator*(const vec3 &left, const float &right);
	vec4 operator*(const vec4 &left, const float &right);
	quat operator*(const quat &left, const float &right);
	vec4 operator*(const mat4 &left, const vec4 &right);

	vec2 &operator*=(vec2 &left, const float &right);
	vec3 &operator*=(vec3 &left, const float &right);
	vec4 &operator*=(vec4 &left, const float &right);
	quat operator*=(quat &left, const quat &right);

	vec2 operator/(const vec2 &left, const float &right);
	vec3 operator/(const vec3 &left, const float &right);
	vec4 operator/(const vec4 &left, const float &right);

	vec2 &operator/=(vec2 &left, const float &right);
	vec3 &operator/=(vec3 &left, const float &right);
	vec4 &operator/=(vec4 &left, const float &right);

	std::ostream &operator<<(std::ostream &o, const vec2 &vec);
	std::ostream &operator<<(std::ostream &o, const vec3 &vec);
	std::ostream &operator<<(std::ostream &o, const vec4 &vec);
	std::ostream &operator<<(std::ostream &o, const quat &q);

}}