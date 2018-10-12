#include "tile.h"
#include "raylib/raylib.h"

Tile::Tile(std::string imageFilename)
{
	sand1 = LoadTexture(imageFilename.c_str());
}

Tile::Tile()
{
	std::cout << "Tile created!" << std::endl;

	sand1 = LoadTexture("mapTile_001.png");
	//sand2 = LoadTexture("mapTile_002.png");
	/*sand3 = LoadTexture("mapTile_003.png");
	sand4 = LoadTexture("mapTile_016.png");
	sand5 = LoadTexture("mapTile_017.png");
	sand6 = LoadTexture("mapTile_018.png");
	sand7 = LoadTexture("mapTile_004.png");
	sand8 = LoadTexture("mapTile_005.png");*/

}

Tile::~Tile()
{
	std::cout << "Tile destroyed!" << std::endl;

	UnloadTexture(sand1);
}

void Tile::refresh()
{
	DrawTexture(sand1, pos.x, pos.y, WHITE);
}
