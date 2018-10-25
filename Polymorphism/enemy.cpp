#include "enemy.h"
#include "raylib.h"
#include <iostream>

bool enemy::follow(const Vector2 & dest)
{
	if (dest.x > position.x)
	{
		position.x += speed;
	}
	if (dest.x < position.x)
	{
		position.x -= speed;
	}
	if (dest.y > position.y)
	{
		position.y += speed;
	}
	if (dest.y < position.y)
	{
		position.y -= speed;
	}
	return true;
}

enemy::enemy(const std::string & fileName)
{
	std::cout << "Creating sprite!" << std::endl;

	mySprite = LoadTexture(fileName.c_str());
}

enemy::enemy()
{
}

enemy::~enemy()
{
	std::cout << "Destroying sprite!" << std::endl;

	UnloadTexture(mySprite);
}

void enemy::draw()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
}