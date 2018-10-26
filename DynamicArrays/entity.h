#pragma once
#include "tQueue.h"
#include "command.h"
#include "raylib.h"

class entity
{
public:
	Vector2 pos;
	float speed = 50.0f;
	Texture2D mySprite;

	tQueue<command*> com;

	entity(const std::string & fileName);
	~entity();
	void update(float deltaTime);
	void draw();
};