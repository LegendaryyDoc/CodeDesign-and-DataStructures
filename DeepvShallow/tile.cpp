#include "tile.h"
#include "raylib/raylib.h"

Tile::Tile(std::string imageFilename)
{
	texture = LoadTexture(imageFilename.c_str());
	tint = WHITE;
}

Tile::Tile()
{
	std::cout << "Tile created!" << std::endl;

	texture = LoadTexture("mapTile_001.png");
	tint = WHITE;
}

Tile::~Tile()
{
	std::cout << "Tile destroyed!" << std::endl;

	UnloadTexture(texture);
}

void Tile::refresh()
{
	DrawTextureEx(texture, { 0,0 }, 0.0f, 4.0f, WHITE);
}
