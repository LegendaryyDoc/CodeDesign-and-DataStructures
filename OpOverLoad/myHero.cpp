#include <iostream>
#include "myHero.h"

hero::hero()
{
	std::cout << "Texture being created!" << std::endl;
	hp = 100;


	happy = LoadTexture("ouch1.png");

	smacked = LoadTexture("ouch2.png");

	hurt = LoadTexture("ouch3.png");

	superhurt = LoadTexture("ouch4.png");
	
	dead = LoadTexture("ouch5.png");
	
}

hero::hero(bool _enabled, float deltaTime)
{
	enabled = _enabled;
	if (enabled)
	{
		refresh();
		update(deltaTime);
	}
		
}

hero::~hero()
{
	std::cout << "Texture being destroyed!" << std::endl;

	UnloadTexture(happy);
	UnloadTexture(smacked);
	UnloadTexture(hurt);
	UnloadTexture(superhurt);
	UnloadTexture(dead);
}

void hero::refresh()
{

	int screenWidth = 832;
	int screenHeight = 448;

	if (hp >= 80)
	{
		DrawTexture(happy, pos.x, pos.y, WHITE);
	}
	else if (hp >= 60 && hp < 80)
	{
		DrawTexture(smacked, pos.x, pos.y, WHITE);
	}
	else if (hp >= 40 && hp < 60)
	{
		DrawTexture(hurt, pos.x, pos.y, WHITE);
	}
	else if (hp >= 20 && hp < 40)
	{
		DrawTexture(superhurt, pos.x, pos.y, WHITE);
	}
	else if (hp >= 0 && hp < 20)
	{
		DrawTexture(dead, pos.x, pos.y, WHITE);
	}
}

void hero::update(float deltaTime)
{
	/*  Player Movement  */
	if (IsKeyDown(KEY_W))
	{
		pos.y -= speed * deltaTime;
	}
	if (IsKeyDown(KEY_S))
	{
		pos.y += speed * deltaTime;
	}
	if (IsKeyDown(KEY_A))
	{
		pos.x -= speed * deltaTime;
	}
	if (IsKeyDown(KEY_D))
	{
		pos.x += speed * deltaTime;
	}
}

int hero::damage(int dealt)
{
	hp -= dealt;
	
	return hp;
}
