#include "enemy.h"
#include "raylib.h"
#include <iostream>
#include <string>
#include <ctime>

void enemy::draw()
{
	//DrawTexture(mySprite, pos.x, pos.y, WHITE);
	DrawTextureEx(mySprite, pos, rota, 2.0f, RED);
}

void enemy::move()
{
	

	 pos.x += rand() % 8 + -4;
	 pos.y += rand() % 8 + -4;
}

void enemy::update()
{
	pos.x += velocity.x;
	pos.y += velocity.y;

	rota = rota + (rand() % 2 - 7);
}

enemy::enemy(const std::string & fileName)
{
	std::cout << "Creating sprite!" << std::endl;
	mySprite = LoadTexture(fileName.c_str());
}

enemy::~enemy()
{
	std::cout << "Destroying sprite!" << std::endl;
	UnloadTexture(mySprite);
}