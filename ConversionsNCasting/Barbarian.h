#pragma once
#include "raylib/raylib.h"
#include <string>

class barbarian
{
public:
	barbarian();           // sets default values
	~barbarian();

	std::string name;
	int mana = 50;
	int health = 10;
	bool dead = false;

	int gold;

	Vector2 pos;
	Texture2D barb;

	void draw(); 
	int damage();
};