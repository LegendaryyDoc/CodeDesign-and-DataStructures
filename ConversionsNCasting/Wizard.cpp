#include "Wizard.h"
#include "corpse.h"

Wizard::Wizard()
{
	std::cout << "Wizard being created" << std::endl;
	wizard = LoadTexture("wizzard_m_idle_anim_f0.png");
}

Wizard::~Wizard()
{
	std::cout << "Destroy the wizard!" << std::endl;
	UnloadTexture(wizard);
}

void Wizard::draw()
{
	if (dead != true)
	{
		DrawTexture(wizard, pos.x, pos.y, WHITE);
	}
}

int Wizard::damage()
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
