#include "GameObject.h"
#include "EngineHandler.h"

GameObject::GameObject()
{
	EngineHandler::getEngine().GetActiveScene()->AddObject(this);
	SetDepth(0);

}

GameObject::GameObject(Scene* scene)
{
	scene->AddObject(this);
	SetDepth(0);
}

GameObject::GameObject(GameObject* parent)
{
	SetParent(parent);
	EngineHandler::getEngine().GetActiveScene()->AddObject(this, false);
	SetDepth(0);
}

void GameObject::Destroy(GameObject *go)
{
	for (auto it = go->GetChildren()->begin(); it != go->GetChildren()->end(); it++)
	{
		Destroy(*(it));
	}

	EngineHandler::getEngine().GetActiveScene()->DestroyObject(go);
	go->_deleted = true;
}

GameObject::~GameObject()
{
	if (EngineHandler::getEngine().GetActiveScene() != NULL)
		EngineHandler::getEngine().GetActiveScene()->RemoveObject(this);
}

void GameObject::SetDepth(int i)
{
	depth = i;
	EngineHandler::getEngine().QueueDepthSort();
}

void GameObject::SetParent(GameObject* obj)
{
	if (obj != NULL)
		parent = obj;
	else
		parent = EngineHandler::getEngine().GetActiveScene()->GetRootObject();
}
