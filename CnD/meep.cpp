#include "meep.h"
#include <iostream>

meep::meep()
{
	std::cout << "Texture being created!" << std::endl;
	texture = LoadTexture("redTexture.png");
}

meep::meep(bool _enabled, bool playerEnabled, float deltaTime)
{
	enabled = _enabled;
	if (enabled)
	{
		refresh();
	}

	playerController = playerEnabled;

	if (playerController)
	{
		update(deltaTime);
	}
}

meep::~meep()
{
	std::cout << "Texture being destroyed!" << std::endl;

	UnloadTexture(texture);
}

void meep::refresh()
{

	int screenWidth = 800;
	int screenHeight = 450;
	

	DrawTexture(texture, pos.x, pos.y, WHITE);
}

void meep::update(float deltaTime)
{
	if (IsKeyDown(KEY_W))
	{
		pos.y -= speed * deltaTime;
	}
	if (IsKeyDown(KEY_S))
	{
		pos.y += speed * deltaTime;
	}
	if (IsKeyDown(KEY_A))
	{
		pos.x -= speed * deltaTime;
	}
	if (IsKeyDown(KEY_D))
	{
		pos.x += speed * deltaTime;
	}
}
