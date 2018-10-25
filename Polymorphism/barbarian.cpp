#include "barbarian.h"
#include "raylib.h"
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

bool barb::moveTo(const Vector2 & dest)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && IsKeyDown(KEY_LEFT_SHIFT))
	{
		des = dest;
		speed = 15.0f;
	}

	else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		des = dest;
		speed = 5.0f;
	}

	if (des.x != position.x && des.y != position.y)
	{
		if (des.x > position.x)
		{
			position.x += speed;
		}
		if (des.x < position.x)
		{
			position.x -= speed;
		}
		if (des.y > position.y)
		{
			position.y += speed;
		}
		if (des.y < position.y)
		{
			position.y -= speed;
		}
	}
	return true;

	return false;
}
