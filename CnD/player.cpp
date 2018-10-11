#include "player.h"
#include "raylib.h"
#include <iostream>

player::player()
{
	std::cout << "Player created!" << std::endl;
	draw();
}

player::player(float deltaTime, bool _enabled)
{
	enabled = _enabled;
	if (enabled)
	{
		update(deltaTime);
	}
}

player::~player()
{
	std::cout << "Player destroyed!" << std::endl;
}

void player::update(float deltaTime)
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

void player::draw()
{
	DrawCircle(pos.x, pos.y, radius, GREEN);
}