#include "Entity.h"



void Entity::Scale(Vector2 _scale)
{
	scale = _scale;
	RefreshMatrix();
}

void Entity::Translate(Vector2 _translate)
{
	position = position + _translate;
	RefreshMatrix();
}


void Entity::SetPosition(Vector2 _position)
{
	position = _position;
	RefreshMatrix();
}

void Entity::Rotate(float radians)
{
	rotation = radians;
	RefreshMatrix();
}

void Entity::RefreshMatrix()
{
	transform = Matrix4(1) * Matrix4::Rotation(rotation) * Matrix4::Translation(Vector3(position.x, position.y, 0)) * Matrix4::Scaling(Vector3(scale.x, scale.y, 1));
}

Entity::Entity()
{
}


Entity::~Entity()
{
}
