#include "picker.h"

bool picker::CheckForClick()
{
	bool rtn = false;
	Vector2 cursor = GetMousePosition();
	if (CheckCollisionPointRec(cursor, rec))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			rtn = true;
			//std::cout << "1";
		}
		else
		{
			rtn = false;
		}
	}
	//std::cout << "0";
	return rtn;
}

void picker::draw()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
}

picker::picker(const std::string & fileName, const Vector2 & pos)
{
	mySprite = LoadTexture(fileName.c_str()); 

	position.x = pos.x;
	position.y = pos.y;
	rec.x = position.x;
	rec.y = position.y;
	rec.height = mySprite.height ;
	rec.width = mySprite.width ;
}

picker::~picker()
{
	UnloadTexture(mySprite);
}
