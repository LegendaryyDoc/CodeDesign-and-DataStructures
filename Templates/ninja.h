#pragma once
#include <iostream>
#include "raylib.h"
class ninja
{
public:
	Texture2D ja;
	Rectangle rec;

	Vector2 pos = { 200, 225 };
	float speed = 70.0f;
	bool enabled = false;

	void render();
	void update(float delta);

	ninja();
	~ninja();
};

void ninja::render()
{
	DrawTexture(ja, pos.x, pos.y, WHITE);
}

void ninja::update(float delta)
{
	if (enabled)
	{
		if (IsKeyDown(KEY_W))
		{
			pos.y -= speed * delta;
		}
		if (IsKeyDown(KEY_S))
		{
			pos.y += speed * delta;
		}
		if (IsKeyDown(KEY_A))
		{
			pos.x -= speed * delta;
		}
		if (IsKeyDown(KEY_D))
		{
			pos.x += speed * delta;
		}
	}

	Vector2 cursor = GetMousePosition();
	rec.x = pos.x;
	rec.y = pos.y;
	rec.width = ja.width;
	rec.height = ja.height;

	if (CheckCollisionPointRec(cursor, rec))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			//enabled = !enabled;
			if (enabled == true)
			{
				enabled = false;
				std::cout << "false";
			}
			else if (enabled == false)
			{
				enabled = true;
				std::cout << "true";
			}
		}
	}
}

ninja::ninja()
{
	ja = LoadTexture("Resources/necromancer_idle_anim_f0.png");	

}

ninja::~ninja()
{
	UnloadTexture(ja);
}


