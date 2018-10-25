#pragma once
#include "raylib.h"
#include <iostream>
class Sprite : public Vector2
{
public:
	Texture2D * spriteCells = NULL;

	float frameRate = 25.0;
	int frameCount = 0;
	int direction = 1;
	int currentFrame = 0;
	int frameCounter = 0;
	void Draw();

	Sprite(const std::string *filename, const  int cellCount = 1, const float _frameRate = 25.0);
	Sprite();
	~Sprite();
};
