#pragma once
#include "Matrix.h"
#include "Vector.h"

class  Entity
{
private:
	Vector2 scale = Vector2(1,1);
	Vector2 position = Vector2(0,0);
	float rotation = 0;
	Matrix4 transform = Matrix4(1);
	void RefreshMatrix();

public:
	Entity();
	~Entity();

	void Scale(Vector2 _scale);

	void Translate(Vector2 _translate);

	void SetPosition(Vector2 _position);

	void Rotate(float radians);

	Matrix4 GetMatrix()
	{
		return transform;
	};

};

