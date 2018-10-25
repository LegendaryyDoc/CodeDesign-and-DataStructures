#pragma once
#include "enemy.h"
#include "raylib.h"

class necromancer : public enemy
{
public:
	bool enabled = false;

	float speed = 2.0f;

	void draw();
	bool follow(const Vector2 &dest);

	necromancer(const std::string & fileName);//assign the sprite image.
	~necromancer();
};

