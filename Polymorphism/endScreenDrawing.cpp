#include "endScreenDrawing.h"
#include "raylib.h"
#include <iostream>

finalForm::finalForm(const std::string & fileName)
{
	if (txtApp == false)
	{
		std::cout << "Creating sprite!" << std::endl;
		mySprite = LoadTexture(fileName.c_str());
		txtApp = true;
	}
}

finalForm::~finalForm()
{
	std::cout << "Destroying sprite!" << std::endl;
	UnloadTexture(mySprite);
}

void finalForm::endDraw(Color h)
{
	DrawTextureEx(mySprite, { 300, 150 }, 0, 10, h);
}