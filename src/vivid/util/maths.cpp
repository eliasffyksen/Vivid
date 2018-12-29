//
// Created by stroh on 15/12/2018.
//

#include "maths.h"

namespace vivid { namespace vdm {
/// functions

	float clamp(const float &value, float bound0, float bound1) {
		if (bound0 < bound1) {
			if (value < bound0)
				return bound0;
			if (value > bound1)
				return bound1;
		} else { // bound1 < bound 0
			if (value < bound1)
				return bound1;
			if (value > bound0)
				return bound0;
		}

		return value;
	}
	float angle(const quat &q0, const quat &q1) { return q0.angle(q1); }

	vec2 lerp(const vec2 &v0, const vec2 &v1, const float &t) { return v0 * (1 - t) + t * v1; }
	vec3 lerp(const vec3 &v0, const vec3 &v1, const float &t) { return v0 * (1 - t) + t * v1; }
	vec4 lerp(const vec4 &v0, const vec4 &v1, const float &t) { return v0 * (1 - t) + t * v1; }
	quat lerp(quat q0, quat q1, const float &t) {
		q0.normalize();
		q1.normalize();

		quat res = ((1 - t) * q0) + (t * q1);
		res.normalize();
		return res;
	}
	quat slerp(quat q0, quat q1, float t) {
		q0.normalize();
		q1.normalize();

		float dot = q0.dot(q1);

		if (dot < 0.0f) {
			q1 = -q1;
			dot = -dot;
		}

		// if the dot is very close to 1, the angle is too small to be used effectively, we therefore approximate as a linear interpolation
		ASSERT(dot != NAN && dot != -NAN);
		if (dot > 0.50) { // TODO: this is very glitchy
			quat res = ((1 - t) * q0) + (t * q1);
			res.normalize();
			return res;
		}

		double theta0 = acos((double) dot);
		double theta = theta0 * t;
		double sintheta0 = sin(theta0);
		double sintheta = sin(theta);

		auto s0 = (float) (cos(theta) - dot * sintheta / sintheta0);
		auto s1 = (float) (sintheta / sintheta0);

		return (s0 * q0) + (s1 * q1);
	}

/// vector2f

	vec2::vec2()
			: x(0), y(0) {}

	vec2::vec2(const float &x, const float &y)
			: x(x), y(y) {}

	float vec2::length() {
		return std::sqrt(x * x + y * y);
	}

	vec2 &vec2::normalize() {
		float length = this->length();

		x /= length;
		y /= length;

		return *this;
	}

	float vec2::dot(const vec2 &right) {
		return this->x * right.x + this->y * right.y;
	}

	vec2 &vec2::rotate(float angle) {
		double cos = std::cos(angle);
		double sin = std::cos(angle);

		float xn = (float) (this->x * cos - this->y * sin);
		float yn = (float) (this->x * sin + this->y * cos);

		x = xn;
		y = yn;

		return *this;
	}

	vec2 &vec2::add(const vec2 &right) {
		x += right.x;
		y += right.y;

		return *this;
	}

	vec2 &vec2::sub(const vec2 &right) {
		x -= right.x;
		y -= right.y;

		return *this;
	}

	vec2 &vec2::mul(const vec2 &right) {
		x *= right.x;
		y *= right.y;

		return *this;
	}

	vec2 &vec2::mul(const float &multiplier) {
		x *= multiplier;
		y *= multiplier;

		return *this;
	}

	vec2 &vec2::div(const vec2 &right) {
		x /= right.x;
		y /= right.y;

		return *this;
	}

	vec2 &vec2::div(const float &multiplier) {
		x /= multiplier;
		y /= multiplier;

		return *this;
	}

/// vector3f

	vec3::vec3()
			: x(0), y(0), z(0) {}

	vec3::vec3(const float &x, const float &y, const float &z)
			: x(x), y(y), z(z) {}

	float vec3::length() {
		return std::sqrt(x * x + y * y + z * z);
	}

	vec3 &vec3::normalize() {
		float length = this->length();

		x /= length;
		y /= length;
		z /= length;

		return *this;
	}

	float vec3::dot(const vec3 &right) {
		return this->x * right.x + this->y * right.y + this->z * right.z;
	}

