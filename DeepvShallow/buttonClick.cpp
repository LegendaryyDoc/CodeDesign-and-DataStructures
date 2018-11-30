#include "buttonClick.h"

bool button::CheckForClick()
{
	bool rtn = false;
	Vector2 cursor = GetMousePosition();
	if (CheckCollisionPointRec(cursor, rec))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			rtn = true;
		}
		else
		{
			rtn = false;
		}
	}
	return rtn;
}

void button::draw()
{
	DrawRectangle(rec.x, rec.y, rec.width, rec.height, MAROON);
	DrawText("Start", 380, 318, 25, BLACK);
}

button::button()
{
	rec.height = 60;
	rec.width = 200;
	rec.x = 310;
	rec.y = 300;
}

button::~button()
{
}
