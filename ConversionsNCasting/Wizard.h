#pragma once
#include <iostream>
#include "raylib/raylib.h"
class Wizard
{
public:
	Wizard();           // sets default values
	~Wizard();

	std::string name;
	int mana = 50;
	int health = 10;
	bool dead = false;

	int gold;

	Vector2 pos;
	Texture2D wizard;

	void draw();        // call this in your draw loop to render the wizard
	int damage();
};
