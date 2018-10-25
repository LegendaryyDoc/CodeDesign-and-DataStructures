#pragma once
#include "enemy.h"
#include "raylib.h"

class ogre : public enemy
{
public:
	bool enabled = false;

	float speed = 0.5f;

	void draw();
	bool follow(const Vector2 &dest);

	ogre(const std::string & fileName);//assign the sprite image.
	~ogre();
};

