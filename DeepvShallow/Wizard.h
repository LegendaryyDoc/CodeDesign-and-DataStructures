#pragma once
#include "player.h"
#include "raylib/raylib.h"

class wizard : public player
{
public:
	bool enabled = false;

	void draw(Color h);
	void moveTo();

	wizard(const std::string & fileName);//assign the sprite image.
	~wizard();
};