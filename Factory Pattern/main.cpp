#include<iostream>
#include <string>
#include "IBox.h"
#include "IFactory.h"
#include "Factory.h"
#include "FallingFactory.h"
#include "SimpleSprite.h"
#include "tObjectPool.h"
#include "raylib.h"

#include <ctime>

#include <vector>

int main()
{
	srand(time(NULL));

	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	FallingFactory::init();



	/*-------   Old Version   -------*/
	/*std::vector<SimpleSprite*> sprites;
	
	float nTimer = 2.0f;
	float cTimer = 5.0f;

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		nTimer += GetFrameTime();
		cTimer += GetFrameTime();
		
		if (nTimer > 2.0f)
		{
			nTimer = 0;

			sprites.push_back(FallingFactory::getFromType("rock"));
		}

		if (cTimer > 5.0f)
		{
			cTimer = 0;
			sprites.push_back(sprites[rand() % sprites.size()]->Clone());
			std::cout << "\n";
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);

		for (int i = 0; i < sprites.size(); ++i)
		{
			sprites[i]->translate({ 0, 50 * GetFrameTime() });
			sprites[i]->draw();
			if (sprites[i]->r2.y > screenHeight)
			{
				sprites[i]->r2.y = -100;
			}
		}
		EndDrawing();
	}
	CloseWindow();*/ 

	/*-------   New Version   -------*/
	tObjectPool<SimpleSprite> sprites(10);
	std::vector<SimpleSprite*> render;

	float nTimer = 2.0f;

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		nTimer += GetFrameTime();
		
		if (sprites.free)
		{
			if (nTimer > 2.0f)
			{
				nTimer = 0;
				SimpleSprite* temp = sprites.retrieve();
				render.push_back[FallingFactory::getFromType("rock")] = sprites;
			}
		}
		BeginDrawing();

		ClearBackground(RAYWHITE);

		for (int i = 0; i < sprites.capacity(); ++i)
		{
			if (render[i]->pos.y < screenHeight)
			{

			}
			else
			{
				render[i]->translate({ 0, 50 * GetFrameTime() });
				render[i]->draw();
				if (render[i]->r2.y > screenHeight)
				{
					render[i]->r2.y = -100;
				}
			}
		}
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
