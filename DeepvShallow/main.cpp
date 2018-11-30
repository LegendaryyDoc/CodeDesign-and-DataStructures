#include <cassert>
#include "raylib/raylib.h"
#include "tile.h"
#include "enemy.h"
#include "imp.h"
#include "master.h"
#include "wizAttack.h"
#include "endScreneDrawing.h"
#include "Wizard.h"
#include "player.h"
#include "buttonClick.h"
#include "Barbarian.h"
#include "highScoreTable.h"
#include <vector>
#include <ctime>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>

void loadMap(std::string fileName, masterTile &master);

int main()
{
	InitWindow(832, 448, "pixel art game");
	srand(time(NULL));

	Texture fogTex = LoadTexture("fog.png");
	Texture litTex = LoadTexture("light.png");

	Tile floor01("floor_1.png"); // map tiles
	Tile floor02("floor_2.png");
	Tile floor03("floor_3.png");
	Tile floor04("floor_4.png");
	Tile floor05("floor_5.png");
	Tile floor06("floor_6.png");
	Tile floor07("floor_7.png");
	Tile floor08("floor_8.png");
	Tile emptyTile;
	
	masterTile master;
	master.tiles[0] = emptyTile;
	master.tiles[1] = floor01;
	master.tiles[2] = floor02;
	master.tiles[3] = floor03;
	master.tiles[4] = floor04;
	master.tiles[5] = floor05;
	master.tiles[6] = floor06;
	master.tiles[7] = floor07;
	master.tiles[8] = floor08;
	
	loadMap("map.txt", master);

	HighScoreTable hst("hst.txt");

	std::vector<wizAttack *> att; // wizard attack arr
	std::vector<enemy *> en; // enemy arr

	float spellsCastedTime = 0; // time before a spell can be casted
	float enemySpawnTime = 0; // time before next enemy spawn
	float enemySpawnTimeMax = 1.0f; // what the time has to hit to spawn an enemy
	float enemyStrongerTimer = 0; // timer for making an enemy have more health
	float damageTimer = 0; // timer for when enemy is allowed to damage
	float damageTimerMax = 0.0f; // max time for damageTimer

	int healthBar = 20; // width of the health bar
	int score = 0;
	bool* opacity = NULL; // controlls opacity of the enemies

	int gameState = 2;

	wizard wiz("wizzard_f_idle_anim_f0.png");
	barb bar("knight_f_idle_anim_f0.png");

	button bStart; // start button

	player * pl = nullptr;

	pl = &wiz; // setting player
	pl->enabled = true;
	pl->position = { 400,200 }; // player starting position

	for (int i = 0; i < 364; i++) // creating the world tile numbers
	{
		if (master.numberType[i] == 0) // void tiles
		{
			master.grid[i] = 0;
		}
		else if (master.numberType[i] == 1) // walkable
		{
			int rNumber = (rand() % 7)+1;
			master.grid[i] = rNumber;
		}
	}
	
	int paintID = -1;

	/*-------------------------------------------------------------*/
	/*                 GameState StartingScreen                    */
	/*-------------------------------------------------------------*/

	while (gameState == 0)
	{
		SetWindowTitle(std::to_string(GetFPS()).c_str());

		bStart.CheckForClick();

		if (bStart.CheckForClick())
		{
			gameState = 1;
		}

		BeginDrawing();

		ClearBackground(BLACK);

		bStart.draw();

		EndDrawing();
	}

	/*-------------------------------------------------------------*/
	/*                     GameState Game                          */
	/*-------------------------------------------------------------*/

	while (gameState == 1 && pl->alive) // game
	{	
		SetWindowTitle(std::to_string(GetFPS()).c_str());
			
		Vector2 cursor = GetMousePosition();
		size_t test = en.size();

		/*-------------------------------------------------------------*/
		/*                          ENEMY                              */
		/*-------------------------------------------------------------*/

		enemySpawnTime += GetFrameTime(); // adding onto the time before next enemy
		enemyStrongerTimer += GetFrameTime(); // adding onto the time for enemy buff
		damageTimer += GetFrameTime(); // adding onto timer for enemy damage allowed

		if (enemySpawnTime >= enemySpawnTimeMax) // enemy creation when time limit is reached
		{
			en.push_back(new imp("imp_idle_anim_f0.png"));
			en.back()->position = { (float)(rand() % 750), (float)(rand() % 400) };
			en.back()->alive = true;
			enemySpawnTime = 0;
		}

		for (int i = 0; i < en.size(); ++i) // update enemy hitbox
		{
			en[i]->follow(pl->position);
			en[i]->shouldRender = true;

			en[i]->rec.height = en[i]->mySprite.height;
			en[i]->rec.width = en[i]->mySprite.width;
			en[i]->rec.x = en[i]->position.x;
			en[i]->rec.y = en[i]->position.y;

			if (enemyStrongerTimer >= 20)
			{
				enemyStrongerTimer = 0;
				en[i]->health += 5;
			}

			// enemy + player collision
			if (CheckCollisionRecs(pl->rec, en[i]->rec) && damageTimer >= damageTimerMax) // player take damage
			{
				pl->takeDamage(en[i]->damage);

				if (!pl->alive)
				{
					gameState = 2;
				}

				healthBar -= 1;
				damageTimer = 0.0f;

				en.erase(en.begin() + i);
				continue;
			}

			bool enemyDied = false;

			// enemy + attack collision
			for (int j = 0; j < att.size(); ++j)
			{
				if (CheckCollisionRecs(att[j]->rec, en[i]->rec)) // enemy take damage
				{
					en[i]->takeDamage(att[j]->damage);

					if (en[i]->health <= 0)
					{
						enemyDied = true;
						en.erase(en.begin() + i);
						++score;
						break;
					}
				}
			}

			if (enemyDied) { continue; }
		}

		/*-------------------------------------------------------------*/
		/*                       WIZARD ATTACK                         */
		/*-------------------------------------------------------------*/

		spellsCastedTime += 0.002f; // adding onto the time before next cast

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellsCastedTime >= 2.0f) // wizard attack creation
		{
			spellsCastedTime = 0;

			att.push_back(new wizAttack("candy_02b.png"));
			att.back()->position = pl->position;
			att.back()->dest = cursor;

			wizAttack& atk = *att.back();

			Vector2 diff = { atk.dest.x - pl->position.x, atk.dest.y - pl->position.y };
			float dist = sqrt(diff.x * diff.x + diff.y * diff.y);
			diff.x /= dist;
			diff.y /= dist;

			atk.dir = diff;
		}

		for (int i = 0; i < att.size(); i++) // deleting wizard attack if it is at destination
		{
			int cdist = 0;
			int xdist = 0;
			int ydist = 0;

			xdist = att[i]->dest.x - att[i]->position.x;
			ydist = att[i]->dest.y - att[i]->position.y;

			cdist = ((xdist * xdist) + (ydist * ydist));
			cdist = sqrtf(cdist);

			if (cdist < 10.0f)
			{
				att.erase(att.begin() + i);
			}
		}

		for (int i = 0; i < att.size(); i++) // wizards attack hitbox and moveto
		{
			att[i]->moveTo({ cursor.x, cursor.y });

			att[i]->rec.height = att[i]->mySprite.height;
			att[i]->rec.width = att[i]->mySprite.width;
			att[i]->rec.x = att[i]->position.x;
			att[i]->rec.y = att[i]->position.y;
		}

		/*-------------------------------------------------------------*/
		/*                          PLAYER                             */
		/*-------------------------------------------------------------*/

		pl->moveTo(); // player movement

		pl->rec.x = pl->position.x; // player hitbox
		pl->rec.y = pl->position.y;
		pl->rec.height = pl->mySprite.height;
		pl->rec.width = pl->mySprite.width;

		/*-------------------------------------------------------------*/
		/*                          TILE                               */
		/*-------------------------------------------------------------*/

		// for every single tile
		for (int i = 0; i < 364; i++)
		{
			// build a rect for that tile if blank
			Rectangle recTile;
			recTile.height = 32;
			recTile.width = 32;
			recTile.x = (i % 26) * 32;
			recTile.y = (i / 26) * 32;

			if (master.grid[i] == 0)
			{
				for (int i = 0; i < att.size(); ++i) // checking for a collision between wizard attack and wall
				{
					if (CheckCollisionRecs(att[i]->rec, recTile))
					{
						att.erase(att.begin() + i); // destroy the wizard attack
					}
				}

				// enemy and t
				for (int i = 0; i < en.size(); ++i)
				{
					if (en[i]->shouldRender)
					{
						if (CheckCollisionRecs(en[i]->rec, recTile))
						{
							en[i]->shouldRender = false;
							break;
						}
					}
				}

				// compare against player
				if (CheckCollisionRecs(pl->rec, recTile))
				{
					if (IsKeyDown(KEY_W))
					{
						pl->position.y += pl->speed * GetFrameTime();
					}

					if (IsKeyDown(KEY_S))
					{
						pl->position.y -= pl->speed * GetFrameTime();
					}

					if (IsKeyDown(KEY_A))
					{
						pl->position.x += pl->speed * GetFrameTime();
					}

					if (IsKeyDown(KEY_D))
					{
						pl->position.x -= pl->speed * GetFrameTime();
					}
				}
			}

			if(master.grid[i] != 0)
			{
				if (CheckCollisionCircleRec(pl->position, 2.0f, recTile))
				{
					master.on[i] = true;
				}
				else
				{
					master.on[i] = false;
				}
			}
		}

		/*  Paint  */
		/*
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
		{
			int copyX = 0;
			int copyY = 0;
			int totalXY = 0;
			copyX = cursor.x / 32;
			copyY = cursor.y / 32;
			copyY = copyY * 26;
			totalXY = copyY + copyX;

			paintID = master.grid[totalXY];
			//+std::cout << paintID << std::endl;
		}

		// if mouse button pressed right button
		  // set the grid's value to the paintID
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			int copyX = 0;
			int copyY = 0;
			int totalXY = 0;
			copyX = cursor.x / 32;
			copyY = cursor.y / 32;
			copyY = copyY * 26;
			totalXY = copyY + copyX;

			master.grid[totalXY] = paintID;
		}
		*/

		/*-------------------------------------------------------------*/
		/*                          DRAW                               */
		/*-------------------------------------------------------------*/

		BeginDrawing();

		ClearBackground(BLACK);

		for (int i = 0; i < 364; i++) // drawing tiles
		{
			if (master.on[i] == true)
			{
				master.draw();
			}
		}

		pl->draw(WHITE); // player draw

		for (int i = 0; i < en.size(); i++)
		{
			if (en[i]->shouldRender)
			{
				en[i]->draw({ 255, 255, 255, 120 });
			}
		}

		for (int i = 0; i < att.size(); ++i) // wizard attack draw
		{
			att[i]->draw();
		}

		DrawRectangle(pl->position.x, pl->position.y, healthBar, 1, RED);
		DrawText(std::to_string(score).c_str(), 60, 10, 15, RAYWHITE);
		DrawText(std::to_string(hst.hsn).c_str(), 85, 50, 15, RAYWHITE);
		DrawText("Score:", 10, 10, 15, RAYWHITE);
		DrawText("HighScore:", 10, 50, 15, RAYWHITE);

		delete[] opacity;

		EndDrawing();
	}
	if (!pl->alive) // saving the new highscore back to file
	{
		if (score > hst.hsn)
		{
			hst.hsn = score;
			hst.hsTableSave("hst.txt");
		}
	}

	/*-------------------------------------------------------------*/
	/*                      GAMESTATE DeathScene                   */
	/*-------------------------------------------------------------*/

	finalForm skelChar("skull.png");
	imp i("imp_idle_anim_f0.png");
	i.position = { -50, 325 };
	i.speed = 40.0f;

	Vector2 followPos = { 850, 325 };

	bool end = false;

	float deathY = -10;

	while (gameState == 2 && !end)
	{
		SetWindowTitle(std::to_string(GetFPS()).c_str());

		i.follow(followPos);

		if (i.position.x > followPos.x - 40)
		{
			end = true;
		}

		BeginDrawing();

		ClearBackground(BLACK);

		if (deathY < 125)
		{
			DrawText("YOU HAVE DIED!", 190, deathY, 50, RED); // shows text on screen
			deathY += 20 * GetFrameTime();
		}
		else if (deathY >= 125)
		{
			DrawText("YOU HAVE DIED!", 190, deathY, 50, RED); // shows text on screen
		}

		skelChar.endDraw(WHITE);
		if (!end)
		{
			i.endDraw(WHITE);
		}

		EndDrawing();
	}
	CloseWindow();
}

void loadMap(std::string fileName, masterTile &master) // loading the map from file
{
	std::string buffer;

	std::ifstream fin(fileName.c_str(), std::ios::in);

	if (fin.fail())
	{
		std::cerr << "File not found." << std::endl;
	}

	if (!fin.eof() && fin.peek() != EOF)
	{
		int cellNumber = 0;

		while (std::getline(fin, buffer))
		{
			for (int i = 0; i < buffer.size(); i++)
			{
				master.numberType[cellNumber] = buffer[i] - '0';
				++cellNumber;
			}
		}
	}
}