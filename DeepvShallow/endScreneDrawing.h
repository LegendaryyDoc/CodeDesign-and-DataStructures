#pragma once
#include "raylib/raylib.h"
#include <string>
#include <iostream>

class finalForm
{
public:
	Texture2D mySprite;

	bool txtApp = false;

	finalForm(const std::string & fileName);
	~finalForm();

	void endDraw(Color h);
};