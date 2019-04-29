#include "Scene.h"
#include "Sprite.h"


Scene::Scene() //Always make scene before objects or else
{
	rootObject = new GameObject(this);

}


Scene::~Scene()
{
	delete rootObject;
}

void Scene::AddObject(GameObject* obj, bool rootIsParent)
{
	renderList.push_back(obj);

	if (rootIsParent)
	{
		if (rootObject != NULL)
		{
			rootObject->AddChild(obj);
		}
	}

}

void Scene::RemoveObject(GameObject *go)
{
	renderList.remove(go);
}

void Scene::DestroyObject(GameObject *go)
{
	deletionList.push_back(go);
}

void Scene::SortDepth()
{
	GetRenderList()->sort(depthCompare);
}

bool Scene::depthCompare(const GameObject* first, const GameObject* second)
{
	return first->GetDepth() < second->GetDepth();
}

void Scene::Draw()
{
	for (auto it = renderList.begin(); it != renderList.end(); it++)
	{
		(*(it))->Draw();
	}
}

void Scene::Update()
{
	//Run the update in sorting order
	for (auto it = renderList.begin(); it != renderList.end(); it++)
	{
		(*(it))->Update();
	}

	//Delete all objects that are destroyed during the update
	for (auto it = deletionList.begin(); it != deletionList.end();)
	{
		if ((*(it))->_deleted == true)
		{
			delete ((*it));
			it = deletionList.erase(it);
		}
		else
			++it;
	}
}

void Scene::LateUpdate()
{
	for (auto it = renderList.begin(); it != renderList.end(); it++)
	{
		(*(it))->LateUpdate();
	}

	//Delete all objects that are destroyed during the late update
	for (auto it = deletionList.begin(); it != deletionList.end();)
	{
		if ((*(it))->_deleted == true)
		{
			delete ((*it));
			it = deletionList.erase(it);
		}
		else
			++it;
	}

	deletionList.clear();
}