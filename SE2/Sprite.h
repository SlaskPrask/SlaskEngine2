#pragma once
#include <cmath>
#include "sMath.h"

#ifdef DEBUG
#include "include_debug/include/glad/glad.h"
#else
#include "include_release/glad/glad.h"
#endif

#include "GLFW/glfw3.h"
#include <iostream>
#include "DebugHandler.h"
#include "shader.h"
#include "Matrix.h"
#include "Texture.h"
#include "Component.h"
#include <list>

class  Sprite : public Component
{

private:

	struct uniformVector
	{
		GLuint location;	
		Vector3 vector = Vector3(0, 0, 0);

		uniformVector(GLuint loc, Vector3 v)
		{
			location = loc;
			vector = v;
		}

		uniformVector(const uniformVector& other) 
		{
			operator=(other);
		}
	};

	std::list<uniformVector> uniformVec;

	void Setup();
	float verts[12];
	float texcoords[8];
	unsigned int indices[6] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	unsigned int VBO;
	unsigned int EBO;
	unsigned int VAO;
	unsigned int TBO;
	Matrix4 translation = Matrix4(1);


public:
	void SetUniformVector(const char* name, Vector3 vec);
	void SetTexture(std::string tex2d_Path);
	void SetShader(std::string shader_name);
	Sprite();
	Sprite(std::string tex2d_Path);
	void Update(Matrix4 trans);
	Shader* shader;
	Texture *tex2d;
	

	void Draw();


	~Sprite();
};

