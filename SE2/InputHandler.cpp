#include "InputHandler.h"

void InputHandler::Init()
{
	key[0].code = Keycode::A;
	key[1].code = Keycode::B;
	key[2].code = Keycode::C;
	key[3].code = Keycode::D;
	key[4].code = Keycode::E;
	key[5].code = Keycode::F;
	key[6].code = Keycode::G;
	key[7].code = Keycode::H;
	key[8].code = Keycode::I;
	key[9].code = Keycode::J;
	key[10].code = Keycode::K;
	key[11].code = Keycode::L;
	key[12].code = Keycode::M;
	key[13].code = Keycode::N;
	key[14].code = Keycode::O;
	key[15].code = Keycode::P;
	key[16].code = Keycode::Q;
	key[17].code = Keycode::R;
	key[18].code = Keycode::S;
	key[19].code = Keycode::T;
	key[20].code = Keycode::U;
	key[21].code = Keycode::V;
	key[22].code = Keycode::W;
	key[23].code = Keycode::X;
	key[24].code = Keycode::Y;
	key[25].code = Keycode::Z;
	key[26].code = Keycode::UP;
	key[27].code = Keycode::DOWN;
	key[28].code = Keycode::LEFT;
	key[29].code = Keycode::RIGHT;
	key[30].code = Keycode::LEFT_ALT;
	key[31].code = Keycode::RIGHT_ALT;
	key[32].code = Keycode::LEFT_CTRL;
	key[33].code = Keycode::RIGHT_CTRL;
	key[34].code = Keycode::LEFT_SHIFT;
	key[35].code = Keycode::RIGHT_SHIFT;
	key[36].code = Keycode::ESCAPE;
	key[37].code = Keycode::RETURN;
	key[38].code = Keycode::SPACE;

	key[39].code = Keycode::ALPHA_0;
	key[40].code = Keycode::ALPHA_1;
	key[41].code = Keycode::ALPHA_2;
	key[42].code = Keycode::ALPHA_3;
	key[43].code = Keycode::ALPHA_4;
	key[44].code = Keycode::ALPHA_5;
	key[45].code = Keycode::ALPHA_6;
	key[46].code = Keycode::ALPHA_7;
	key[47].code = Keycode::ALPHA_8;
	key[48].code = Keycode::ALPHA_9;

	key[49].code = Keycode::NUM_0;
	key[50].code = Keycode::NUM_1;
	key[51].code = Keycode::NUM_2;
	key[52].code = Keycode::NUM_3;
	key[53].code = Keycode::NUM_4;
	key[54].code = Keycode::NUM_5;
	key[55].code = Keycode::NUM_6;
	key[56].code = Keycode::NUM_7;
	key[57].code = Keycode::NUM_8;
	key[58].code = Keycode::NUM_9;

	key[59].code = Keycode::NUM_ENTER;
	key[60].code = Keycode::NUM_PLUS;

	key[61].code = Keycode::F1;
	key[62].code = Keycode::F2;
	key[63].code = Keycode::F3;
	key[64].code = Keycode::F4;
	key[65].code = Keycode::F5;
	key[66].code = Keycode::F6;
	key[67].code = Keycode::F7;
	key[68].code = Keycode::F8;
	key[69].code = Keycode::F9;
	key[70].code = Keycode::F10;
	key[71].code = Keycode::F11;
	key[72].code = Keycode::F12;

	for (int i = 0; i < NR_KEYS; i++)
	{
		key[i].state = 0;
	}
}


void InputHandler::key_callback(GLFWwindow* window, int _key, int scancode, int action, int mods)
{
	for (int i = 0; i < NR_KEYS; i++)
	{
		if (_key == key[i].code)
		{
			if (action == GLFW_PRESS)
			{
				key[i].state = (key[i].state == 1) ? 2 : 1; //1 is just pressed, 2 is held down
			}
			
			if (action == GLFW_RELEASE)
				key[i].state = -1; //key just released
		}
	}
}

void InputHandler::CheckNegativeOne()
{
	for (int i = 0; i < NR_KEYS; i++)
	{
		if (key[i].state == -1)
			key[i].state = 0;
	}
}


bool InputHandler::GetKeyDown(Keycode _key)
{
	for (int i = 0; i < NR_KEYS; i++)
	{
		if (key[i].code == _key)
			return key[i].state == 1;
	}
	return false;
}

bool InputHandler::GetKeyUp(Keycode _key)
{
	for (int i = 0; i < NR_KEYS; i++)
	{
		if (key[i].code == _key)
			return key[i].state == -1;
	}
	return false;
}

bool InputHandler::GetKey(Keycode _key)
{
	for (int i = 0; i < NR_KEYS; i++)
	{
		if (key[i].code == _key)
			return key[i].state > 0;
	}
	return false;
}

InputHandler::InputHandler()
{
}


InputHandler::~InputHandler()
{
}

Key InputHandler::key[NR_KEYS];