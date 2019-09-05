#include "Matrix4.h"

#include <cmath>
#include "MathsUtils.h"

namespace Dolmen
{
	Matrix4::Matrix4()
	{
		memset(elements, 0, 4 * 4 * sizeof(float));
	}

	Matrix4::Matrix4(float diagonal)
	{
		memset(elements, 0, 4 * 4 * sizeof(float));
		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
	}

	Matrix4::Matrix4(float* elements)
	{
		memcpy(this->elements, elements, 4 * 4 * sizeof(float));
	}

	Matrix4::Matrix4(const Vector4& r0, const Vector4& r1, const Vector4& r2, const Vector4& r3)
	{
		rows[0] = r0;
		rows[1] = r1;
		rows[2] = r2;
		rows[3] = r3;
	}

	Matrix4 Matrix4::Identity()
	{
		return Matrix4(1.0f);
	}

	Matrix4& Matrix4::Inverse()
	{
		float temp[16];

		temp[0] = elements[5] * elements[10] * elements[15] -
			elements[5] * elements[11] * elements[14] -
			elements[9] * elements[6] * elements[15] +
			elements[9] * elements[7] * elements[14] +
			elements[13] * elements[6] * elements[11] -
			elements[13] * elements[7] * elements[10];

		temp[4] = -elements[4] * elements[10] * elements[15] +
			elements[4] * elements[11] * elements[14] +
			elements[8] * elements[6] * elements[15] -
			elements[8] * elements[7] * elements[14] -
			elements[12] * elements[6] * elements[11] +
			elements[12] * elements[7] * elements[10];

		temp[8] = elements[4] * elements[9] * elements[15] -
			elements[4] * elements[11] * elements[13] -
			elements[8] * elements[5] * elements[15] +
			elements[8] * elements[7] * elements[13] +
			elements[12] * elements[5] * elements[11] -
			elements[12] * elements[7] * elements[9];

		temp[12] = -elements[4] * elements[9] * elements[14] +
			elements[4] * elements[10] * elements[13] +
			elements[8] * elements[5] * elements[14] -
			elements[8] * elements[6] * elements[13] -
			elements[12] * elements[5] * elements[10] +
			elements[12] * elements[6] * elements[9];

		temp[1] = -elements[1] * elements[10] * elements[15] +
			elements[1] * elements[11] * elements[14] +
			elements[9] * elements[2] * elements[15] -
			elements[9] * elements[3] * elements[14] -
			elements[13] * elements[2] * elements[11] +
			elements[13] * elements[3] * elements[10];

		temp[5] = elements[0] * elements[10] * elements[15] -
			elements[0] * elements[11] * elements[14] -
			elements[8] * elements[2] * elements[15] +
			elements[8] * elements[3] * elements[14] +
			elements[12] * elements[2] * elements[11] -
			elements[12] * elements[3] * elements[10];

		temp[9] = -elements[0] * elements[9] * elements[15] +
			elements[0] * elements[11] * elements[13] +
			elements[8] * elements[1] * elements[15] -
			elements[8] * elements[3] * elements[13] -
			elements[12] * elements[1] * elements[11] +
			elements[12] * elements[3] * elements[9];

		temp[13] = elements[0] * elements[9] * elements[14] -
			elements[0] * elements[10] * elements[13] -
			elements[8] * elements[1] * elements[14] +
			elements[8] * elements[2] * elements[13] +
			elements[12] * elements[1] * elements[10] -
			elements[12] * elements[2] * elements[9];

		temp[2] = elements[1] * elements[6] * elements[15] -
			elements[1] * elements[7] * elements[14] -
			elements[5] * elements[2] * elements[15] +
			elements[5] * elements[3] * elements[14] +
			elements[13] * elements[2] * elements[7] -
			elements[13] * elements[3] * elements[6];

		temp[6] = -elements[0] * elements[6] * elements[15] +
			elements[0] * elements[7] * elements[14] +
			elements[4] * elements[2] * elements[15] -
			elements[4] * elements[3] * elements[14] -
			elements[12] * elements[2] * elements[7] +
			elements[12] * elements[3] * elements[6];

		temp[10] = elements[0] * elements[5] * elements[15] -
			elements[0] * elements[7] * elements[13] -
			elements[4] * elements[1] * elements[15] +
			elements[4] * elements[3] * elements[13] +
			elements[12] * elements[1] * elements[7] -
			elements[12] * elements[3] * elements[5];

		temp[14] = -elements[0] * elements[5] * elements[14] +
			elements[0] * elements[6] * elements[13] +
			elements[4] * elements[1] * elements[14] -
			elements[4] * elements[2] * elements[13] -
			elements[12] * elements[1] * elements[6] +
			elements[12] * elements[2] * elements[5];

		temp[3] = -elements[1] * elements[6] * elements[11] +
			elements[1] * elements[7] * elements[10] +
			elements[5] * elements[2] * elements[11] -
			elements[5] * elements[3] * elements[10] -
			elements[9] * elements[2] * elements[7] +
			elements[9] * elements[3] * elements[6];

		temp[7] = elements[0] * elements[6] * elements[11] -
			elements[0] * elements[7] * elements[10] -
			elements[4] * elements[2] * elements[11] +
			elements[4] * elements[3] * elements[10] +
			elements[8] * elements[2] * elements[7] -
			elements[8] * elements[3] * elements[6];

		temp[11] = -elements[0] * elements[5] * elements[11] +
			elements[0] * elements[7] * elements[9] +
			elements[4] * elements[1] * elements[11] -
			elements[4] * elements[3] * elements[9] -
			elements[8] * elements[1] * elements[7] +
			elements[8] * elements[3] * elements[5];

		temp[15] = elements[0] * elements[5] * elements[10] -
			elements[0] * elements[6] * elements[9] -
			elements[4] * elements[1] * elements[10] +
			elements[4] * elements[2] * elements[9] +
			elements[8] * elements[1] * elements[6] -
			elements[8] * elements[2] * elements[5];

		float determinant = elements[0] * temp[0] + elements[1] * temp[4] + elements[2] * temp[8] + elements[3] * temp[12];
		determinant = 1.0f / determinant;

		for (int i = 0; i < 4 * 4; i++)
		{
			elements[i] = temp[i] * determinant;
		}

		return *this;
	}

