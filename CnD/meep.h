#pragma once
#include "raylib.h"

class meep
{
public:

	//Vars
	bool enabled = true;

	bool playerController = true;

	Texture2D texture;

	Vector2 pos;
	float speed;

	// Constructors & Destructors
	meep();
	meep(bool _enabled, bool playerEnabled, float deltaTime);
	~meep();

	// Misc Functions
	void refresh();
	void update(float deltaTime);

private:
};