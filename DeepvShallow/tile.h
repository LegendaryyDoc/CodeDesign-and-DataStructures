#pragma once
#include <string>
#include <iostream>
#include "raylib/raylib.h"

class Tile
{
public:
	Vector2 pos;

	Texture2D texture;

	Color tint;
	Tile(std::string imageFilename);
	Tile();
	~Tile();

	void refresh();
};