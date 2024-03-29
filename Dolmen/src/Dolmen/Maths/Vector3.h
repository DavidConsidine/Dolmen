#pragma once
#include <iostream>
namespace Dolmen
{
	struct Matrix4;

	struct Vector3
	{
		float x, y, z;

		Vector3();
		Vector3(const float& x, const float& y, const float& z);

		Vector3& Add(const Vector3& other);
		Vector3& Subtract(const Vector3& other);
		Vector3& Multiply(const Vector3& other);
		Vector3& Divide(const Vector3& other);

		Vector3 Multiply(const Matrix4& transform) const;

		friend Vector3 operator+(Vector3 left, const Vector3& right);
		friend Vector3 operator-(Vector3 left, const Vector3& right);
		friend Vector3 operator*(Vector3 left, const Vector3& right);
		friend Vector3 operator/(Vector3 left, const Vector3& right);

		bool operator==(const Vector3& other);
		bool operator!=(const Vector3& other);

		Vector3& operator+=(const Vector3& other);
		Vector3& operator-=(const Vector3& other);
		Vector3& operator*=(const Vector3& other);
		Vector3& operator/=(const Vector3& other);

		friend std::ostream& operator<<(std::ostream& stream, const Vector3& vector);
	};
}