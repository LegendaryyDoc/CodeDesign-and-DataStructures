#include "raylib.h"
#include "spells.h"
#include "tStack.h"
#include "tVector.h"
#include <iostream>

int main()
{
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	tStack<spells> currentSpell;
	bool loop = true;
	while (loop)
	{
		BeginDrawing();

		// do the key presses outside the switch
		if (IsKeyPressed(KEY_ONE))
		{
			if (currentSpell.empty())
			{
				currentSpell.push(Water);
			}
			else if (currentSpell.top() == Fire)
			{
				currentSpell.pop();
			}
			else if (currentSpell.top() == Lightning)
			{
				currentSpell.pop();
				currentSpell.push(IsThatWaterElectrified);
			}
			else
			{
				currentSpell.push(Water);
			}
		}
		else if (IsKeyPressed(KEY_TWO))
		{
			if (currentSpell.empty())
			{
				currentSpell.push(Fire);
			}
			else if (currentSpell.top() == Water)
			{
				currentSpell.pop();
			}
			else if (currentSpell.top() == Earth)
			{
				currentSpell.pop();
				currentSpell.push(Magma);
			}
			else
			{
				currentSpell.push(Fire);
			}
		}
		else if (IsKeyPressed(KEY_THREE))
		{
			if (currentSpell.empty())
			{
				currentSpell.push(Earth);
			}
			else if (currentSpell.top() == Lightning)
			{
				currentSpell.pop();
			}
			else if (currentSpell.top() == Fire)
			{
				currentSpell.pop();
				currentSpell.push(Magma);
			}
			else
			{
				currentSpell.push(Earth);
			}
		}
		else if (IsKeyPressed(KEY_FOUR))
		{
			if (currentSpell.empty())
			{
				currentSpell.push(Lightning);
			}
			else if (currentSpell.top() == Earth)
			{
				currentSpell.pop();
			}
			else if (currentSpell.top() == Water)
			{
				currentSpell.pop();
				currentSpell.push(IsThatWaterElectrified);
			}
			else
			{
				currentSpell.push(Lightning);
			}
		}

		// cast the spells
		if (IsKeyPressed(KEY_ENTER) && !currentSpell.empty())
		{
			// "cast every spell in the stack"
			while (!currentSpell.empty())
			{
				switch (currentSpell.top())
				{
				case Water:
					std::cout << "WATER" << std::endl;
					currentSpell.pop();
					break;
				case Fire:
					std::cout << "FIRE" << std::endl;
					currentSpell.pop();
					break;
				case Earth:
					std::cout << "EARTH" << std::endl;
					currentSpell.pop();
					break;
				case Lightning:
					std::cout << "LIGHTNING" << std::endl;
					currentSpell.pop();
					break;
				case IsThatWaterElectrified:
					std::cout << "IsThatWaterElectrified" << std::endl;
					currentSpell.pop();
						break;
				case Magma:
					std::cout << "Magma" << std::endl;
					currentSpell.pop();
					break;
				default:
					break;
				}
			}
		}

		ClearBackground(RAYWHITE);
		EndDrawing();
	}
	CloseWindow(); 
	return 0;
}