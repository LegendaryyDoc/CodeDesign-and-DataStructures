#include "raylib/raylib.h"
#include "tile.h"
#include "master.h"
#include <ctime>

int main()
{
	InitWindow(832, 448, "pixel art game");
	srand(time(NULL));

	/*  randomly generating the tiles  */
	
	Tile sand1;
	//sand1.pos = { 0,0 };

	Tile grass3;
	//grass1.pos = { 768, 0 };

	Tile stone4;
	//stone1.pos = { 0, 384 };

	Tile sand5;
	sand5.pos = { 768,384 };

	/*  Random placing  */
	
	Tile sand01("mapTile_001.png");
	Tile sand02("mapTile_002.png");
	Tile sand03("mapTile_003.png");
	Tile sand04("mapTile_004.png");
	Tile sand05("mapTile_005.png");
	Tile grass01("mapTile_006.png");
	Tile grass02("mapTile_007.png");
	Tile grass03("mapTile_008.png");
	Tile grass04("mapTile_009.png");
	Tile grass05("mapTile_010.png");
	Tile stone01("mapTile_011.png");
	Tile stone02("mapTile_012.png");
	Tile stone03("mapTile_013.png");
	Tile stone04("mapTile_014.png");
	Tile stone05("mapTile_015.png");

	
	masterTile master;
	master.tiles[0] = sand01;
	master.tiles[1] = sand02;
	master.tiles[2] = sand03;
	master.tiles[3] = sand04;
	master.tiles[4] = sand05;
	master.tiles[5] = grass01;
	master.tiles[6] = grass02;
	master.tiles[7] = grass03;
	master.tiles[8] = grass04;
	master.tiles[9] = grass05;
	master.tiles[10] = stone01;
	master.tiles[11] = stone02;
	master.tiles[12] = stone03;
	master.tiles[13] = stone04;
	master.tiles[14] = stone05;

	
	for (int i = 0; i < 104; ++i)
	{
		int rNumber = rand() % 15;
		master.grid[i] = rNumber;
	}

	master.grid[4] = 5;
	
	int paintID = -1;

	while (!WindowShouldClose())
	{
		Vector2 cursor = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
		{
			int copyX = 0;
			int copyY = 0;
			int totalXY = 0;
			copyX = cursor.x / 64;
			copyY = cursor.y / 64;
			copyY = copyY * 13;
			totalXY = copyY + copyX;

			paintID = master.grid[totalXY];
			//std::cout << paintID << std::endl;
		}

		// if mouse button pressed right button
		  // set the grid's value to the paintID
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			int copyX = 0;
			int copyY = 0;
			int totalXY = 0;
			copyX = cursor.x / 64;
			copyY = cursor.y / 64;
			copyY = copyY * 13;
			totalXY = copyY + copyX;

			master.grid[totalXY] = paintID;
		}

		//std::cout << "x:" << cursor.x << "," << "y:" << cursor.y << std::endl;

		BeginDrawing();

		ClearBackground(SKYBLUE);

		master.draw();

		EndDrawing();
	}
	CloseWindow();
}
