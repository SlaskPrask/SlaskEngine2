#pragma once
#include "Matrix.h"
#include "Vector.h"
class Transform
{
private:
	Vector4 translationVector = Vector4(1, 0, 0, 1);

public:
	
	Matrix4 matrix = Matrix4(1);
	Vector2 position = Vector2(0,0);
	Vector2 scale = Vector2::one;
	float rotation = 0;


	void SetScale(Vector2 newScale);
	void ScaleBy(Vector2 percentage);
	void Translate(Vector2 translation);

	Transform();
	~Transform();
};

