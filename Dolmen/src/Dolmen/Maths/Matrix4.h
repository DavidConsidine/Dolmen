#pragma once

#include "Vector3.h"
#include "Vector4.h"

namespace Dolmen
{
	struct Matrix4
	{
		union
		{
			float elements[4 * 4];
			Vector4 rows[4];
		};

		Matrix4();
		Matrix4(float diagonal);
		Matrix4(float* elements);
		Matrix4(const Vector4& r0, const Vector4& r1, const Vector4& r2, const Vector4& r3);

		static Matrix4 Identity();

		Matrix4& Inverse();

		Vector4 GetColumn(unsigned int index) const;
		void SetColumn(unsigned int index, const Vector4& column);

		static Matrix4 Orthographic(float left, float right, float top, float bottom, float near, float far);
		static Matrix4 Perspective(float fov, float aspect, float near, float far);

		static Matrix4 Translate(const Vector3& translation);
		static Matrix4 Rotate(float angleInDegrees, const Vector3& axis);
		static Matrix4 Scale(const Vector3& scale);

		static Matrix4 Inverse(const Matrix4& matrix);
		static Matrix4 Transpose(const Matrix4& matrix);

		Matrix4& Multiply(const Matrix4& other);
		friend Matrix4 operator*(Matrix4 left, const Matrix4& right);
		Matrix4& operator*=(const Matrix4& other);

		Vector3 Multiply(const Vector3& other) const;
		friend Vector3 operator*(const Matrix4& left, const Vector3& right);

		Vector4 Multiply(const Vector4& other) const;
		friend Vector4 operator*(const Matrix4& left, const Vector4& right);
	};
}