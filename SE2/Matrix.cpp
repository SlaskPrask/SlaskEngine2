#include "Matrix.h"

Matrix4::Matrix4(float init)
{
	m[0] = init;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	
	m[4] = 0;
	m[5] = init;
	m[6] = 0;
	m[7] = 0;
	
	m[8] = 0;
	m[9] = 0;
	m[10] = init;
	m[11] = 0;
	
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = init;

}
Matrix4::~Matrix4()
{
}
Matrix4::Matrix4(float n[16])
{
	m[0] = n[0];
	m[1] = n[1];
	m[2] = n[2];
	m[3] = n[3];

	m[4] = n[4];
	m[5] = n[5];
	m[6] = n[6];
	m[7] = n[7];

	m[8] = n[8];
	m[9] = n[9];
	m[10] = n[10];
	m[11] = n[11];

	m[12] = n[12];
	m[13] = n[13];
	m[14] = n[14];
	m[15] = n[15];
}
Matrix4 Matrix4::operator+(float &scalar)
{
	float f[16] = 
	{
		m[0] + scalar,
		m[1] + scalar,
		m[2] + scalar,
		m[3] + scalar,
		m[4] + scalar,
		m[5] + scalar,
		m[6] + scalar,
		m[7] + scalar,
		m[8] + scalar,
		m[9] + scalar,
		m[10] + scalar,
		m[11] + scalar,
		m[12] + scalar,
		m[13] + scalar,
		m[14] + scalar,
		m[15] + scalar
	};
	return Matrix4(f);
}
Matrix4 Matrix4::operator-(float &scalar)
{
	float f[16] =
	{
		m[0] - scalar,
		m[1] - scalar,
		m[2] - scalar,
		m[3] - scalar,
		m[4] - scalar,
		m[5] - scalar,
		m[6] - scalar,
		m[7] - scalar,
		m[8] - scalar,
		m[9] - scalar,
		m[10] - scalar,
		m[11] - scalar,
		m[12] - scalar,
		m[13] - scalar,
		m[14] - scalar,
		m[15] - scalar
	};
	return Matrix4(f);
}
Matrix4 Matrix4::operator*(float &scalar)
{
	float f[16] =
	{
		m[0] * scalar,
		m[1] * scalar,
		m[2] * scalar,
		m[3] * scalar,
		m[4] * scalar,
		m[5] * scalar,
		m[6] * scalar,
		m[7] * scalar,
		m[8] * scalar,
		m[9] * scalar,
		m[10] * scalar,
		m[11] * scalar,
		m[12] * scalar,
		m[13] * scalar,
		m[14] * scalar,
		m[15] * scalar
	};
	return Matrix4(f);
}
Matrix4 Matrix4::operator*(const Matrix4 &second)
{
	float f[16] =
	{
		m[0] * second.m[0] + m[1] * second.m[4] + m[2] * second.m[8] + m[3] * second.m[12],
		m[0] * second.m[1] + m[1] * second.m[5] + m[2] * second.m[9] + m[3] * second.m[13],
		m[0] * second.m[2] + m[1] * second.m[6] + m[2] * second.m[10] + m[3] * second.m[14],
		m[0] * second.m[3] + m[1] * second.m[7] + m[2] * second.m[11] + m[3] * second.m[15],
		m[4] * second.m[0] + m[5] * second.m[4] + m[6] * second.m[8] + m[7] * second.m[12],
		m[4] * second.m[1] + m[5] * second.m[5] + m[6] * second.m[9] + m[7] * second.m[13],
		m[4] * second.m[2] + m[5] * second.m[6] + m[6] * second.m[10] + m[7] * second.m[14],
		m[4] * second.m[3] + m[5] * second.m[7] + m[6] * second.m[11] + m[7] * second.m[15],
		m[8] * second.m[0] + m[9] * second.m[4] + m[10] * second.m[8] + m[11] * second.m[12],
		m[8] * second.m[1] + m[9] * second.m[5] + m[10] * second.m[9] + m[11] * second.m[13],
		m[8] * second.m[2] + m[9] * second.m[6] + m[10] * second.m[10] + m[11] * second.m[14],
		m[8] * second.m[3] + m[9] * second.m[7] + m[10] * second.m[11] + m[11] * second.m[15],
		m[12] * second.m[0] + m[13] * second.m[4] + m[14] * second.m[8] + m[15] * second.m[12],
		m[12] * second.m[1] + m[13] * second.m[5] + m[14] * second.m[9] + m[15] * second.m[13],
		m[12] * second.m[2] + m[13] * second.m[6] + m[14] * second.m[10] + m[15] * second.m[14],
		m[12] * second.m[3] + m[13] * second.m[7] + m[14] * second.m[11] + m[15] * second.m[15]
	};
	return Matrix4(f);
}

Matrix4& Matrix4::operator= (Matrix4 other)
{
	std::swap(m, other.m);
	return *this;
}

Matrix4 Matrix4::Rotation(float r)
{
	Matrix4 m2(1);
	m2[0] = cosf(r);
	m2[1] = sinf(r);
	m2[4] = -sinf(r);
	m2[5] = cosf(r);
	return m2;
}

Matrix4 Matrix4::Translation(Vector3 t)
{
	Matrix4 m2(1);
	m2[12] = t.x;
	m2[13] = t.y;
	m2[14] = t.z;
	return m2;
}