	Vector4 Matrix4::GetColumn(unsigned int index) const
	{
		return Vector4(elements[index + 0 * 4], elements[index + 1 * 4], elements[index + 2 * 4], elements[index + 3 * 4]);
	}

	void Matrix4::SetColumn(unsigned int index, const Vector4& column)
	{
		elements[index + 0 * 4] = column.x;
		elements[index + 1 * 4] = column.y;
		elements[index + 2 * 4] = column.z;
		elements[index + 3 * 4] = column.w;
	}

	Matrix4 Matrix4::Orthographic(float left, float right, float top, float bottom, float near, float far)
	{
		Matrix4 ortho(1.0f);

		ortho.elements[0 + 0 * 4] = 2 / (right - left);
		ortho.elements[1 + 1 * 4] = 2 / (top - bottom);
		ortho.elements[2 + 2 * 4] = 2 / (near - far);

		ortho.elements[3 + 0 * 4] = (left + right) / (left - right);
		ortho.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
		ortho.elements[3 + 2 * 4] = -(far + near) / (far - near);

		return ortho;
	}

	Matrix4 Matrix4::Perspective(float fov, float aspect, float near, float far)
	{
		Matrix4 persp(1.0f);

		float q = 1.0f / std::tan(DegreesToRadians(fov));
		float a = q / aspect;

		float b = (near + far) / (near - far);
		float c = (2.0f * near * far) / (near - far);

		persp.elements[0 + 0 * 4] = a;
		persp.elements[1 + 1 * 4] = q;
		persp.elements[2 + 2 * 4] = b;
		persp.elements[2 + 3 * 4] = -1.0f;
		persp.elements[3 + 2 * 4] = c;

		return persp;
	}

