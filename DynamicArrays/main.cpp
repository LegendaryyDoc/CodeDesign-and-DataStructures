#include "raylib.h"
#include "tVecor.h"
#include "enemy.h"
#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));

	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	tVector<enemy*> original;

	while (!WindowShouldClose())    
	{
		BeginDrawing();

		Vector2 cursor = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{	
			original.push_back(new enemy("big_zombie_idle_anim_f3.png"));
			original[original.size() - 1]->pos = cursor;
			original[original.size() - 1]->velocity.x = rand() % 8 + -4;
			original[original.size() - 1]->velocity.y = rand() % 8 + -4;
		}

		for (int i = 0; i < original.size(); i++)
		{
			original[i]->update();
		}

		ClearBackground(RAYWHITE);

		for (int i = 0; i < original.size(); i++)
		{
			original[i]->draw();
		}

		EndDrawing();
	}
	CloseWindow(); 
	return 0;
}