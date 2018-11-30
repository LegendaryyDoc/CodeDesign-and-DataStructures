#pragma once
#include "raylib/raylib.h"
#include <iostream>

class enemy
{
public:
	bool enabled = false;

	int health = 5;
	int damage = 5;
	bool alive = false;
	bool shouldRender = false;

	Rectangle rec;

	Vector2 position;
	float speed = 1.0f;
	Texture2D mySprite;
	void takeDamage(int attDamage);
	bool virtual follow(const Vector2 &dest);
	enemy(const std::string & fileName);//assign the sprite image.
	enemy();
	~enemy();

	void virtual draw(Color);
};