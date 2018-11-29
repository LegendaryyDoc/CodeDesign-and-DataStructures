#include "raylib/raylib.h"
#include "tile.h"
#include "master.h"
#include "wizAttack.h"
#include "Wizard.h"
#include "player.h"
#include "Barbarian.h"
#include <ctime>
#include <cmath>
#include <fstream>
#include <vector>

void loadMap(std::string fileName, masterTile &master);

int main()
{
	InitWindow(832, 448, "pixel art game");
	srand(time(NULL));

	/*  Random placing  */

	Texture fogTex = LoadTexture("fog.png");
	Texture litTex = LoadTexture("light.png");

	Tile floor01("floor_1.png");
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

	std::vector<wizAttack *> att;
	float spellsCastedTime = 0;

	wizard wiz("wizzard_f_idle_anim_f0.png");
	barb bar("knight_f_idle_anim_f0.png");

	player * pl = nullptr;

	pl = &wiz;
	pl->enabled = true;
	pl->position = { 400,200 };

	for (int i = 0; i < 364; i++)
	{
		if (master.numberType[i] == 0) // void tiles
		{
			master.grid[i] = 0;
		}
		else if (master.numberType[i] == 1)
		{
			int rNumber = (rand() % 7)+1;
			master.grid[i] = rNumber;
		}
		
	}
	
	int paintID = -1;

	bool alive = true;

	while (alive) // game
	{
		if (pl->health <= 0)
		{
			alive = false;
		}

		spellsCastedTime += 0.002f;

		SetWindowTitle(std::to_string(GetFPS()).c_str());
			
		Vector2 cursor = GetMousePosition();

		pl->moveTo();

		for (int i = 0; i < att.size(); i++)
		{
			att[i]->moveTo({ cursor.x, cursor.y });

			att[i]->rec.height = att[i]->mySprite.height;
			att[i]->rec.width = att[i]->mySprite.width;
			att[i]->rec.x = att[i]->position.x;
			att[i]->rec.y = att[i]->position.y;
		}

		pl->rec.x = pl->position.x;
		pl->rec.y = pl->position.y;
		pl->rec.height = pl->mySprite.height;
		pl->rec.width = pl->mySprite.width;

		// for every single tile
		for (int i = 0; i < 364; i++)
		{
			// build a rect for that tile if blank
			Rectangle recTile;
			recTile.height = 32;//  master.tiles->texture.height;
			recTile.width = 32; // master.tiles->texture.width;
			recTile.x = (i % 26)* 32;
			recTile.y = (i / 26) * 32;

			if (master.grid[i] == 0)
			{
				for (int i = 0; i < att.size(); ++i)
				{
					if (CheckCollisionRecs(att[i]->rec, recTile))
					{
						att.erase(att.begin() + i);
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

		for (int i = 0; i < att.size(); i++)
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

		BeginDrawing();

		ClearBackground(BLACK);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && spellsCastedTime >= 2.0f)
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

			std::cout << "yep" << std::endl;
		}

		for (int i = 0; i < 364; i++)
		{
			if (master.on[i] == true)
			{
				master.draw();
			}
		}

		pl->draw(WHITE);

		for (int i = 0; i < att.size(); ++i)
		{
			att[i]->draw();
		}

		EndDrawing();
	}
	CloseWindow();
}

void loadMap(std::string fileName, masterTile &master)
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