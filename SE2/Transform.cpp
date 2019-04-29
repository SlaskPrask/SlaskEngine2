#include "Transform.h"



Transform::Transform()
{
}


Transform::~Transform()
{
}

void Transform::SetScale(Vector2 newScale)
{
	matrix.NewScale(newScale);
}

void Transform::ScaleBy(Vector2 percentage)
{
	matrix.ScaleBy(percentage);
}

void Transform::Translate(Vector2 translation)
{
	matrix.Translate(Vector3(translation.x, translation.y, 0));
}