	vec3 vec3::cross(const vec3 &right) {
		return vec3(
				this->y * right.z - this->z * right.y,
				this->z * right.x - this->x * right.z,
				this->x * right.y - this->y * right.x
		);
	}

	vec3 &vec3::rotate(const quat &rotation) {
		quat conjugate = rotation.conjugate();
		quat intermediate = rotation.mul(*this).mul(conjugate);

		x = intermediate.x;
		y = intermediate.y;
		z = intermediate.z;

		return *this;
	}

	vec3 &vec3::add(const vec3 &right) {
		x += right.x;
		y += right.y;
		z += right.z;

		return *this;
	}

	vec3 &vec3::sub(const vec3 &right) {
		x -= right.x;
		y -= right.y;
		z -= right.z;

		return *this;
	}

	vec3 &vec3::mul(const vec3 &right) {
		x *= right.x;
		y *= right.y;
		z *= right.z;

		return *this;
	}

	vec3 &vec3::mul(const float &multiplier) {
		x *= multiplier;
		y *= multiplier;
		z *= multiplier;

		return *this;
	}

	vec3 &vec3::div(const vec3 &right) {
		x /= right.x;
		y /= right.y;
		z /= right.z;

		return *this;
	}

	vec3 &vec3::div(const float &multiplier) {
		x /= multiplier;
		y /= multiplier;
		z /= multiplier;

		return *this;
	}

/// vector4f

	vec4::vec4()
			: x(0), y(0), z(0), w(0) {}

	vec4::vec4(const float &x, const float &y, const float &z, const float &w)
			: x(x), y(y), z(z), w(w) {}

	vec4::vec4(const vec3 &other, float w)
			: x(other.x), y(other.y), z(other.z), w(w) {}

	float vec4::length() {
		return std::sqrt(x * x + y * y + z * z + w * w);
	}

	vec4 &vec4::normalize() {
		float length = this->length();

		x /= length;
		y /= length;
		z /= length;
		w /= length;

		return *this;
	}

	float vec4::dot(const vec4 &right) {
		return this->x * right.x + this->y * right.y + this->z * right.z + this->w * right.w;
	}

	vec4 &vec4::add(const vec4 &right) {
		x += right.x;
		y += right.y;
		z += right.z;
		w += right.w;

		return *this;
	}

	vec4 &vec4::sub(const vec4 &right) {
		x -= right.x;
		y -= right.y;
		z -= right.z;
		w -= right.w;

		return *this;
	}

	vec4 &vec4::mul(const vec4 &right) {
		x *= right.x;
		y *= right.y;
		z *= right.z;
		w *= right.w;

		return *this;
	}

	vec4 &vec4::mul(const float &multiplier) {
		x *= multiplier;
		y *= multiplier;
		z *= multiplier;
		w *= multiplier;

		return *this;
	}

	vec4 &vec4::div(const vec4 &right) {
		x /= right.x;
		y /= right.y;
		z /= right.z;
		w /= right.w;

		return *this;
	}

	vec4 &vec4::div(const float &multiplier) {
		x /= multiplier;
		y /= multiplier;
		z /= multiplier;
		w /= multiplier;

		return *this;
	}

	/// quaternion

	quat::quat()
			: w(1), x(0), y(0), z(0) {}

	quat::quat(const float &w, const float &x, const float &y, const float &z)
			: w(w), x(x), y(y), z(z) {}

	quat::quat(const float &angle, vec3 axis) {
		axis.normalize();
		float sinHalfAngle = std::sin(angle / 2.0f);
		float cosHalfAngle = std::cos(angle / 2.0f);

		w = (float) cosHalfAngle;
		x = (float) (axis.x * sinHalfAngle);
		y = (float) (axis.y * sinHalfAngle);
		z = (float) (axis.z * sinHalfAngle);
	}

	float quat::length() const {
		return std::sqrt(x * x + y * y + z * z + w * w);
	}

	float quat::dot(const quat &q) const {
		return w * q.w + x * q.x + y * q.y + z * q.z;
	}

	float quat::angle(const quat &other) const {
		float dot = this->dot(other);
		if (dot < 0.0)
			dot = -dot;
		if (dot > 1)
			dot = 1;

		float angle = (float) acos((double) dot);
		ASSERT(angle >= 0 && angle <= VD_PI);
		return angle;
	}

