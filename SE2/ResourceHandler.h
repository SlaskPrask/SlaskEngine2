#pragma once
#include <filesystem>
#include <fstream>
#include "DebugHandler.h"

namespace fs = std::experimental::filesystem;


class ResourceHandler
{
private:

	static std::string endOfFile;
	static std::string startOfFile;

public:
	static std::string LoadResource(const char* resourceFile, const char* resourceName);
	static bool LoadResources();
	static std::string vertDef;
	static std::string fragDef;
	static fs::path path;
#ifdef DEBUG
#ifndef E_DLL
	static void CompileResources();
#endif
#endif
};

