#include "Vector4.h"
#include "Matrix4.h"
namespace Dolmen
{
	
	Vector4::Vector4(float scalar)
	{
		x = scalar;
		y = scalar;
		z = scalar;
		w = scalar;
	}

	Vector4::Vector4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vector4::Vector4(const Vector3& xyz, float w)
	{
		this->x = xyz.x;
		this->y = xyz.y;
		this->z = xyz.z;
		this->w = w;
	}


	Vector4& Vector4::Add(const Vector4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	Vector4& Vector4::Subtract(const Vector4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	Vector4& Vector4::Multiply(const Vector4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}

	Vector4& Vector4::Divide(const Vector4& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;
		return *this;
	}

	Vector4 Vector4::Multiply(const Matrix4& transform) const
	{
		return Vector4(
			transform.rows[0].x * x + transform.rows[0].y * y + transform.rows[0].z * z + transform.rows[0].w * w,
			transform.rows[1].x * x + transform.rows[1].y * y + transform.rows[1].z * z + transform.rows[1].w * w,
			transform.rows[2].x * x + transform.rows[2].y * y + transform.rows[2].z * z + transform.rows[2].w * w,
			transform.rows[3].x * x + transform.rows[3].y * y + transform.rows[3].z * z + transform.rows[3].w * w
		);
	}
	
	Vector4 operator+(Vector4 left, const Vector4& right)
	{
		return left.Add(right);
	}

	Vector4 operator-(Vector4 left, const Vector4& right)
	{
		return left.Subtract(right);
	}

	Vector4 operator*(Vector4 left, const Vector4& right)
	{
		return left.Multiply(right);
	}

	Vector4 operator/(Vector4 left, const Vector4& right)
	{
		return left.Divide(right);
	}

	bool Vector4::operator==(const Vector4& other)
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	bool Vector4::operator!=(const Vector4& other)
	{
		return !(*this == other);
	}

	Vector4& Vector4::operator+=(const Vector4& other)
	{
		return Add(other);
	}

	Vector4& Vector4::operator-=(const Vector4& other)
	{
		return Subtract(other);
	}

	Vector4& Vector4::operator*=(const Vector4& other)
	{
		return Multiply(other);
	}

	Vector4& Vector4::operator/=(const Vector4& other)
	{
		return Divide(other);
	}

	std::ostream& operator<<(std::ostream& stream, const Vector4& vector)
	{
		stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		return stream;
	}
}