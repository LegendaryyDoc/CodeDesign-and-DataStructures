#include "raylib.h"
#include "min.h"
#include "max.h"
#include "gameObject.h"
#include "ninja.h"
#include "soldier.h"
#include <iostream>

int main()
{
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	Vector2 cursor = GetMousePosition();

	/*   Min  --  Max   */
	/*
	int a = min(3, 4);  // 3
	int b = min(3, 3);  // 3
	int c = min(99, 0); // 0

	int d = max(7, 10); // 10
	int e = max(5, 0);  // 5
	int f = max(6, 6);  // 6

	std::cout << "Min: " << a << std::endl;
	std::cout << "Min: " << b << std::endl;
	std::cout << "Min: " << c << std::endl;
	std::cout << "Max: " << d << std::endl;
	std::cout << "Max: " << e << std::endl;
	std::cout << "Max: " << f << std::endl;
	*/

	ninja myNinja;
	soldier mySoldier;

	gameObject<ninja> myGameObject(myNinja);
	myGameObject.enabled = myNinja.enabled;
	gameObject<soldier> myGameObject2(mySoldier);
	myGameObject2.enabled = mySoldier.enabled;

	while (!WindowShouldClose())   
	{
		myGameObject.update(GetFrameTime());
		myGameObject2.update(GetFrameTime());

		BeginDrawing();

		ClearBackground(RAYWHITE);

		myGameObject.render();
		myGameObject2.render();

		EndDrawing();
	}
	CloseWindow();      

	return 0;
}