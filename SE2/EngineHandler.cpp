#include "EngineHandler.h"



EngineHandler::EngineHandler()
{
	
}

void EngineHandler::StartTheEngine(const char* gameName, Scene* startupScene)
{

#ifdef DEBUG
#ifndef E_DLL
	ResourceHandler::CompileResources();
#endif
#endif

	DebugHandler::Log("Starting Engine");

	running = true;

	//Initialize glfw
	if (!glfwInit())
	{
		DebugHandler::LogError("Couldn't initialize GLFW");
		return;
	}

	window = glfwCreateWindow(width, height, gameName, NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		DebugHandler::LogError("Couldn't create window");
		return;
	}

	glfwMakeContextCurrent(window);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0f);

	glOrtho(-height / 2.0f, height / 2.0f, -width / 2.0f, width / 2.0f, -.1f, -100.0f);
	defShader = InitDefaultShaders();

	//Set framerate and camera
	InputHandler::Init();
	glfwSetKeyCallback(window, InputHandler::key_callback);
	frameRate = 60;
	double nextFrame = glfwGetTime();
	double currentFrame = glfwGetTime();

	activeCamera = new Camera();


#ifdef E_DLL
	nextScene = startupScene;
#else
	delete startupScene;
	activeScene = new Scene();
	testObject = new GameObject();
	testObject->AddComponent<Sprite>();
	AsyncHandler::StartThreadedFunction([this]() { Update(); });
#endif
	currentFrameMutex = new AutoDeletionMutex();

	while (!glfwWindowShouldClose(window))
	{

		currentFrameMutex->lock();

		nextFrame = glfwGetTime() + ((double)1000/(double)frameRate);
		

		glClearColor(0, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
		
		if (activeScene != NULL)
		{
			if (nextScene != NULL)
			{ 
				Scene* tempPointer = activeScene;
				activeScene = nextScene; 
				activeScene->Start();
				delete tempPointer;
				nextScene = NULL;
			}

			if (sortDepth)
			{
				activeScene->SortDepth();
				sortDepth = false;
			}
			//GameUpdateStuff
			GameLogic();
		}
		else
		{
			if (nextScene != NULL)
			{
				activeScene = nextScene;
				activeScene->Start();
				nextScene = NULL;
			}
		}


		glfwSwapBuffers(window);
		InputHandler::CheckNegativeOne();

		currentFrame = glfwGetTime();

		if (nextFrame > currentFrame) //lock to framerate
		{
			Sleep((DWORD)(nextFrame - currentFrame));
		}
		else
		{
			std::cout << "Lag" << std::endl;
		}
		AutoDeletionMutex* release = currentFrameMutex;
		currentFrameMutex = new AutoDeletionMutex();
		release->unlock();
	}
}

int EngineHandler::height = 720;
int EngineHandler::width = 1280;

#ifndef E_DLL
void EngineHandler::Update()
{
	for (int i = 0; i < 100; i++)
	{
		DebugHandler::Log("This is test: " + std::to_string(i));
	}

}
#endif

Shader* EngineHandler::InitDefaultShaders()
{
	return new Shader(ResourceHandler::LoadResource("Shaders.res", "default.vert"),
		ResourceHandler::LoadResource("Shaders.res", "default.frag"));
}

#ifdef E_DLL
void EngineHandler::GetHmodule(DWORD& _hMod)
{
	MEMORY_BASIC_INFORMATION mbi;
	static int dummy;
	VirtualQuery(&dummy, &mbi, sizeof(mbi));
	_hMod = (DWORD)mbi.AllocationBase;
}
#endif

EngineHandler::~EngineHandler()
{
	glfwTerminate();

	delete defShader;
	delete activeCamera;
}

void EngineHandler::glOrtho(const float &b, const float &t, const float &l, const float &r, const float &n, const float &f)
{
	ortho[0] = 2 / (r - l);
	ortho[1] = 0;
	ortho[2] = 0;
	ortho[3] = 0;

	ortho[4] = 0;
	ortho[5] = 2 / (t - b);
	ortho[6] = 0;
	ortho[7] = 0;

	ortho[8] = 0;
	ortho[9] = 0;
	ortho[10] = -2 / (f - n);
	ortho[11] = 0;

	ortho[12] = -(r+l)/(r-l);
	ortho[13] = -(t+b)/(t-b);
	ortho[14] = -(f+n)/(f-n);
	ortho[15] = 1;
}

Matrix4 EngineHandler::getOrtho()
{
	return ortho;
}

void EngineHandler::GameLogic()
{
	activeScene->Update();
	activeScene->Draw();
	activeScene->LateUpdate();
}