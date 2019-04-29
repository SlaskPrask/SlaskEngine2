#include "ResourceHandler.h"


std::string ResourceHandler::LoadResource(const char* resourceFile, const char* resourceName)
{
	path = fs::current_path();
#ifdef E_DLL
	path.append("Resources\\");
#else
	path.append("Resources\\Compiled\\");
#endif
	path.append(resourceFile);
	std::string allContent;
	std::fstream resource;

	resource.exceptions(std::fstream::failbit | std::fstream::badbit);


	try
	{
		resource.open(path.string());
		std::stringstream buff;
		buff << resource.rdbuf();
		resource.close();
		allContent = buff.str();
	}
	catch (std::fstream::failure e)
	{
		DebugHandler::LogError(e.what());
	}
	std::string startThing = startOfFile + resourceName + ">";

	int start = allContent.find(startThing) + startThing.length();

	allContent = allContent.substr(start);
	allContent = allContent.substr(0, allContent.find(endOfFile));

	if (resourceName == "default.vert")
		vertDef = allContent;
	if (resourceName == "default.frag")
		fragDef = allContent;
	
	path = fs::current_path();
#ifdef E_DLL
	path.append("Resources\\");
#else
	path.append("Resources\\Compiled\\");
#endif

	return allContent;
}


bool ResourceHandler::LoadResources()
{
	return true;
}

#ifdef DEBUG
#ifndef E_DLL
void ResourceHandler::CompileResources()
{ 
	fs::path path = fs::current_path();
	path.append("Resources\\");
	fs::path compiledPath = path;
	compiledPath.append("Compiled\\");

	fs::remove_all(compiledPath);
	fs::create_directory(compiledPath);

	for (auto& p : fs::recursive_directory_iterator(path))
	{
		if (p.status().type() == fs::file_type::directory)
		{
			if (p.path().filename() == "Compiled")
				continue;

			// pack stuff into one file
			std::string resourceName = p.path().filename().string() + ".res";
			std::fstream file;
			file.open(compiledPath.string() + resourceName, std::fstream::out);
			
			for (auto& f : fs::recursive_directory_iterator(p.path()))
			{
				std::fstream temp;

				temp.exceptions(std::fstream::failbit | std::fstream::badbit);

				try
				{
					temp.open(f.path().string());
					file << startOfFile << f.path().filename() << ">";
					file << temp.rdbuf();
					file << endOfFile;
					temp.close();
				}
				catch (std::fstream::failure e)
				{
					DebugHandler::LogError(e.what());
				}

			}
			file.close();	
		}
	}
}

#endif
#endif

std::string ResourceHandler::endOfFile = "<EOF>";
std::string ResourceHandler::startOfFile = "<SOF=";
std::string ResourceHandler::vertDef = "";
std::string ResourceHandler::fragDef = "";
fs::path ResourceHandler::path= fs::current_path();