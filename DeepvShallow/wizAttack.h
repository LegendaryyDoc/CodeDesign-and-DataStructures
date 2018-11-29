#pragma once
#include "player.h"

class wizAttack : public player
{
public:
	Texture2D mySprite;

	Rectangle rec;

	Vector2 dest = {100, 100};
	Vector2 dir = { 0,0 };

	void draw();
	void moveTo(const Vector2 &pos);

	wizAttack();
	wizAttack(const std::string & fileName);
	~wizAttack();
};