	Matrix4 Matrix4::Translate(const Vector3& translation)
	{
		Matrix4 result(1.0f);
		result.elements[3 + 0 * 4] = translation.x;
		result.elements[3 + 1 * 4] = translation.y;
		result.elements[3 + 2 * 4] = translation.z;
		return result;
	}

	Matrix4 Matrix4::Rotate(float angleInDegrees, const Vector3& axis)
	{
		Matrix4 result(1.0f);
		float radians = DegreesToRadians(angleInDegrees);
		float cos = std::cos(radians);
		float sin = std::sin(radians);
		float omc = 1.0f - cos;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		result.elements[0 + 0 * 4] = x * x * omc + cos;
		result.elements[0 + 1 * 4] = x * y * omc + z * sin;
		result.elements[0 + 2 * 4] = x * z * omc - y * sin;

		result.elements[1 + 0 * 4] = x * y * omc - z * sin;
		result.elements[1 + 1 * 4] = y * y * omc + cos;
		result.elements[1 + 2 * 4] = y * z * omc + x * sin;

		result.elements[2 + 0 * 4] = x * z * omc + y * sin;
		result.elements[2 + 1 * 4] = y * z * omc - x * sin;
		result.elements[2 + 2 * 4] = z * z * omc + cos;


		return result;
	}

	Matrix4 Matrix4::Scale(const Vector3& scale)
	{
		Matrix4 result(1.0f);
		result.elements[0 + 0 * 4] = scale.x;
		result.elements[1 + 1 * 4] = scale.y;
		result.elements[2 + 2 * 4] = scale.z;
		return result;
	}

	Matrix4 Matrix4::Inverse(const Matrix4& matrix)
	{
		Matrix4 mat = matrix;
		return mat.Inverse();
	}

	Matrix4 Matrix4::Transpose(const Matrix4& matrix)
	{
		return Matrix4(
			Vector4(matrix.rows[0].x, matrix.rows[1].x, matrix.rows[2].x, matrix.rows[3].x),
			Vector4(matrix.rows[0].y, matrix.rows[1].y, matrix.rows[2].y, matrix.rows[3].y),
			Vector4(matrix.rows[0].z, matrix.rows[1].z, matrix.rows[2].z, matrix.rows[3].z),
			Vector4(matrix.rows[0].w, matrix.rows[1].w, matrix.rows[2].w, matrix.rows[3].w)
		);
	}

	Matrix4& Matrix4::Multiply(const Matrix4& other)
	{
		float tempElements[16];
		for (int r = 0; r < 4; r++)
		{
			for (int c = 0; c < 4; c++)
			{
				float sum = 0.0f;
				for (int k = 0; k < 4; k++)
				{
					sum += elements[k + r * 4] * other.elements[c + k * 4];
				}
				tempElements[c + r * 4] = sum;
			}
		}
		memcpy(elements, tempElements, 4 * 4 * sizeof(float));
		return *this;
	}
	
	Matrix4 operator*(Matrix4 left, const Matrix4& right)
	{
		return left.Multiply(right);
	}

	Matrix4& Matrix4::operator*=(const Matrix4& other)
	{
		return Multiply(other);
	}

	Vector3 Matrix4::Multiply(const Vector3& other) const
	{
		return other.Multiply(*this);
	}

	Vector3 operator*(const Matrix4& left, const Vector3& right)
	{
		return left.Multiply(right);
	}

	Vector4 Matrix4::Multiply(const Vector4& other) const
	{
		return other.Multiply(*this);
	}

	Vector4 operator*(const Matrix4& left, const Vector4& right)
	{
		return left.Multiply(right);
	}
}