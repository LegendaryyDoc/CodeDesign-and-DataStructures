/*********************************************************/

/*   Wizard Teleports To Mouse Location On Left CLick    */

/*********************************************************/

/* Knight Moves Towards The Mouse Location On Left Click */
/*  If Shift And Left Click Knight Will Sprint Towards   */

/*********************************************************/

#include "raylib.h"
#include "player.h"
#include "picker.h"'
#include "wizard.h"
#include "imp.h"
#include "ogre.h"
#include "necromancer.h"
#include "enemy.h"
#include "barbarian.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

int main()
{
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	srand(time(NULL));

	picker wiz("wizzard_f_idle_anim_f0.png", {200,200});
	picker bar("knight_f_idle_anim_f0.png", {500, 200});

	wizard urawizard("wizzard_f_idle_anim_f0.png");
	barb ogh("knight_f_idle_anim_f0.png");

	player * pl = nullptr;
	
	std::vector<enemy *> en;

	en.push_back(new necromancer("necromancer_idle_anim_f0.png"));
	en.push_back(new necromancer("necromancer_idle_anim_f0.png"));
	en.push_back(new necromancer("necromancer_idle_anim_f0.png"));
	en.push_back(new necromancer("necromancer_idle_anim_f0.png"));
	en.push_back(new necromancer("necromancer_idle_anim_f0.png"));
	en.push_back(new imp("imp_idle_anim_f0.png"));
	en.push_back(new imp("imp_idle_anim_f0.png"));
	en.push_back(new imp("imp_idle_anim_f0.png"));
	en.push_back(new imp("imp_idle_anim_f0.png"));
	en.push_back(new imp("imp_idle_anim_f0.png"));
	en.push_back(new imp("imp_idle_anim_f0.png"));
	en.push_back(new imp("imp_idle_anim_f0.png"));
	en.push_back(new imp("imp_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));
	

	en.size();

	/*   Old Version For Enemy   */
	/*enemy * en[10];

	en[0] = new necromancer("necromancer_idle_anim_f0.png");
	en[1] = new imp("imp_idle_anim_f0.png");
	en[2] = new imp("imp_idle_anim_f0.png");
	en[3] = new imp("imp_idle_anim_f0.png");
	en[4] = new ogre("ogre_idle_anim_f0.png");
	en[5] = new ogre("ogre_idle_anim_f0.png");
	en[6] = new ogre("ogre_idle_anim_f0.png");
	en[7] = new imp("imp_idle_anim_f0.png");
	en[8] = new imp("imp_idle_anim_f0.png");
	en[9] = new necromancer("necromancer_idle_anim_f0.png");
	*/

	int randNumX = rand() % 750;
	int randNumY = rand() % 400;

	for (int i = 0; i < en.size(); i++)
	{
		randNumX = rand() % 750;
		randNumY = rand() % 400;
		en[i]->position = { (float)(randNumX), (float)(randNumY) };
	}

	bool waitingForChoice = true;
	while (waitingForChoice)
	{
		wiz.CheckForClick();
		if (wiz.CheckForClick())
		{
			pl = &urawizard;
			pl->enabled = true;
			waitingForChoice = false;
		}

		bar.CheckForClick();
		if (bar.CheckForClick())
		{
			pl = &ogh;
			pl->enabled = true;
			waitingForChoice = false;
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);
		//Do Menu UI Screen here

		DrawText("Choose a character!", 250, 100, 20, MAROON);

		wiz.draw();
		wiz.position = { 200, 200 };

		bar.draw();
		bar.position = { 500, 200 };

		EndDrawing();
	}

	/*-----------------------------------------------------------*/

	while (!WindowShouldClose())
	{
		Vector2 cursor = GetMousePosition();

		pl->moveTo({cursor.x, cursor.y});

		if (!IsKeyDown(KEY_H))
		{
			for (int i = 0; i < en.size(); i++)
			{
				en[i]->follow(pl->position);
			}
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);

		if (IsKeyDown(KEY_H)) 
		{
			pl->draw(Color{255,255,255,90});
		}
		else if (!IsKeyDown(KEY_H))
		{
			pl->draw(WHITE);
		}

		for (int i = 0; i < en.size(); i++)
		{
			en[i]->draw();
		}

		EndDrawing();
	}
	CloseWindow();       

	return 0;
}
