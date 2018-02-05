#include "stdafx.h"
#include "Vector3.h"

namespace GL {

	Vector3::Vector3() : Vector3(0.0f, 0.0f, 0.0f) { }

	Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {
		len = sqrt(_x * _x + _y * _y + _z * _z);
	}

	Vector3::Vector3(const Vector3 &vec) {
		x = vec.x; y = vec.y; z = vec.z;
	}

	Vector3::Vector3(const std::vector<float> &vec) {
		if (vec.size() < 3)
			throw std::invalid_argument("Vector size less than dimension");
		x = vec[0]; y = vec[1]; z = vec[2];
	}

	bool Vector3::operator==(const Vector3 &vec) const {
		return x == vec.x && y == vec.y && z == vec.z;
	}

	bool Vector3::operator!=(const Vector3 &vec) const {
		return x != vec.x || y != vec.y || z != vec.z;
	}

	Vector3 Vector3::operator+(const Vector3 &vec) const {
		return Vector3(x + vec.x, y + vec.y, z + vec.z);
	}

	Vector3 Vector3::operator-(const Vector3 &vec) const {
		return Vector3(x - vec.x, y - vec.y, z - vec.z);
	}

	Vector3 Vector3::operator-() const {
		return Vector3(-x, -y, -z);
	}

	Vector3 Vector3::operator*(float s) const {
		return Vector3(s * x, s * y, s * z);
	}

	Vector3 Vector3::operator/(float s) const {
		if (s == 0)
			throw std::invalid_argument("Division by zero");
		return Vector3(x / s, y / s, z / s);
	}

	float Vector3::dot(const Vector3 &vec) const {
		return x * vec.x + y * vec.y + z * vec.z;
	}

	Vector3 Vector3::cross(const Vector3 &vec) const {
		return Vector3(y * vec.z - z * vec.y,
					   z * vec.x - x * vec.z,
					   x * vec.y - y * vec.x);
	}

	Vector3 Vector3::normalized() const {
		// return a zero vector if already is one
		return (*this) / (len == 0 ? 1 : len);
	}
}