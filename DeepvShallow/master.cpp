#include "master.h"
#include "raylib/raylib.h"

void masterTile::draw()
{
	int rows = 0;
	int cols = -32;

	for (int i = 0; i < 364; ++i)
	{
		if (cols != 800)
		{ // creating each row
			cols += 32;
		}
		else if (cols == 800)
		{ // creating each col
			cols = 0;
			rows += 32;
		}
		DrawTextureEx(tiles[grid[i]].texture, { (float)(cols), (float)(rows) }, 0.f, 2.0f, tiles[grid[i]].tint);
	}
}
