#include "wizAttack.h"
#include <cmath>

void wizAttack::draw()
{
	DrawTexture(mySprite, position.x, position.y, BLUE);
}

void wizAttack::moveTo(const Vector2 &pos)
{
	int offsetX = 0;
	int offsetY = 0;

	int targetDestination = 0;

	position.x += dir.x * speed * 3 * GetFrameTime();
	position.y += dir.y * speed * 3 * GetFrameTime();
}

wizAttack::wizAttack()
{
}

wizAttack::wizAttack(const std::string & fileName)
{
	mySprite = LoadTexture(fileName.c_str());
}

wizAttack::~wizAttack()
{
	UnloadTexture(mySprite);
}
