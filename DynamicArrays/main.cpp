#include "raylib.h"
#include "tVecor.h"
#include "enemy.h"
#include "tStack.h"
#include "tQueue.h"
#include "command.h"
#include "entity.h"
#include <iostream>
#include <ctime>

void printTop(const tQueue<int> &q)
{
	std::cout << q.front() << std::endl;
}

int main()
{
	Vector2 cursor = GetMousePosition();

	srand(time(NULL));

	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	entity player("big_zombie_idle_anim_f3.png");

	//tVector<enemy*> original;
	//tQueue<int> que;
	/*tStack<int> en;
	en.push(6);
	en.push(7);
	en.pop();*/

	//que.push(5);
	//que.push(6);

	/*while (!que.size())
	{
		std::cout << "Front: " << que.front() << std::endl;
		que.pop();
	}*/

	//std::cout << "Last Number: " << en.top() << std::endl;
	
	//std::cout << en.empty() << std::endl;

	while (!WindowShouldClose())    
	{
		BeginDrawing();

		player.update(GetFrameTime());

		if (IsMouseButtonPressed(0))
		{
			auto move = new moveCommand();
			move->dest = GetMousePosition();
			player.com.push(move);
		}

		/*if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{	
			original.push_back(new enemy("big_zombie_idle_anim_f3.png"));
			original[original.size() - 1]->pos = cursor;
			original[original.size() - 1]->velocity.x = rand() % 8 + -4;
			original[original.size() - 1]->velocity.y = rand() % 8 + -4;
		}

		for (int i = 0; i < original.size(); i++)
		{
			original[i]->update();
		}*/

		ClearBackground(RAYWHITE);

		/*for (int i = 0; i < original.size(); i++)
		{
			original[i]->draw();
		}*/
		player.draw();

		EndDrawing();
	}
	CloseWindow(); 
	return 0;
}