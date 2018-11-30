#pragma once
#include "raylib/raylib.h"

class button
{
public:
	bool CheckForClick();
	void draw();
	Rectangle rec;

	button();
	~button();
};