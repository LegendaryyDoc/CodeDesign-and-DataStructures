#include "entity.h"
#include "raylib.h"
#include "command.h"

entity::entity(const std::string & fileName)
{
	mySprite = LoadTexture(fileName.c_str());
}

entity::~entity()
{
	UnloadTexture(mySprite);
}

void entity::update(float deltaTime)
{
	if (com.empty())
	{
		return;
	}
	else if (com.front()->doCommand(this, deltaTime))
	{
		delete com.front();
		com.pop();
	}
}

void entity::draw()
{
	DrawTextureEx(mySprite, pos, 1.0f, 2.0f, RED);
}
