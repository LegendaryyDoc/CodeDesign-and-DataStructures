#include "player.h"
#include "raylib/raylib.h"
#include <iostream>

void player::moveTo()
{
	std::cout << "player moving" << std::endl;
}

void player::takeDamage(int damage)
{
	if (health > 0)
	{
		health -= damage;
		alive = true;
	}
	else
	{
		alive = false;
	}
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