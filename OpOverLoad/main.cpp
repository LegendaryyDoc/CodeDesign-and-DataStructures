#include "raylib/raylib.h"
#include "myHero.h"
#include "ball.h"
#include "potion.h"
#include <ctime>
#include "square.h"

int main()
{
	InitWindow(800, 450, "pixel art game");

	hero dug;
	dug.pos = { 100, 100 };
	dug.speed = 50.0f;
	dug.enabled = true;

	ball dugCollider;
	dugCollider.pos = { 124, 135 };
	dugCollider.radius = 25.0f;
	dugCollider.speed = 50.0f;
	dugCollider.enabled = true;

	srand(time(NULL));

	potion hpPlus;
	hpPlus.enabled = true;
	hpPlus.pos = { (float)(rand() % 750), (float)(rand() % 400) };

	Rectangle potionCollider;

	potionCollider.x = hpPlus.pos.x + 14;
	potionCollider.y = hpPlus.pos.y + 2;
	potionCollider.height = 44;
	potionCollider.width = 20;

	//Texture2D potionTex = LoadTexture("potion_01c.png");

	float damageTimer = 0.0f;

	while (!WindowShouldClose())
	{
		damageTimer += GetFrameTime();

		if (damageTimer > 2.5f)
		{
			dug.damage(5);
			damageTimer = 0.0f;
		}

		if (CheckCollisionCircleRec(dugCollider.pos, dugCollider.radius, potionCollider))
		{
			hpPlus.enabled = false;
			dug.hp += 5;

			hpPlus.enabled = true;
			hpPlus.pos = { (float)(rand() % 750), (float)(rand() % 400) };

			potionCollider.x = hpPlus.pos.x + 14;
			potionCollider.y = hpPlus.pos.y + 2;
		}

		if (dug.enabled)
		{
			dug.update(GetFrameTime());
		}

		dugCollider.update(GetFrameTime());

		if (dug.hp > 100)
		{
			dug.hp = 100;
		}

		if (dug.hp == 0)
		{
			DrawText("The Hero is dead!", 190, 200, 20, RED);

			system("pause");
			return 0;
		}

		BeginDrawing();

		ClearBackground(BLACK);

		dugCollider.draw();
		DrawRectangle(potionCollider.x, potionCollider.y, potionCollider.width, potionCollider.height, BLACK);
		
		if (hpPlus.enabled)
		{
			hpPlus.refresh();
		}

		if (dug.enabled)
		{
			dug.refresh();
		}

		//DrawTexture(potionTex, 200, 100, WHITE);

		DrawText(std::to_string(dug.hp).c_str(), 600, 75, 25, RAYWHITE);

		EndDrawing();
	}

	CloseWindow();
}