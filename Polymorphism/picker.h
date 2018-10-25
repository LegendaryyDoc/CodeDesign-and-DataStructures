#pragma once
#include "raylib.h"
#include "player.h"

class picker : public player
{
public:
	bool CheckForClick();
	void draw();

	Rectangle rec;

	picker(const std::string & fileName, const Vector2 & position);
	~picker();
};
