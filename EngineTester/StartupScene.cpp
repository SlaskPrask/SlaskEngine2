#include "StartupScene.h"

Scene* StartupScene::Start()
{
	EngineHandler::getEngine().GetActiveCamera()->Scale(Vector2(8, 8));
	player = new Player();
	return this;
}