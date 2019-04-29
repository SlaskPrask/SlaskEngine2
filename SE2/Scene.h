#pragma once
#include "GameObject.h"
#include <list>


class  Scene
{
private:

	GameObject* rootObject;
	std::list<GameObject*> renderList;
	std::list<GameObject*> deletionList;

	static bool depthCompare(const GameObject* first, const GameObject* second);
public:
	std::list<GameObject*>* GetRenderList()
	{
		return &renderList;
	}

	std::list<GameObject*>* GetDeleteList()
	{
		return &deletionList;
	}

	virtual Scene* Start() { return this; };
	void AddObject(GameObject* obj, bool rootIsParent = true);
	void SortDepth();
	void RemoveObject(GameObject *go);
	void DestroyObject(GameObject *go);
	GameObject* GetRootObject()
	{
		return rootObject;
	}
	Scene();
	virtual ~Scene();

	void Draw();
	void Update();
	void LateUpdate();
};

