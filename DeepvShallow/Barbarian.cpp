#include "Barbarian.h"
#include "raylib/raylib.h"
#include <iostream>
#include <string>

void barb::draw(Color h)
{
	DrawTexture(mySprite, position.x, position.y, h);
}

barb::barb(const std::string & fileName)
{
	std::cout << "Creating sprite!" << std::endl;
	mySprite = LoadTexture(fileName.c_str());
}

barb::~barb()
{
	std::cout << "Destroying sprite!" << std::endl;
	UnloadTexture(mySprite);
}

void barb::moveTo()
{
	if (IsKeyDown(KEY_W))
	{
		position.y -= speed;
	}
	if (IsKeyDown(KEY_S))
	{
		position.y += speed;
	}
	if (IsKeyDown(KEY_A))
	{
		position.x -= speed;
	}
	if (IsKeyDown(KEY_D))
	{
		position.x += speed;
	}
}
