#pragma once
#include "player.h"
#include "raylib.h"

class barb : public player
{
public:
	bool enabled = false;
	bool visible = true;

	Vector2 des = {100,100};

	void draw(Color h);
	bool moveTo(const Vector2 &dest);

	barb(const std::string & fileName);//assign the sprite image.
	~barb();
};
