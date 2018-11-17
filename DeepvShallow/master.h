#pragma once

#include "tile.h"

class masterTile
{
public:
	bool on[364];
	int numberType[364];
	Tile tiles[9];
	int grid[364];

	//Rectangle rec;

	void draw();
};