#include "Vector.h"



Vector4::Vector4(float x, float y, float z, float w) : x(v[0]), y(v[1]), z(v[2]), w(v[3])
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = w;
}

Vector4::~Vector4()
{

}



float Vector4::Dot(Vector4 v1, Vector4 v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

Vector4 Vector4::operator+ (float &scalar)
{
	return Vector4(x + scalar, y + scalar, z + scalar, w + scalar);
}

Vector4 Vector4::operator- (float &scalar)
{
	return Vector4(x - scalar, y - scalar, z - scalar, w - scalar);
}
Vector4 Vector4::operator* (float &scalar)
{
	return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}
Vector4 Vector4::operator/ (float &scalar)
{
	return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}

Vector4 Vector4::operator+ (Vector4 &second)
{
	return Vector4(x + second.x, y + second.y, z + second.z, w + second.w);
}
Vector4 Vector4::operator- (Vector4 &second)
{
	return Vector4(x - second.x, y - second.y, z - second.z, w - second.w);
}

float Vector4::Length()
{
	return sqrtf(x * x + y * y + z * z + w * w);
}

void Vector4::Normalize()
{
	float l = Length();
	
	if (l != 0)
	{
		v[0] = x / l;
		v[1] = y / l;
		v[2] = z / l;
		v[3] = w / l;
	}
}

Vector4 Vector4::Normalized()
{
	float l = Length();
	if (l != 0)
	{
		return Vector4(x / l, y / l, z / l, w / l);
	}
	else
	{
		return zero;
	}
}

const Vector4 Vector4::zero = Vector4(0, 0, 0, 0);

Vector4& Vector4::operator= (Vector4 other) 
{
	std::swap(v, other.v);
	return *this;
}

Vector3& Vector3::operator= (Vector3 other)
{
	std::swap(v, other.v);
	return *this;
}

Vector2::Vector2(float x, float y) : x(v[0]), y(v[1]) 
{
	v[0] = x;
	v[1] = y;
}

Vector2::~Vector2()
{

}

Vector2& Vector2::operator= (Vector2 other)
{
	std::swap(v, other.v);
	return *this;
}

float Vector2::Dot(Vector2 v1, Vector2 v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

float Vector2::Length()
{
	return sqrtf(x * x + y * y);
}

void Vector2::Normalize()
{
	float l = Length();
	
	if (l != 0)
	{
		v[0] = x / l;
		v[1] = y / l;
	}
}

Vector2 Vector2::Normalized()
{
	float l = Length();

	if (l != 0)
	{
		return Vector2(x / l, y / l);
	}
	else
		return zero;
}

const Vector2 Vector2::zero = Vector2(0,0);
const Vector2 Vector2::one = Vector2(1, 1);
const Vector2 Vector2::up = Vector2(0, 1);
const Vector2 Vector2::down = Vector2(0, -1);
const Vector2 Vector2::left = Vector2(-1, 0);
const Vector2 Vector2::right = Vector2(1, 0);


Vector2 Vector2::operator+ (Vector2 &second)
{
	return Vector2(x + second.x, y + second.y);
}

Vector2 Vector2::operator- (Vector2 &second)
{
	return Vector2(x - second.x, y - second.y);
}

Vector2 Vector2::operator* (Vector2 &second)
{
	return Vector2(x * second.x, y * second.y);
}

Vector2 Vector2::operator+ (float &scalar)
{
	return Vector2(x + scalar, y + scalar);
}
Vector2 Vector2::operator- (float &scalar)
{
	return Vector2(x - scalar, y - scalar);
}
Vector2 Vector2::operator* (float &scalar)
{
	return Vector2(x * scalar, y * scalar);
}
Vector2 Vector2::operator/ (float &scalar)
{
	if (scalar == 0)
	{
		throw (EM_ZERODIVIDE);
	}
	else
		return Vector2(x / scalar, y / scalar);
}

Vector3::Vector3(float x, float y, float z) : x(v[0]), y(v[1]), z(v[2])
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

Vector3::~Vector3()
{

}
