#include "SlaskEngine2.h"
#include "StartupScene.h"

using namespace SlaskEngine2::SE2;

int main()
{
	StartupScene* test = new StartupScene();
	StartEngine("New Game", test);
}