	quat &quat::normalize() {
		float len = this->length();

		x /= len;
		y /= len;
		z /= len;
		w /= len;

		return *this;
	}

	quat quat::conjugate() const {
		return quat(w, -x, -y, -z);
	}

	quat &quat::add(const quat &right) {
		this->w += right.w;
		this->x += right.x;
		this->y += right.y;
		this->z += right.z;

		return *this;
	}

	quat &quat::mul(const quat &right) {
		float w_ = this->w * right.w - this->x * right.x - this->y * right.y - this->z * right.z;
		float x_ = this->w * right.x + this->x * right.w + this->y * right.z - this->z * right.y;
		float y_ = this->w * right.y - this->x * right.z + this->y * right.w + this->z * right.x;
		float z_ = this->w * right.z + this->x * right.y - this->y * right.x + this->z * right.w;

		w = w_;
		x = x_;
		y = y_;
		z = z_;

		return *this;
//		return this->normalize();
	}

	quat quat::mul(const vec3 &vec) const {
		return quat(
				-this->x * vec.x - this->y * vec.y - this->z * vec.z,
				this->w * vec.x + this->y * vec.z - this->z * vec.y,
				this->w * vec.y + this->z * vec.x - this->x * vec.z,
				this->w * vec.z + this->x * vec.y - this->y * vec.x
		);
	}

	quat &quat::mul(const float &multiplier) {
		w *= multiplier;
		x *= multiplier;
		y *= multiplier;
		z *= multiplier;

		return *this;
	}

/// matrix 4x4

	mat4::mat4(const float &d) {
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

	mat4 mat4::transpose() {
		mat4 res(0);

		for (int i = 0; i < 16; i++) {
			int x = i % 4;
			int y = i / 4;

			res.m[y + x * 4] = this->m[x + y * 4];
		}

		return res;
	}

	mat4 mat4::mul(const mat4 &right) const {
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

	vec4 mat4::mul(const vec4 &right) const {
		vec4 res;

		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				res.m[j] += this->m[k + 4 * j] * right.m[k];
			}
		}

		return res;
	}

	vec4 mat4::mul(const vec3 &vec, const float &w) const {
		return mul(vec4(vec, w));
	}

	mat4 mat4::translation(const vec3 &translation) {
		mat4 res(1);

		res.m[0 * 4 + 3] = translation.x;
		res.m[1 * 4 + 3] = translation.y;
		res.m[2 * 4 + 3] = translation.z;

		return res;
	}

	mat4 mat4::scale(const vec3 &scale) {
		mat4 res(1);
		res.m[0 * 4 + 0] = scale.x;
		res.m[1 * 4 + 1] = scale.y;
		res.m[2 * 4 + 2] = scale.z;

		return res;
	}

	mat4 mat4::rotation(const quat &rotation) {
		mat4 res(0);

		const float &w = rotation.w;
		const float &x = rotation.x;
		const float &y = rotation.y;
		const float &z = rotation.z;

		res.m[0 * 4 + 0] = w * w + x * x - y * y - z * z;
		res.m[0 * 4 + 1] = 2 * x * y - 2 * w * z;
		res.m[0 * 4 + 2] = 2 * x * z + 2 * w * y;
		res.m[0 * 4 + 3] = 0;

		res.m[1 * 4 + 0] = 2 * x * y + 2 * w * z;
		res.m[1 * 4 + 1] = w * w - x * x + y * y - z * z;
		res.m[1 * 4 + 2] = 2 * y * z - 2 * w * x;
		res.m[1 * 4 + 3] = 0;

		res.m[2 * 4 + 0] = 2 * x * z - 2 * w * y;
		res.m[2 * 4 + 1] = 2 * y * z + 2 * w * x;
		res.m[2 * 4 + 2] = w * w - x * x - y * y + z * z;
		res.m[2 * 4 + 3] = 0;

		res.m[3 * 4 + 0] = 0;
		res.m[3 * 4 + 1] = 0;
		res.m[3 * 4 + 2] = 0;
		res.m[3 * 4 + 3] = w * w + x * x + y * y + z * z;

		return res;
	}

/// operators

