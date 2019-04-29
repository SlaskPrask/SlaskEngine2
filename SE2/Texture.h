#pragma once

#ifdef DEBUG
#include "include_debug/include/glad/glad.h"
#else
#include "include_release/glad/glad.h"
#endif

#include "stb_image.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "DebugHandler.h"
#include "Matrix.h"

class  Texture
{
private:


	unsigned char *data;

public:
	std::string _path;
	int width;
	int height;
	int nrChannels;
	unsigned int texture;
	void Load(bool smooth = false);

	Texture(bool smooth = false);
	Texture(std::string path, bool smooth = false);
	~Texture();
};

