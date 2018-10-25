#pragma once
#include "player.h"
#include "raylib.h"

class wizard : public player
{
public:
	bool enabled = false;

	void draw();
	bool moveTo(const Vector2 &dest);

	wizard(const std::string & fileName);//assign the sprite image.
	~wizard();
};
