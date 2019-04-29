#include "Sprite.h"
#include "EngineHandler.h"


Sprite::Sprite()
{
	tex2d = NULL;
}

void Sprite::Setup()
{
	verts[0] = tex2d->width / 2.0f;
	verts[1] = tex2d->height / 2.0f;
	verts[2] = 1;

	verts[3] = tex2d->width / 2.0f;
	verts[4] = -tex2d->height / 2.0f;
	verts[5] = 1;

	verts[6] = -tex2d->width / 2.0f;
	verts[7] = -tex2d->height / 2.0f;
	verts[8] = 1;

	verts[9] = -tex2d->width / 2.0f;
	verts[10] = tex2d->height / 2.0f;
	verts[11] = 1;

	texcoords[0] = 1;
	texcoords[1] = 0;

	texcoords[2] = 1;
	texcoords[3] = 1;

	texcoords[4] = 0;
	texcoords[5] = 1;

	texcoords[6] = 0;
	texcoords[7] = 0;

	shader = EngineHandler::getEngine().GetDefaultShader();

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &TBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, TBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texcoords), texcoords, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

Sprite::Sprite(std::string tex2d_Path)
{
	tex2d = new Texture(tex2d_Path);
	Setup();
}

void Sprite::SetTexture(std::string tex2d_Path)
{
	tex2d = new Texture(tex2d_Path);
	Setup();
}

void Sprite::SetShader(std::string shader_name)
{
	shader = new Shader(shader_name);
}

void Sprite::Update(Matrix4 trans)
{
	translation = trans;
}
void Sprite::Draw()
{
	if (tex2d == NULL)
		return;

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,0, (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, TBO);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex2d->texture);

	shader->use();
	unsigned int transformLoc = glGetUniformLocation(shader->ID, "transform");	

	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, translation);

	if (!uniformVec.empty())
	{
		for (auto it = uniformVec.begin(); it != uniformVec.end(); it++)
		{
			glUniform3f((it)->location, (it)-> vector.x, (it)->vector.y, (it)->vector.z);
		}
	}


	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Sprite::SetUniformVector(const char* name, Vector3 vec)
{
	uniformVector uv(glGetUniformLocation(shader->ID, name), vec);
	uniformVec.push_back(uv);
}

Sprite::~Sprite()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &TBO);
}
