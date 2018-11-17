#include "Wizard.h"
#include "raylib/raylib.h"
#include <iostream>
#include <string>

void wizard::draw(Color h)
{
	DrawTexture(mySprite, position.x, position.y, h);
}

wizard::wizard(const std::string & fileName)
{
	std::cout << "Creating sprite!" << std::endl;
	mySprite = LoadTexture(fileName.c_str());
}

wizard::~wizard()
{
	std::cout << "Destroying sprite!" << std::endl;
	UnloadTexture(mySprite);
}

void wizard::moveTo()
{
	if (IsKeyDown(KEY_W))
	{
		position.y -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_S))
	{
		position.y += speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_A))
	{
		position.x -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_D))
	{
		position.x += speed * GetFrameTime();
	}
}