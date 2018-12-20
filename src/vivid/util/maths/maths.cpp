//
// Created by stroh on 15/12/2018.
//

#include "maths.h"
#include <cmath>

namespace vivid { namespace maths {
/// vec2

	float vec2::length() {
		return std::sqrt(x * x + y * y);
	}

	vec2 vec2::add(const vec2 &right) {
		x += right.x;
		y += right.y;
	}

	vec2 vec2::sub(const vec2 &right) {
		x -= right.x;
		y -= right.y;
	}

	vec2 vec2::mul(const vec2 &right) {
		x *= right.x;
		y *= right.y;
	}

	vec2 vec2::div(const vec2 &right) {
		x /= right.x;
		y /= right.y;
	}

/// vec3

	float vec3::length() {
		return std::sqrt(x * x + y * y);
	}

	vec3 vec3::add(const vec3 &right) {
		x += right.x;
		y += right.y;
		z += right.z;
	}

	vec3 vec3::sub(const vec3 &right) {
		x -= right.x;
		y -= right.y;
		z -= right.z;
	}

	vec3 vec3::mul(const vec3 &right) {
		x *= right.x;
		y *= right.y;
		z *= right.z;
	}

	vec3 vec3::div(const vec3 &right) {
		x /= right.x;
		y /= right.y;
		z /= right.z;
	}

/// vec4

	float vec4::length() {
		return std::sqrt(x * x + y * y);
	}

	vec4 vec4::add(const vec4 &right) {
		x += right.x;
		y += right.y;
		z += right.z;
		w += right.w;
	}

	vec4 vec4::sub(const vec4 &right) {
		x -= right.x;
		y -= right.y;
		z -= right.z;
		w -= right.w;
	}

	vec4 vec4::mul(const vec4 &right) {
		x *= right.x;
		y *= right.y;
		z *= right.z;
		w *= right.w;
	}

	vec4 vec4::div(const vec4 &right) {
		x /= right.x;
		y /= right.y;
		z /= right.z;
		w /= right.w;
	}

/// mat4

//mat4::mat4() {
//	m[0] = 1;	m[1] = 0;	m[2] = 0;	m[3] = 0;
//	m[4] = 0;	m[5] = 1;	m[6] = 0;	m[7] = 0;
//	m[8] = 0;	m[9] = 0;	m[10] = 1;	m[11] = 0;
//	m[12] = 0;	m[13] = 0;	m[14] = 0;	m[15] = 1;
//}

	mat4::mat4(float d) {
		m[0] = d;
		m[1] = 0;
		m[2] = 0;
		m[3] = 0;
		m[4] = 0;
		m[5] = d;
		m[6] = 0;
		m[7] = 0;
		m[8] = 0;
		m[9] = 0;
		m[10] = d;
		m[11] = 0;
		m[12] = 0;
		m[13] = 0;
		m[14] = 0;
		m[15] = d;
	}

	mat4 mat4::mul(const mat4 &right) {
		mat4 res(0);

		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 4; i++) {
				for (int k = 0; k < 4; k++) {
					res.m[i + 4 * j] += this->m[k + 4 * j] * right.m[i + 4 * k];
				}
			}
		}

		return res;
	}

	vec4 mat4::mul(const vec4 &vec) {
		vec4 res;

		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				res.m[j] += this->m[k + 4 * j] * vec.m[k];
			}
		}

		return res;
	}

/// Logging

	std::ostream &operator<<(std::ostream &o, const vec4 &vec) {
		o << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";

		return o;
	}

}}