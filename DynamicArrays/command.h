#pragma once
#include "raylib.h"
#include "tQueue.h"

class command
{
public:
	virtual bool doCommand(class entity * target, float deltaTime) = 0;
};
class moveCommand : public command
{
public:
	Vector2 dest;
	virtual bool doCommand(class entity * target, float deltaTime);
};