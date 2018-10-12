#pragma once
#include <string>
#include <iostream>
#include "raylib/raylib.h"

class Tile
{
public:

	Vector2 pos;

	Texture2D texture;
	Texture2D sand2;
	Texture2D sand3;
	Texture2D sand4;
	Texture2D sand5;
	Texture2D grass1;
	Texture2D grass2;
	Texture2D grass3;
	Texture2D grass4;
	Texture2D grass5;
	Texture2D stone1;
	Texture2D stone2;
	Texture2D stone3;
	Texture2D stone4;
	Texture2D stone5;

	Color tint;
	Tile(std::string imageFilename);
	Tile();
	~Tile();

	void refresh();
};