#include "DebugHandler.h"

void DebugHandler::Log(std::string message, int type)
{
#ifdef DEBUG
	std::string str = "[DEBUG-";
	switch (type)
	{
		case 1:
			str += "WARNING] ";
			break;
		case 2:
			str += "ERROR] ";
			break;
		default:
			str += "LOG] ";
		break;
	}
	str += message;
	std::cout << str.c_str() << std::endl;
#endif
}

void DebugHandler::Log(Vector4 v4)
{
#ifdef DEBUG
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(4)  << v4.x << " | " <<
		std::fixed << std::setprecision(4) << v4.y << " | " <<
		std::fixed << std::setprecision(4) << v4.z << " | " <<
		std::fixed << std::setprecision(4) << v4.w;

	Log(ss.str());
#endif
}

void DebugHandler::LogError(std::string message)
{
	Log(message, 1);
}

void DebugHandler::LogWarning(std::string message)
{
	Log(message, 2);
}