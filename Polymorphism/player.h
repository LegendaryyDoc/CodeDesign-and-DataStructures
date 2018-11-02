#pragma once
#include "raylib.h"
#include <iostream>
class player
{
public:
	int health = 100;
	bool enabled = false;
	bool death = false;

	Rectangle rec;

	Vector2 position = { 100,100 };
	Vector2 destination = { 0,0 };
	float speed = 5.0f;
	Texture2D mySprite;
	bool virtual moveTo(const Vector2 &dest);
	void takeDamage(int damage);
	player(const std::string & fileName);//assign the sprite image.
	player();
	~player();

	void virtual draw(Color h);
};
