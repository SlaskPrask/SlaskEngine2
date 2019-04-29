#pragma once
#include "Entity.h"
#include <list>
#include "Component.h"
#include "DebugHandler.h"
#include "Sprite.h"
#include "AsyncHandler.h"

class Scene;

class  GameObject : public Entity
{
private:
	std::list<GameObject*> children;
	GameObject* parent;
	int depth;
	void RemoveChild(GameObject* obj)
	{
		children.remove(obj); //disown the child
	}

	std::list<Component*> components;
	std::list<Sprite*> sprites;

public:
	std::list<GameObject*>* GetChildren()
	{
		return &children;
	}
	bool _deleted;

	static void Destroy(GameObject *go);
	GameObject();
	GameObject(Scene* scene);
	GameObject(GameObject* parent);
	virtual ~GameObject();


	void Draw() 
	{
		if (!sprites.empty())
		{
			for (auto it = sprites.begin(); it != sprites.end(); it++)
			{
				(*it)->Update(GetMatrix());
				(*it)->Draw();
			}
		}
	}
	virtual void Update(){}
	virtual void LateUpdate(){}
	void SetDepth(int i);
	int GetDepth() const
	{
		return depth;
	}
	void AddChild(GameObject* obj)
	{
		children.push_back(obj); //adds child to this
		if (obj->GetParent() != NULL)
			obj->GetParent()->RemoveChild(obj); //Basically Adoption - Removes previous parent
		
		obj->SetParent(this);   //sets parent of new child to this
	}
	void SetParent(GameObject* obj);

	template <typename T>
	T* AddComponent() 
	{
		T* comp = new T;
		components.push_back(comp);
		if (typeid(T) == typeid(Sprite))
			sprites.push_back(comp);

		return comp;
	};

	template <typename T>
	T* GetComponent()
	{
		if (std::is_base_of<Component, T>())
		{
			for (auto it = components.begin(); it != components.end(); it++)
			{
				if (typeid(T) == typeid(*it))
					return *(it);
			}
		}

		DebugHandler::LogError(typeid(T).name + "is not a component");
		return NULL;
	}

	GameObject* GetParent()
	{
		return parent;
	}
};

