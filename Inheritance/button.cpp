#include "raylib.h"
#include "button.h"

void Button::Draw()
{
	
}

bool Button::CheckForClick()
{
	bool rtn = false;
	Vector2 cursor = GetMousePosition();
	if (CheckCollisionPointRec(cursor, rec))
	{
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			currentFrame = 1;
			rtn= true;
		}
		else
		{
			currentFrame = 0;
			rtn= false;
		}
	}


	//std::cout << currentFrame;
	DrawTexture(spriteCells[currentFrame], x, y, WHITE);
	return rtn;
}

Button::Button(const std::string * filename, const Vector2 & position, const int cellCount)
{
	spriteCells = new Texture2D[cellCount];
	frameCount = cellCount;

	for (int i = 0; i < cellCount; ++i)
	{
		spriteCells[i] = LoadTexture(filename[i].c_str());
	}
	//rec = { x,y,w,h };
	x = position.x;
	y = position.y;
	rec.x = position.x;
	rec.y = position.y;
	rec.width = spriteCells->width;
	rec.height = spriteCells->height;
}

Button::Button()
{

}

Button::~Button()
{
	UnloadTexture(spriteCells[currentFrame]);
}
