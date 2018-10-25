#include "imp.h"
#include "raylib.h"
#include <iostream>
#include <string>

void imp::draw()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
}

imp::imp(const std::string & fileName)
{
	std::cout << "Creating sprite!" << std::endl;
	mySprite = LoadTexture(fileName.c_str());
}

imp::~imp()
{
	std::cout << "Destroying sprite!" << std::endl;
	UnloadTexture(mySprite);
}

bool imp::follow(const Vector2 & dest)
{
	if (dest.x + 20 > position.x)
	{
		position.x += speed;
	}
	if (dest.x - 20 < position.x)
	{
		position.x -= speed;
	}
	if (dest.y + 20 > position.y)
	{
		position.y += speed;
	}
	if (dest.y - 20 < position.y)
	{
		position.y -= speed;
	}
	return true;
}