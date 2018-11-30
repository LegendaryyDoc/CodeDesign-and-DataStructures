#pragma once
#include "enemy.h"
#include "raylib/raylib.h"

class imp : public enemy
{
public:
	bool enabled = false;

	float speed = 15.0f;

	void draw();
	void endDraw(Color h);

	bool follow(const Vector2 &dest);

	imp(const std::string & fileName);//assign the sprite image.
	~imp();
};