#include "wizard.h"
#include "raylib.h"
#include <iostream>
#include <string>

void wizard::draw()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
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

bool wizard::moveTo(const Vector2 & dest)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 cursor = GetMousePosition();

		position.x = dest.x;
		position.y = dest.y;

		return true;
	}
	return false;
}
