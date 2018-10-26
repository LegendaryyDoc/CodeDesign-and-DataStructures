#include "command.h"
#include "entity.h"
#include <cmath>

bool moveCommand::doCommand(entity * target, float deltaTime)
{
	float delX = dest.x - target->pos.x;
	float delY = dest.y - target->pos.y;

	float dist = sqrt(delX * delX + delY * delY);

	if (dist < 10.0f)
	{
		return true;
	}

	delX /= dist;
	delY /= dist;

	target->pos.x += delX * target->speed * deltaTime;
	target->pos.y += delY * target->speed * deltaTime;

	return false;
}
