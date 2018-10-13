#include "corpse.h"
#include "Wizard.h"
#include "Barbarian.h"

corpse::corpse(Wizard a)
{
	gold = a.gold;
	pos = a.pos;
}

corpse::corpse(barbarian a)
{
	gold = a.gold;
	pos = a.pos;
}

corpse::corpse()
{
	death = LoadTexture("zombie_idle_anim_f0.png");
}

corpse::~corpse()
{
	UnloadTexture(death);
}

void corpse::draw()
{
	if (enabled)
	{
		DrawTexture(death, pos.x, pos.y, WHITE);
	}
}
