#pragma once
#include <cmath>
#include "Vector.h"

struct  Matrix4
{
private:
	float m[16];
	Matrix4(float n[16]);
public:
	Matrix4(float init);
	~Matrix4();

	Matrix4 operator+ (float &scalar);
	Matrix4 operator- (float &scalar);
	Matrix4 operator* (float &scalar);

	Matrix4 operator* (const Matrix4 &second);
	operator float* () { return m; };
	static Matrix4 Rotation(float r);
	static Matrix4 Translation(Vector3 t);
	static Matrix4 Scaling(Vector3 s);
	
	void NewScale(Vector3 scale);
	void ScaleBy(Vector3 scale);
	void Translate(Vector3 translate);
	void Rotate(float r);
    Vector4 operator* (Vector4 &vec4);
	Matrix4& operator= (Matrix4 other);
};

struct Matrix3
{
private:
	float m[9];
	Matrix3(float n[9]);
public:
	Matrix3(float init);
	~Matrix3();

	Matrix3 operator+ (float &scalar);
	Matrix3 operator- (float &scalar);
	Matrix3 operator* (float &scalar);

	Matrix3 operator* (Matrix3 &second);
};

struct Matrix2
{
private:
	float m[4];
	Matrix2(float n[4]);
public:
	Matrix2(float init);
	~Matrix2();

	Matrix2 operator+ (float &scalar);
	Matrix2 operator- (float &scalar);
	Matrix2 operator* (float &scalar);

	Matrix2 operator* (Matrix2 &second);
};