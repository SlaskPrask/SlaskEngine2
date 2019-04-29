#include "shader.h"
#include "EngineHandler.h"

void Shader::use() const
{
	glUseProgram(ID);


	if (proLoc != -1)
	{
		glUniformMatrix4fv(proLoc, 1, GL_FALSE, EngineHandler::getEngine().getOrtho());
	}
	if (camLoc != -1)
	{
		glUniformMatrix4fv(camLoc, 1, GL_FALSE, EngineHandler::getEngine().GetActiveCamera()->GetMatrix());
	}
}
