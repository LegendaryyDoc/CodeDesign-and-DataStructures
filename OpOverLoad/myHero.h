#pragma once
#include <string>
#include "raylib/raylib.h"

class hero
{
public:
	Texture2D happy;
	Texture2D smacked;
	Texture2D hurt;
	Texture2D superhurt;
	Texture2D dead;

	Vector2 pos;
	float speed;
	bool enabled = true;

	hero();
	hero(bool _enabled, float deltaTime);
	~hero();

	int age;
	int hp;
	int wealth;

	void update(float deltaTime);
	void refresh();
	int damage(int dealt);
};