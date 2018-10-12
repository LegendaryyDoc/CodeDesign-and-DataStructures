#pragma once

#include "tile.h"

class masterTile
{
public:
	Tile tiles[3];
	int grid[104];
	int rows = 0;
	int cols = 0;

	void createGrid();
	void draw();
};