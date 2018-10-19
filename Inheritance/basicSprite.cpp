#include "basicSprite.h"
#include "raylib/raylib.h"
#include <iostream>
#include <string>

Sprite::Sprite(const std::string * filename, const int cellCount, const float _frameRate)
{
	spriteCells = new Texture2D [cellCount];
	frameCount = cellCount;

	for (int i = 0; i < cellCount; ++i)
	{
		spriteCells[i] = LoadTexture(filename[i].c_str());
	}
}

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

void Sprite::Draw()
{
	std::cout << currentFrame << std::endl;
	currentFrame++;
	
	DrawTexture(spriteCells[currentFrame], x, y, WHITE);
}
