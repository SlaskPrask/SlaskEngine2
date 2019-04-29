#define STB_IMAGE_IMPLEMENTATION
#include "SlaskEngine2.h"

#ifndef E_DLL
int main()
{
	Scene* t = new Scene;
	EngineHandler::getEngine().StartTheEngine("best window", t);
}
#endif