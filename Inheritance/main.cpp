#include <iostream>
#include "raylib.h"
#include "basicSprite.h"
#include "button.h"
int main()
{
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	std::string arr[] = { "soldier_idle.png" , "soldier_walk1.png" };

	Button dug(arr, {100, 100}, 2);
	/*dug.x = 100;
	dug.y = 100;
*/
	while (!WindowShouldClose())
	{
		BeginDrawing();

		dug.CheckForClick();

		if (dug.CheckForClick() == true)
		{
			//std::cout << "Dug does something with his legs!" << std::endl;
			DrawText("Dug does something with his legs!", 190, 200, 20, DARKBLUE);
		}
		else
		{
			//std::cout << "Dug is just standing there... looking into the void!" << std::endl;
			DrawText("Dug is just standing there... looking into the void!", 190, 200, 20, MAROON);
		}
		
		ClearBackground(RAYWHITE);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}