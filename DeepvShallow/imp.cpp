#include "imp.h"
#include "raylib/raylib.h"
#include <iostream>
#include <string>

void imp::draw()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
}

void imp::endDraw(Color h)
{
	DrawTextureEx(mySprite, position, 0, 3, h);
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
	if (dest.x + 10 > position.x)
	{
		position.x += speed * 2 * GetFrameTime();
	}
	if (dest.x - 10 < position.x)
	{
		position.x -= speed * 2 * GetFrameTime();
	}
	if (dest.y + 10 > position.y)
	{
		position.y += speed * 2 *GetFrameTime();
	}
	if (dest.y - 10 < position.y)
	{
		position.y -= speed * 2 * GetFrameTime();
	}
	return true;
}