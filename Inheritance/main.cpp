#include <iostream>
#include "raylib/raylib.h"
#include "basicSprite.h"

int main()
{
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	
	Sprite dug;
	dug.x = 100;
	dug.y = 100;

	while (!WindowShouldClose()) 
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		dug.Draw();

		EndDrawing();
	}

	CloseWindow();       

	return 0;
}