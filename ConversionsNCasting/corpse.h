#pragma once
#include "raylib/raylib.h"
#include "Wizard.h"
#include "Barbarian.h"
#include <string>

class corpse
{
public:
	corpse(Wizard a);
	corpse(barbarian a);
	corpse();           // sets default values
	~corpse();

	std::string name;
	int mana = 50;

	int gold;

	Vector2 pos;
	Texture2D death;

	bool enabled = false;

	void draw();
};