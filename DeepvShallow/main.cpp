#include "raylib/raylib.h"
#include "tile.h"
#include "master.h"

int main()
{
	InitWindow(832, 448, "pixel art game");

	Tile sand1;
	sand1.pos = { 100,100 };

	Tile sand2("mapTile_002.png");
	Tile johnn("mapTile_007.png");

	masterTile master;
	master.tiles[0] = sand1;
	master.tiles[1] = sand2;
	master.tiles[2] = johnn;

	master.grid[0] = 2;
	master.grid[1] = 2;
	master.grid[2] = 2;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		master.draw();

		//sand1.refresh();

		EndDrawing();
	}
	CloseWindow();
}
