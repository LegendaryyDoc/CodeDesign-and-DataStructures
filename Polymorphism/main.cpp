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
#include "state.h"
#include "endScreenDrawing.h"
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

	GameState::GetInstance().setState(0); // what state it starts in
	GameState::GetInstance().getState();

	picker wiz("wizzard_f_idle_anim_f0.png", {200,200});
	picker bar("knight_f_idle_anim_f0.png", {500, 200});

	wizard urawizard("wizzard_f_idle_anim_f0.png");
	barb ogh("knight_f_idle_anim_f0.png");

	player * pl = nullptr;

	std::vector<enemy *> en; // creating enemy array

	en.push_back(new necromancer("necromancer_idle_anim_f0.png")); // adding enemies to the array
	en.push_back(new imp("imp_idle_anim_f0.png"));
	en.push_back(new imp("imp_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));
	en.push_back(new ogre("ogre_idle_anim_f0.png"));

	en.size();

	bool quit = false;

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

	for (int i = 0; i < en.size(); i++) // spawning enemies at random location
	{
		randNumX = rand() % 750;
		randNumY = rand() % 400;
		en[i]->position = { (float)(randNumX), (float)(randNumY) };
	}

	while (quit == false)
	{
		while (GameState::GetInstance().getState() == 0) // starting screen
		{
			wiz.CheckForClick(); // checking for a collision with wiz box and cursor
			if (wiz.CheckForClick())
			{
				pl = &urawizard; // setting player to be wizard
				pl->enabled = true;
				GameState::GetInstance().setState(1); // once wiz is picked changes state to play the game
			}

			bar.CheckForClick(); // checking for a collision with barb box and cursor
			if (bar.CheckForClick())
			{
				pl = &ogh; // setting player to be barbarian
				pl->enabled = true;
				GameState::GetInstance().setState(1); // once barb is picked changes state to play the game
			}

			BeginDrawing();

			ClearBackground(RAYWHITE);
			//Do Menu UI Screen here

			DrawText("Choose a character!", 250, 100, 20, MAROON);

			wiz.draw();                   // drawing wiz
			wiz.position = { 200, 200 };  // at this position

			bar.draw();                   // drawing barb
			bar.position = { 500, 200 };  // at this postion

			EndDrawing();
		}

		/*-----------------------------------------------------------*/

		while (GameState::GetInstance().getState() == 1) // game
		{
			Vector2 cursor = GetMousePosition();

			pl->moveTo({ cursor.x, cursor.y }); // moves to cursor

			if (!IsKeyDown(KEY_H))
			{
				for (int i = 0; i < en.size(); i++)
				{
					en[i]->follow(pl->position); // follows the player position
				}
			}

			for (int i = 0; i < en.size(); i++) // player taking damage if they collide
			{
				en[i]->rec.x = en[i]->position.x;
				en[i]->rec.y = en[i]->position.y;
				en[i]->rec.height = en[i]->mySprite.height;
				en[i]->rec.width = en[i]->mySprite.width;

				DrawRectangle(en[i]->rec.x, en[i]->rec.y, en[i]->rec.width, en[i]->rec.height, RAYWHITE);
				//DrawRectangle(en[i]->rec.x, en[i]->rec.y, en[i]->rec.width, en[i]->rec.height, RED);

				pl->rec.x = pl->position.x;
				pl->rec.y = pl->position.y;
				pl->rec.height = pl->mySprite.height;
				pl->rec.width = pl->mySprite.width;

				DrawRectangle(pl->rec.x, pl->rec.y, pl->rec.width, pl->rec.height, RAYWHITE);
				//DrawRectangle(pl->rec.x, pl->rec.y, pl->rec.width, pl->rec.height, RED);

				if (CheckCollisionRecs(pl->rec, en[i]->rec))
				{
					pl->takeDamage(en[i]->damage);
				}
			}
			if (pl->death == true)
			{
				GameState::GetInstance().setState(2); // if dead goes to death screen
			}

			BeginDrawing();

			ClearBackground(RAYWHITE);

			if (IsKeyDown(KEY_H))
			{
				pl->draw(Color{ 255,255,255,90 }); // if H is down the player becomes more transparent and enemies will not follow
			}
			else if (!IsKeyDown(KEY_H))
			{
				pl->draw(WHITE); // draws player
			}

			for (int i = 0; i < en.size(); i++)
			{
				en[i]->draw(); // draws enemies
			}

			DrawText(std::to_string(pl->health / 10).c_str(), 725, 25, 25, RED);

			EndDrawing();
		}

		/*-----------------------------------------------------------*/

		finalForm skelChar("skull.png");

		necromancer n("necromancer_idle_anim_f0.png");
		n.position = { -50, 325 };
		n.speed = 2.0f;

		Vector2 followPos = { 850, 325 };

		float deathY = -10;

		while (GameState::GetInstance().getState() == 2) // death screen
		{
			BeginDrawing();

			n.follow(followPos);

			if (n.position.x > followPos.x - 30)
			{
				return 0;
			}

			ClearBackground(RAYWHITE);

			if (deathY < 125)
			{
				DrawText("YOU HAVE DIED!", 190, deathY, 50, RED); // shows text on screen
				deathY += .4;
			}
			else if (deathY >= 125)
			{
				DrawText("YOU HAVE DIED!", 190, deathY, 50, RED); // shows text on screen
			}

			skelChar.endDraw(WHITE);
			n.endDraw(WHITE);

			EndDrawing();
		}
	}
	return 0;
}

