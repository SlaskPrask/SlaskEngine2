#include "Player.h"



Player::Player()
{
	sprite = AddComponent<Sprite>();
	sprite->SetTexture("Assets\\Sprites\\head.png");
	sprite->SetShader("skin.frag");
	sprite->SetUniformVector("skin", Vector3(228.0f / 255, 214.0f / 255, 189.0f / 255));

	eyeSprite = AddComponent<Sprite>();
	eyeSprite->SetTexture("Assets\\Sprites\\eyes.png");
	eyeSprite->SetShader("eyeshader.frag");
	eyeSprite->SetUniformVector("eyes", Vector3(6.0f / 255, 152.0f / 255, 1));

	DebugHandler::Log("Hi, I'm player");
	AsyncHandler::StartThreadedFunction([this]() {Test(20); });
}

void Player::Update()
{
	if (InputHandler::GetKey(Keycode::RIGHT))
		Translate(Vector2(3,0));

	if (InputHandler::GetKey(Keycode::LEFT))
		Translate(Vector2(-3, 0));

	if (InputHandler::GetKey(Keycode::UP))
		Translate(Vector2(0, 3));

	if (InputHandler::GetKey(Keycode::DOWN))
		Translate(Vector2(0, -3));
}

void Player::LateUpdate()
{

}

void Player::Test(int j)
{
	for (int i = 0; i < j; i++)
	{
		DebugHandler::Log(std::to_string(i) + " < " + std::to_string(j));
		SlaskEngine2::GameObject::WaitForEndOfFrame();
	}
}


Player::~Player()
{
}