	vec2 &operator+=(vec2 &left, const vec2 &right) { return left.add(right); }
	vec3 &operator+=(vec3 &left, const vec3 &right) { return left.add(right); }
	vec4 &operator+=(vec4 &left, const vec4 &right) { return left.add(right); }
	quat &operator+=(quat &left, const quat &right) { return left.add(right); }

	vec2 operator+(const vec2 &left, const vec2 &right) { return vec2(left).add(right); }
	vec3 operator+(const vec3 &left, const vec3 &right) { return vec3(left).add(right); }
	vec4 operator+(const vec4 &left, const vec4 &right) { return vec4(left).add(right); }
	quat operator+(const quat &left, const quat &right) { return quat(left).add(right); }

	vec2 &operator-=(vec2 &left, const vec2 &right) { return left.sub(right); }
	vec3 &operator-=(vec3 &left, const vec3 &right) { return left.sub(right); }
	vec4 &operator-=(vec4 &left, const vec4 &right) { return left.sub(right); }

	vec2 operator-(const vec2 &left, const vec2 &right) { return vec2(left).sub(right); }
	vec3 operator-(const vec3 &left, const vec3 &right) { return vec3(left).sub(right); }
	vec4 operator-(const vec4 &left, const vec4 &right) { return vec4(left).sub(right); }

	vec2 operator-(const vec2 &vec) { return vec2(-vec.x, -vec.y); }
	vec3 operator-(const vec3 &vec) { return vec3(-vec.x, -vec.y, -vec.z); }
	vec4 operator-(const vec4 &vec) { return vec4(-vec.x, -vec.y, -vec.z, -vec.w); }
	quat operator-(const quat &q) { return quat(-q.w, -q.x, -q.y, -q.z); }

	vec2 operator*(const float &left, const vec2 &right) { return vec2(right).mul(left); }
	vec3 operator*(const float &left, const vec3 &right) { return vec3(right).mul(left); }
	vec4 operator*(const float &left, const vec4 &right) { return vec4(right).mul(left); }
	quat operator*(const quat &left, const quat &right) { return quat(left).mul(right); }
	quat operator*(const float &left, const quat &right) { return quat(right).mul(left); }
	mat4 operator*(const mat4 &left, const mat4 &right) { return left.mul(right); }

	vec2 operator*(const vec2 &left, const float &right) { return vec2(left).mul(right); }
	vec3 operator*(const vec3 &left, const float &right) { return vec3(left).mul(right); }
	vec4 operator*(const vec4 &left, const float &right) { return vec4(left).mul(right); }
	quat operator*(const quat &left, const float &right) { return quat(left).mul(right); }
	vec4 operator*(const mat4 &left, const vec4 &right) { return left.mul(right); }

	vec2 &operator*=(vec2 &left, const float &right) { return left.mul(right); }
	vec3 &operator*=(vec3 &left, const float &right) { return left.mul(right); }
	vec4 &operator*=(vec4 &left, const float &right) { return left.mul(right); }
	quat operator*=(quat &left, const quat &right) { return left.mul(right); }

	vec2 operator/(const vec2 &left, const float &right) { return vec2(left).div(right); }
	vec3 operator/(const vec3 &left, const float &right) { return vec3(left).div(right); }
	vec4 operator/(const vec4 &left, const float &right) { return vec4(left).div(right); }

	vec2 &operator/=(vec2 &left, const float &right) { return left.div(right); }
	vec3 &operator/=(vec3 &left, const float &right) { return left.div(right); }
	vec4 &operator/=(vec4 &left, const float &right) { return left.div(right); }

	std::ostream &operator<<(std::ostream &o, const vec2 &vec) {
		o << "(" << vec.x << ", " << vec.y << ")";
		return o;
	}
	std::ostream &operator<<(std::ostream &o, const vec3 &vec) {
		o << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
		return o;
	}
	std::ostream &operator<<(std::ostream &o, const vec4 &vec) {
		o << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
		return o;
	}
	std::ostream &operator<<(std::ostream &o, const quat &q) {
		o << "(" << q.w << ", " << q.x << ", " << q.y << ", " << q.z << ")";
		return o;
	}

}}
