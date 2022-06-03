#include "Ship.h"
#include <stdlib.h>
Ship::Ship(Texture2D* texture, float posX, float posY, float speed) : Entity(texture, posX, posY,spriteRec, width, height), speed(speed)
{
	moveTimer = 5 + (rand() % 15);//initialise movetimer
	width = 64;
	height = 64;
}

void Ship::Update()
{
	if (!enabled) return;

	if (moveTimer <= 0.0f)
	{
		//move ship
		posX += speed * GetFrameTime();
		if (posX > GetScreenWidth())
		{
			posX = -64;//instead of having a bool to determine if mothership is drawing or alive we just respawn it just off screen where it waits for next timer trigger
			moveTimer =  5 + (rand() % 15);//reset movetimer
		}
	}
	else
	{
		moveTimer -= GetFrameTime();
	}
}

void Ship::Draw()
{
	if (!enabled) return;

	DrawTexturePro(*texture, Rectangle{ 48, 64, 16, 16 }, Rectangle{ posX, posY, 64, 64 }, Vector2{ 0, 0 }, 0, WHITE);//draw mothership
}
