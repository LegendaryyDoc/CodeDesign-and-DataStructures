#include "SimpleSprite.h"
#include "raylib.h"
#include <iostream>

SimpleSprite * SimpleSprite::Clone()
{
	std::cout << "clone" << std::endl;

	auto sprite = new SimpleSprite(*this);

	sprite->r2.x = rand() % 800;

	return sprite;
}

void SimpleSprite::translate(Vector2 delta)
{
	r2.x += delta.x;
	r2.y += delta.y;
}

void SimpleSprite::draw()
{
	DrawTexturePro(texture, r1, r2, pos, rot, WHITE);
}

SimpleSprite::SimpleSprite()
{
	pos = { 0,0 };
}

SimpleSprite::SimpleSprite(const std::string & filename, const std::string _sprType, float scale)
{
	sprType = _sprType;
	texture = LoadTexture(filename.c_str());
	r1 = { (float)0,(float)0,(float)texture.width,(float)texture.height };
	r2 = { (float)0,(float)0,(float)texture.width*scale,(float)texture.height*scale };
	pos = { 0,0 };
	rot = 45;
}

SimpleSprite::~SimpleSprite()
{
	UnloadTexture(texture);
}
