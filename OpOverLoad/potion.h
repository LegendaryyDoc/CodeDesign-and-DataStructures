#pragma once
#include <string>
#include "raylib/raylib.h"

class potion
{
public:
	bool enabled = true;
	int hpMod;

	Texture2D texture;

	Vector2 pos;

	potion();
	potion(bool _enabled);
	~potion();

	void refresh();
};