Matrix4 Matrix4::Scaling(Vector3 s)
{
	Matrix4 m2(1);
	m2[0] = s.x;
	m2[5] = s.y;
	m2[10] = s.z;
	return m2;
}

Vector4 Matrix4::operator*(Vector4 &vec4)
{
	return Vector4(m[0] * vec4.x + m[4] * vec4.y + m[8] * vec4.z + m[12] * vec4.w, m[1] * vec4.x + m[5] * vec4.y + m[9] * vec4.z + m[13] * vec4.w, m[2] * vec4.x + m[6] * vec4.y + m[10] * vec4.z + m[14] * vec4.w, m[3] * vec4.x + m[7] * vec4.y + m[11] * vec4.z + m[15] * vec4.w);
}

void Matrix4::Rotate(float r)
{
	m[0] = cosf(r);
	m[1] = sinf(r);
	m[4] = -sinf(r);
	m[5] = cosf(r);
}

void Matrix4::NewScale(Vector3 scale)
{
	m[0] = scale.x;
	m[5] = scale.y;
	m[10] = scale.z;
}

void Matrix4::ScaleBy(Vector3 scale)
{
	m[0] *= scale.x;
	m[5] *= scale.y;
	m[10] *= scale.z;
}

void Matrix4::Translate(Vector3 translate)
{
	m[12] = translate.x;
	m[13] = translate.y;
	m[14] = translate.z;
}

Matrix3::Matrix3(float init)
{
	for (int i = 0; i < sizeof(m); i++)
	{
		if (i % 4 == 0)
			m[i] = init;
		else
			m[i] = 0;
	}
}
Matrix3::~Matrix3()
{
}
Matrix3::Matrix3(float n[9])
{
	for (int i = 0; i < sizeof(n); i++)
	{
		m[i] = n[i];
	}
}
Matrix3 Matrix3::operator+(float &scalar)
{
	float f[9] =
	{
		m[0] + scalar,
		m[1] + scalar,
		m[2] + scalar,
		m[3] + scalar,
		m[4] + scalar,
		m[5] + scalar,
		m[6] + scalar,
		m[7] + scalar,
		m[8] + scalar
	};
	return Matrix3(f);
}
Matrix3 Matrix3::operator-(float &scalar)
{
	float f[9] =
	{
		m[0] - scalar,
		m[1] - scalar,
		m[2] - scalar,
		m[3] - scalar,
		m[4] - scalar,
		m[5] - scalar,
		m[6] - scalar,
		m[7] - scalar,
		m[8] - scalar,
	};
	return Matrix3(f);
}
Matrix3 Matrix3::operator*(float &scalar)
{
	float f[9] =
	{
		m[0] * scalar,
		m[1] * scalar,
		m[2] * scalar,
		m[3] * scalar,
		m[4] * scalar,
		m[5] * scalar,
		m[6] * scalar,
		m[7] * scalar,
		m[8] * scalar
	};
	return Matrix3(f);
}
Matrix3 Matrix3::operator*(Matrix3 &second)
{
	float f[9] =
	{
		m[0] * second.m[0] + m[1] * second.m[3] + m[2] * second.m[6],
		m[0] * second.m[1] + m[1] * second.m[4] + m[2] * second.m[7],
		m[0] * second.m[2] + m[1] * second.m[5] + m[2] * second.m[8],
		m[3] * second.m[0] + m[4] * second.m[3] + m[5] * second.m[6],
		m[3] * second.m[1] + m[4] * second.m[4] + m[5] * second.m[7],
		m[3] * second.m[2] + m[4] * second.m[5] + m[5] * second.m[8],
		m[6] * second.m[0] + m[7] * second.m[3] + m[8] * second.m[6],
		m[6] * second.m[1] + m[7] * second.m[4] + m[8] * second.m[7],
		m[6] * second.m[2] + m[7] * second.m[5] + m[8] * second.m[8],
	};
	return Matrix3(f);
}

Matrix2::Matrix2(float init)
{
	for (int i = 0; i < sizeof(m); i++)
	{
		if (i % 3 == 0)
			m[i] = init;
		else
			m[i] = 0;
	}
}
Matrix2::~Matrix2()
{
}
Matrix2::Matrix2(float n[4])
{
	for (int i = 0; i < sizeof(n); i++)
	{
		m[i] = n[i];
	}
}
Matrix2 Matrix2::operator+(float &scalar)
{
	float f[4] =
	{
		m[0] + scalar,
		m[1] + scalar,
		m[2] + scalar,
		m[3] + scalar
	};
	return Matrix2(f);
}
Matrix2 Matrix2::operator-(float &scalar)
{
	float f[4] =
	{
		m[0] - scalar,
		m[1] - scalar,
		m[2] - scalar,
		m[3] - scalar
	};
	return Matrix2(f);
}
Matrix2 Matrix2::operator*(float &scalar)
{
	float f[4] =
	{
		m[0] * scalar,
		m[1] * scalar,
		m[2] * scalar,
		m[3] * scalar
	};
	return Matrix2(f);
}
Matrix2 Matrix2::operator*(Matrix2 &second)
{
	float f[4] =
	{
		m[0] * second.m[0] + m[1] * second.m[2],
		m[0] * second.m[1] + m[1] * second.m[3],
		m[1] * second.m[0] + m[2] * second.m[2],
		m[1] * second.m[1] + m[2] * second.m[3]
	};
	return Matrix2(f);
}