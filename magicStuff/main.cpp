#include "raylib.h"
#include "spells.h"
#include <iostream>

int main()
{
	spells currentSpell;
	// do the key presses outside the switch

	switch (currentSpell)
	{
	case Water:
		if (IsKeyPressed(KEY_ONE))
		{
			if (!Lightning == currentSpell)
			{
				std::cout << "WATER" << std::endl;
			}
		}
		break;
	case Fire:
		if (IsKeyPressed(KEY_TWO))
		{
			if (!Water == currentSpell)
			{
				std::cout << "FIRE" << std::endl;
			}
		}
		break;
	case Earth:
		if (IsKeyPressed(KEY_THREE))
		{
			if (!Fire == currentSpell)
			{
				std::cout << "EARTH" << std::endl;
			}
		}
		break;
	case Lightning:
		
		if (IsKeyPressed(KEY_FOUR))
		{
			if (!Earth == currentSpell)
			{
				std::cout << "LIGHTNING" << std::endl;
			}
		}
		break;
	default:
		break;
	}
}