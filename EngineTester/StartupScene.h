#pragma once
#include "Scene.h"
#include "Player.h"

class StartupScene : public Scene
{
public:
	 Scene* Start();
	 Player* player;
};