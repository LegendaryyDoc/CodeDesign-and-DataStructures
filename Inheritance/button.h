#pragma once
#include "raylib.h"
#include "basicSprite.h"

class Button :
	public Sprite
{
public:
	void Draw();// This Draw function will override the base classes Draw.
	bool CheckForClick();

	Rectangle rec;

	Button(const std::string *filename, const Vector2 & position, const  int cellCount = 1);
	Button();
	~Button();
};
