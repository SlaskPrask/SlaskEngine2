#pragma once

#include "includes.h"
#include "Camera.h"
#include "Sprite.h"
#include "Matrix.h"
#include "sMath.h"
#include "shader.h"
#include "Scene.h"
#include "ResourceHandler.h"
#include "InputHandler.h"
#include "AsyncHandler.h"
#include <mutex>

class  EngineHandler
{
public:

	static EngineHandler& getEngine() //Getter function
	{
		static EngineHandler instance;
		return instance;
	}

private:

	

#ifdef E_DLL
	
	DWORD hMod;
	void GetHmodule(DWORD& _hMod);
	
#else

	GameObject* testObject;

#endif

	EngineHandler();
	bool sortDepth;

	bool running;

	void GameLogic();
	Shader* InitDefaultShaders();
	int frameRate;
	GLFWwindow* window;

	void glOrtho(const float &b, const float &t, const float &l, const float &r, const float &n, const float &f);

	Matrix4 ortho = Matrix4(0.0f);
	Camera *activeCamera;
	Scene *activeScene;
	Scene *nextScene;
	Shader *defShader;

public:
	
	AutoDeletionMutex* currentFrameMutex;

	void Update();
	static int height;
	static int width;


	Shader* GetDefaultShader()
	{
		return defShader;
	}

	void SetActiveCamera(Camera *cam)
	{
		activeCamera = cam;
	};

	Scene* GetActiveScene()
	{
		return activeScene;
	}

	Camera* GetActiveCamera()
	{
		return activeCamera;
	};

	void QueueDepthSort()
	{
		sortDepth = true;
	}

	void StartTheEngine(const char* gameName, Scene* startupScene);
	Matrix4 getOrtho();

	EngineHandler(EngineHandler const&) = delete;
	void operator=(EngineHandler const&) = delete;

	~EngineHandler();
};

