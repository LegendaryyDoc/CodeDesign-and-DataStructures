#include "master.h"
#include "raylib/raylib.h"

void masterTile::draw()
{
	int rows = 0;
	int cols = -64;

	for (int i = 0; i < 104; ++i)
	{
		if (cols != 768)
		{ // creating each row
			cols += 64;
		}
		else if (cols == 768)
		{ // creating each col
			cols = 0;
			rows += 64;
		}
		DrawTexture(tiles[grid[i]].texture, cols, rows, tiles[grid[i]].tint);
	}
}
