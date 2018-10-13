#include "Barbarian.h"

barbarian::barbarian()
{
	barb = LoadTexture("knight_f_hit_anim_f0.png");
}

barbarian::~barbarian()
{
	UnloadTexture(barb);
}

void barbarian::draw()
{
	if (dead == false)
	{
		DrawTexture(barb, pos.x, pos.y, RED);
	}
}

int barbarian::damage()
{
	int damage = 10;
	health -= damage;
	if (health <= 0)
	{
		dead = true;
	}
	else
	{
		dead = false;
	}
	return health;
}
