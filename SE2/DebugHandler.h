#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Vector.h"

class  DebugHandler
{

public:

	static void Log(std::string message, int type = 0);
	static void Log(Vector4 v4);

	static void LogError(std::string message);
	static void LogWarning(std::string message);

};