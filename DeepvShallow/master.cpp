#include "master.h"
#include "raylib/raylib.h"

void masterTile::createGrid()
{
	// 64 by 64
	for (int i = 0; i <= 104; ++i)
	{
		if (i % 13)
		{ // creating each row
			cols = 0;
			int nextRows = rows + 64;
			rows = nextRows;
			grid[i] = rows; // grid = row from before + 64
		}
		else
		{ // creating each col
			int nextCols = cols + 64;
			cols = nextCols;
			grid[i] = cols; // grid = col from before + 64
		}
	}
}

void masterTile::draw()
{
	DrawTexture(tiles[grid[0]].sand1, 0, 0, WHITE);
	DrawTexture(tiles[grid[1]].sand1, 64, 0, WHITE);
	DrawTexture(tiles[grid[2]].sand1, 128, 0, WHITE);
	// draws all of the tiles
}
