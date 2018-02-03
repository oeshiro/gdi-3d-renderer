#pragma once

#include <vector>
#include "Vector4.h"

// The Matrix4 class represents a 4-dimensional matrix. The indices start at zero.
class Matrix4
{
public:
	// Initializes an identity matrix.
	Matrix4();
	// Initializes a matrix with the values given in a list.
	Matrix4(const std::vector<float> _values);
	// Copy constructor
	Matrix4(const Matrix4 &mat);

	const int dim = 4;

	Matrix4 operator*(float s);
	Matrix4 operator*(const Matrix4 &mat);
	Vector4 operator*(const Vector4 &vec);
	Matrix4 operator+(const Matrix4 &mat);
	Matrix4 operator-(const Matrix4 &mat);

	float get(int row, int col) const;
	Vector4 getRow(int row) const;
	Vector4 getColumn(int col) const;
	Matrix4 transposed();

private:
	std::vector<float> values;
};

Matrix4::Matrix4() {
	values = { 1, 0, 0, 0,
		       0, 1, 0, 0, 
		       0, 0, 1, 0,
	           0, 0, 0, 1 };
}

Matrix4::Matrix4(const std::vector<float> _values) : values(_values) { }

Matrix4::Matrix4(const Matrix4 &mat) : values(mat.values) { }

Matrix4 Matrix4::operator*(float s) {
	std::vector<float> newValues(values);
	for (int i = 0; i < newValues.size(); i++) {
		newValues[i] *= s;
	}
	return Matrix4(newValues);
}

Matrix4 Matrix4::operator*(const Matrix4 &mat) {
	std::vector<float> newValues(values);
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			newValues[i * dim + j] = getRow(i).dot(mat.getColumn(j));
		}
	}
	return Matrix4(newValues);
}

Vector4 Matrix4::operator*(const Vector4 &vec) {
	std::vector<float> newVector;
	for (int i = 0; i < dim; i++) {
		newVector.push_back(getRow(i).dot(vec));
	}
	return Vector4(newVector);
}

Matrix4 Matrix4::operator+(const Matrix4 &mat) {
	std::vector<float> newValues(values);
	for (int i = 0; i < newValues.size(); i++) {
		newValues[i] += mat.get(i / dim, i % dim);
	}
	return Matrix4(newValues);
}

Matrix4 Matrix4::operator-(const Matrix4 &mat) {
	std::vector<float> newValues(values);
	for (int i = 0; i < newValues.size(); i++) {
		newValues[i] -= mat.get(i / dim, i % dim);
	}
	return Matrix4(newValues);
}

float Matrix4::get(int row, int col) const {
	if (row < 0 || row > dim || col < 0 || col > dim)
		throw std::invalid_argument("Coordinates are invalid");
	return values[row * dim + col];
}

Vector4 Matrix4::getRow(int row) const {
	if (row < 0 || row > dim)
		throw std::invalid_argument("Row number is invalid");
	return Vector4(get(row, 0), get(row, 1), get(row, 2), get(row, 3));
}

Vector4 Matrix4::getColumn(int col) const {
	if (col < 0 || col > dim)
		throw std::invalid_argument("Col number is invalid");
	return Vector4(get(0, col), get(1, col), get(2, col), get(3, col));
}

Matrix4 Matrix4::transposed() {
	std::vector<float> newValues(values);
	for (int i = 0; i < newValues.size(); i++) {
		newValues[i] = get(i % dim, i / dim);
	}
	return Matrix4(newValues);
}
