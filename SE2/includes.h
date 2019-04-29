#pragma once



#ifdef DEBUG
#include "include_debug/include/glad/glad.h"
#else
#include "include_release/glad/glad.h"
#endif

#include <GLFW/glfw3.h>
#include "DebugHandler.h"
#include <iostream>