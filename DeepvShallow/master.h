#pragma once

#include "tile.h"

class masterTile
{
public:
	Tile tiles[15];
	int grid[104];

	void draw();
};