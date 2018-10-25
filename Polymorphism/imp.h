#pragma once
#include "enemy.h"
#include "raylib.h"

class imp : public enemy
{
public:
	bool enabled = false;

	float speed = 1.0f;

	void draw();
	bool follow(const Vector2 &dest);

	imp(const std::string & fileName);//assign the sprite image.
	~imp();
};

