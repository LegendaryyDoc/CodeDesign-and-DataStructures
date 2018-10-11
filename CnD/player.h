#pragma once
#include "raylib.h"

class player
{
public:
	Vector2 pos;
	float radius;
	float speed;
	bool enabled = true;

	player();
	player(float deltaTime, bool _enabled);
	~player();

	void update(float deltaTime);
	void draw();
};