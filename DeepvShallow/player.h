#pragma once
#include "raylib/raylib.h"
#include <iostream>
class player
{
public:
	int health = 1000;
	int damage = 10;
	bool enabled = false;
	bool death = false;

	Rectangle rec;

	Vector2 position;
	Vector2 destination = { 0,0 };
	float speed = 20.f;
	Texture2D mySprite;
	void virtual moveTo();
	void virtual attack(Vector2 pos);
	void takeDamage(int damage);
	player(const std::string & fileName);//assign the sprite image.
	player();
	~player();

	void virtual draw(Color h);
};
