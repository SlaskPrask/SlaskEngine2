#pragma once
#include "EngineHandler.h"
#include "Scene.h"

namespace SlaskEngine2
{
	namespace SE2
	{
		static void StartEngine(const char* gameName, Scene* startScene)
		{
			EngineHandler::getEngine().StartTheEngine(gameName, startScene);
		}
	}
	namespace GameObject
	{
		static void StartThreadFunction(std::function<void()> lambdaFunction)
		{
			AsyncHandler::StartThreadedFunction(lambdaFunction);
		}
		
		static void WaitForSeconds(float seconds)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(int(seconds * 1000)));
		}
		
		static void WaitForEndOfFrame()
		{
			EngineHandler::getEngine().currentFrameMutex->wait();
		}
	}
	namespace Input
	{
		
	}
}
