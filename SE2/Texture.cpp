#include "Texture.h"



Texture::Texture(bool smooth)
{
	_path = "AssetsTest/sprite.png";
	Load(smooth);
}

Texture::Texture(std::string path, bool smooth)
{
	_path = path;
	Load(smooth);
}

void Texture::Load(bool smooth)
{
	data = stbi_load(_path.c_str(), &width, &height, &nrChannels, 0);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, smooth ? GL_LINEAR : GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, smooth ? GL_LINEAR : GL_NEAREST);

	if (data)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	else
		DebugHandler::LogError(_path + " couldn't load properly");
	stbi_image_free(data);
}

Texture::~Texture()
{

}
