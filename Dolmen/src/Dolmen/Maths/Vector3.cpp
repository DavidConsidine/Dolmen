#include "Vector3.h"
#include "Matrix4.h"

namespace Dolmen
{
	
	Vector3::Vector3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vector3::Vector3(const float& x, const float& y, const float& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3& Vector3::Add(const Vector3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3& Vector3::Subtract(const Vector3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vector3& Vector3::Multiply(const Vector3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	Vector3& Vector3::Divide(const Vector3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	Vector3 Vector3::Multiply(const Matrix4& transform) const
	{
		return Vector3(
					transform.rows[0].x * x + transform.rows[0].y * y + transform.rows[0].z * z + transform.rows[0].w,
					transform.rows[1].x * x + transform.rows[1].y * y + transform.rows[1].z * z + transform.rows[1].w, 
					transform.rows[2].x * x + transform.rows[2].y * y + transform.rows[2].z * z + transform.rows[2].w
					);
	}
	
	Vector3 operator+(Vector3 left, const Vector3& right)
	{
		return left.Add(right);
	}

	Vector3 operator-(Vector3 left, const Vector3& right)
	{
		return left.Subtract(right);
	}

	Vector3 operator*(Vector3 left, const Vector3& right)
	{
		return left.Multiply(right);
	}

	Vector3 operator/(Vector3 left, const Vector3& right)
	{
		return left.Divide(right);
	}

	bool Vector3::operator==(const Vector3& other)
	{
		return x == other.x && y == other.y && z == other.z;
	}

	bool Vector3::operator!=(const Vector3& other)
	{
		return !(*this == other);
	}

	Vector3& Vector3::operator+=(const Vector3& other)
	{
		return Add(other);
	}

	Vector3& Vector3::operator-=(const Vector3& other)
	{
		return Subtract(other);
	}

	Vector3& Vector3::operator*=(const Vector3& other)
	{
		return Multiply(other);
	}

	Vector3& Vector3::operator/=(const Vector3& other)
	{
		return Divide(other);
	}

	std::ostream& operator<<(std::ostream& stream, const Vector3& vector)
	{
		stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}
}