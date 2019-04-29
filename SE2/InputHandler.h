#pragma once
#define NR_KEYS 73

#ifdef DEBUG
#include "include_debug/include/glad/glad.h"
#else
#include "include_release/glad/glad.h"
#endif

#include "GLFW/glfw3.h"


enum Keycode
{
	A = GLFW_KEY_A,
	B = GLFW_KEY_B,
	C = GLFW_KEY_C,
	D = GLFW_KEY_D,
	E = GLFW_KEY_E,
	F = GLFW_KEY_F,
	G = GLFW_KEY_G,
	H = GLFW_KEY_H,
	I = GLFW_KEY_I,
	J = GLFW_KEY_J,
	K = GLFW_KEY_K,
	L = GLFW_KEY_L,
	M = GLFW_KEY_M,
	N = GLFW_KEY_N,
	O = GLFW_KEY_O,
	P = GLFW_KEY_P,
	Q = GLFW_KEY_Q,
	R = GLFW_KEY_R,
	S = GLFW_KEY_S,
	T = GLFW_KEY_T,
	U = GLFW_KEY_U,
	V = GLFW_KEY_V,
	W = GLFW_KEY_W,
	X = GLFW_KEY_X,
	Y = GLFW_KEY_Y,
	Z = GLFW_KEY_Z,
	UP = GLFW_KEY_UP,
	DOWN = GLFW_KEY_DOWN,
	LEFT = GLFW_KEY_LEFT,
	RIGHT = GLFW_KEY_RIGHT,
	LEFT_CTRL = GLFW_KEY_LEFT_CONTROL,
	RIGHT_CTRL = GLFW_KEY_RIGHT_CONTROL,
	LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT,
	RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT,
	LEFT_ALT = GLFW_KEY_LEFT_ALT,
	RIGHT_ALT = GLFW_KEY_RIGHT_ALT,
	ESCAPE = GLFW_KEY_ESCAPE,
	SPACE = GLFW_KEY_SPACE,
	RETURN = GLFW_KEY_ENTER,
	ALPHA_1 = GLFW_KEY_1,
	ALPHA_2 = GLFW_KEY_2,
	ALPHA_3 = GLFW_KEY_3,
	ALPHA_4 = GLFW_KEY_4,
	ALPHA_5 = GLFW_KEY_5,
	ALPHA_6 = GLFW_KEY_6,
	ALPHA_7 = GLFW_KEY_7,
	ALPHA_8 = GLFW_KEY_8,
	ALPHA_9 = GLFW_KEY_9,
	ALPHA_0 = GLFW_KEY_0,
	NUM_1 = GLFW_KEY_KP_1,
	NUM_2 = GLFW_KEY_KP_2,
	NUM_3 = GLFW_KEY_KP_3,
	NUM_4 = GLFW_KEY_KP_4,
	NUM_5 = GLFW_KEY_KP_5,
	NUM_6 = GLFW_KEY_KP_6,
	NUM_7 = GLFW_KEY_KP_7,
	NUM_8 = GLFW_KEY_KP_8,
	NUM_9 = GLFW_KEY_KP_9,
	NUM_0 = GLFW_KEY_KP_0,
	NUM_ENTER = GLFW_KEY_KP_ENTER,
	NUM_PLUS = GLFW_KEY_KP_ADD,
	F1 = GLFW_KEY_F1,
	F2 = GLFW_KEY_F2,
	F3 = GLFW_KEY_F3,
	F4 = GLFW_KEY_F4,
	F5 = GLFW_KEY_F5,
	F6 = GLFW_KEY_F6,
	F7 = GLFW_KEY_F7,
	F8 = GLFW_KEY_F8,
	F9 = GLFW_KEY_F9,
	F10 = GLFW_KEY_F10,
	F11 = GLFW_KEY_F11,
	F12 = GLFW_KEY_F12
};

struct Key
{
	Keycode code;
	int state;
};

class InputHandler
{
	static Key key[NR_KEYS];

public:	
	static void Init();
	static void key_callback(GLFWwindow* window, int _key, int scancode, int action, int mods);
	static bool GetKeyDown(Keycode _key);
	static bool GetKeyUp(Keycode _key);
	static bool GetKey(Keycode _key);
	static void CheckNegativeOne();

	InputHandler();
	~InputHandler();
};


