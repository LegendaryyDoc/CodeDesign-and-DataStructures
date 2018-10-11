#include "potion.h"
#include <iostream>
#include "raylib/raylib.h"
#include <ctime>

potion::potion()
{
	std::cout << "Potion created!" << std::endl;

	texture = LoadTexture("potion_01c.png");
}

potion::potion(bool _enabled)
{
	enabled = _enabled;
	if (enabled)
	{
		
	}
}

potion::~potion()
{
	std::cout << "Potion destroyed!" << std::endl;

	UnloadTexture(texture);
}

void potion::refresh()
{
	srand(time(NULL));

	DrawTexture(texture, pos.x, pos.y, WHITE);
}
