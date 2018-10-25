#include "eSTL.h"

bool en::follow(const Vector2 & dest)
{
	if (dest.x > position.x)
	{
		position.x += speed;
	}
	if (dest.x < position.x)
	{
		position.x -= speed;
	}
	if (dest.y > position.y)
	{
		position.y += speed;
	}
	if (dest.y < position.y)
	{
		position.y -= speed;
	}

	return true;
}

en::en(std::string & _name, std::string & _fileName, float _speed)
{
	name = _name;
	fileName = _fileName;
	speed = _speed;
}

en::en()
{

}

en::~en()
{
	std::cout << "Destroying sprite!" << std::endl;

	UnloadTexture(mySprite);
}

void en::draw()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
}
