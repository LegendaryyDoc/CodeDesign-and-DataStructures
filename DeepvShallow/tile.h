#pragma once
#include <string>
#include <iostream>
#include "raylib/raylib.h"

class Tile
{
public:

	Vector2 pos;

	Texture2D sand1;
	//Texture2D sand2;
	/*Texture2D sand3;
	Texture2D sand4;
	Texture2D sand5;
	Texture2D sand6;
	Texture2D sand7;
	Texture2D sand8;*/

	Color tint;
	Tile(std::string imageFilename);
	Tile();
	~Tile();

	void refresh();
};