#include<iostream>
#include <string>
#include "IBox.h"
#include "IFactory.h"
#include "Factory.h"
#include "FallingFactory.h"
#include "SimpleSprite.h"
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

	std::vector<SimpleSprite*> sprites;
	
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
	CloseWindow();        
	return 0;
}
