#include "Camera.h"
#include "EngineHandler.h"


void Camera::SetActive()
{
	EngineHandler::getEngine().SetActiveCamera(this);
}

Camera::Camera()
{
}

Camera::~Camera()
{
}
