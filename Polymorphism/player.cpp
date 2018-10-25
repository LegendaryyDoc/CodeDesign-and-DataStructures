#include "player.h"
#include "raylib.h"
#include <iostream>

bool player::moveTo(const Vector2 & dest)
{
	std::cout << "player moving" << std::endl;
	return false;
}

player::player(const std::string & fileName)
{
	std::cout << "Creating sprite!" << std::endl;

	mySprite = LoadTexture(fileName.c_str());
}

player::player()
{
}

player::~player()
{
	std::cout << "Destroying sprite!" << std::endl;

	UnloadTexture(mySprite);
}

void player::draw(Color h)
{
	DrawTexture(mySprite, 375, 225, h);
}
