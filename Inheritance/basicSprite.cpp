#include "basicSprite.h"
#include "raylib.h"
#include <iostream>
#include <string>

Sprite::Sprite(const std::string * filename, const int cellCount, const float _frameRate)
{
	spriteCells = new Texture2D[cellCount];
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
	UnloadTexture(spriteCells[currentFrame]);
}

void Sprite::Draw()
{
	frameCounter++;
	if (frameCounter > 60 / frameCount) {
		frameCounter = 0;	
		currentFrame++;
		if (currentFrame >= frameCount)
		{
			currentFrame = 0;
		}
	}
	DrawTexture(spriteCells[currentFrame], x, y, WHITE);
}