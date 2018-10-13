#include "OriginalClass.h"
#include "NewerClass.h"
#include "raylib/raylib.h"
#include "Wizard.h"
#include "Barbarian.h"
#include "corpse.h"

int main() 
{
	OriginalClass ma;
	NewerClass mb = ma;

	NewerClass mc;
	OriginalClass md = mc;

	InitWindow(800, 450, "pixel art game");

	Wizard uraWizard;
	uraWizard.pos = { 100,100 };
	uraWizard.gold = 10;
	uraWizard.dead = false;

	barbarian ogh;
	ogh.pos = { 100,200 };
	ogh.gold = 21;
	ogh.dead = false;

	corpse dead[3];
	dead[2].gold = 0;
	dead[2].enabled = false;

	//corpse dead[3];

	while (!WindowShouldClose())
	{
		if (uraWizard.dead == false)
		{
			if (IsKeyPressed(KEY_H))
			{
				uraWizard.damage();
				if (uraWizard.dead == true)
				{
					dead[1].gold = uraWizard.gold;
					dead[1].enabled = true;
					dead[1].pos = uraWizard.pos;
				}
				std::cout << "Money money money " << dead[1].gold << std::endl;
			}
		}
		if (ogh.dead == false)
		{
			if (IsKeyPressed(KEY_J))
			{
				ogh.damage();
				if (ogh.dead == true)
				{
					dead[0].gold = ogh.gold;
					dead[0].enabled = true;
					dead[0].pos = ogh.pos;
				}
				std::cout << "Money money money " << dead[0].gold << std::endl;
			}
		}

		BeginDrawing();

		ClearBackground(BLACK);

		//DrawTexture(potionTex, 200, 100, WHITE);

		// if the wizard dies
			// hide the wizard
			// convert the wizard into a corpse
			// enable that corpse

		uraWizard.draw();
		ogh.draw();
		for (int i = 0; i < 3; ++i)
		{
			if (dead[i].enabled == true)
			{
				dead[i].draw();
			}
		}
		EndDrawing();
	}
CloseWindow();
}