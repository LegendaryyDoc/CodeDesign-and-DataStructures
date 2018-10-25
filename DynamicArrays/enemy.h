#pragma once
#include <string>
#include "raylib.h"

class enemy
{
public:
	Vector2 pos;
	bool enabled = false;
	float speed = 2.0f;
	Texture2D mySprite;
	float rota = 0;

	Vector2 velocity;

	void draw();
	void move();
	void update();

	enemy(const std::string & fileName);//assign the sprite image.
	~enemy();
};