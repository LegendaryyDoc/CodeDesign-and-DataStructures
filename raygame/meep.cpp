#include "meep.h"
#include <iostream>

meep::meep()
{
	std::cout << "Texture being created!" << std::endl;
	texture = LoadTexture("redTexture.png");
}

meep::meep(bool enabled)
{
	if (enabled)
	{
		refresh();
	}
}

meep::~meep()
{
	std::cout << "Texture being destroyed!" << std::endl;

	UnloadTexture(texture);
}

void meep::refresh()
{

	int screenWidth = 800;
	int screenHeight = 450;
	

	DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2 - 40, WHITE);
}
