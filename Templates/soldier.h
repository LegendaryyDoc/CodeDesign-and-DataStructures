#pragma once
#include <iostream>
#include "raylib.h"
class soldier
{
public:
	Texture2D ja;

	Rectangle rec;

	Vector2 pos = { 400,225 };
	float speed = 60.0f;
	bool enabled = false;

	void render();
	void update(float delta);

	soldier();
	~soldier();
};

void soldier::render()
{
	DrawTexture(ja, pos.x, pos.y, WHITE);
}

void soldier::update(float delta)
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

soldier::soldier()
{
	ja = LoadTexture("Resources/knight_m_idle_anim_f0.png");
}

soldier::~soldier()
{
	UnloadTexture(ja);
}