#pragma once
#include <cmath>
#include <algorithm>

struct  Vector4
{
private:

	float v[4];

public:

	Vector4(float x, float y, float z, float w); 

	const float &x;
	const float &y;
	const float &z;
	const float &w;

	~Vector4();

	Vector4 operator+ (float &scalar);
	Vector4 operator- (float &scalar);
	Vector4 operator* (float &scalar);
	Vector4 operator/ (float &scalar);

	Vector4 operator+ (Vector4 &second);
	Vector4 operator- (Vector4 &second);
	Vector4& operator= (Vector4 other);
	//float operator* (Vector4 &second); //dot-product
	//float operator/  (Vector4 &second); //

	operator float* () { return v; };
	float &operator[](int i) { return v[i]; };

	static float Dot(Vector4 v1, Vector4 v2);
	float Length();
	void Normalize();
	Vector4 Normalized();
	static const Vector4 zero;

//	operator Vector2() { return Vector2(x, y); };
//	operator Vector3() { return Vector3(x, y, z); };
};

struct  Vector3
{
private:
	float v[3];
public:
	Vector3(float x, float y, float z);
	const float &x;
	const float &y;
	const float &z;
	~Vector3();

	Vector3& operator= (Vector3 other);
	operator Vector4() { return Vector4(x, y, z, 0); };
//	operator Vector2() { return Vector2(x, y); };
};

struct  Vector2
{

private:
	float v[2];
public:
	Vector2(float x, float y);
	const float &x;
	const float &y;

	~Vector2();

	static float Dot(Vector2 v1, Vector2 v2);
	float Length();
	void Normalize();
	Vector2 Normalized();

	static const Vector2 zero;
	static const Vector2 one;
	static const Vector2 up;
	static const Vector2 down;
	static const Vector2 left;
	static const Vector2 right;

	operator Vector4(){ return Vector4(x, y, 0, 0); };
	operator Vector3() { return Vector3(x, y, 0); };
	Vector2& operator= (Vector2 other);
	Vector2 operator+ (Vector2 &second);
	Vector2 operator- (Vector2 &second);
	Vector2 operator* (Vector2 &second);

	Vector2 operator+ (float &scalar);
	Vector2 operator- (float &scalar);
	Vector2 operator* (float &scalar);
	Vector2 operator/ (float &scalar);
};