#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "InputHandler.h"
#include "SlaskEngine2.h"

class Player : public GameObject
{
private:
	void Test(int j);
	GLuint eyeLoc;
	GLuint skinLoc;

public:
	Sprite* eyeSprite;
	Sprite* sprite;
	Player();
	~Player();

	void Update();
	void LateUpdate();
};

