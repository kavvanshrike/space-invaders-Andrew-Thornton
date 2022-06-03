#include "Background.h"
Background::Background(Texture2D* texture, float speed) : Entity(texture, posX, posY, width, height), speed(speed)
{
	posX = 0;
	posY = 0;
	width = 400;
	height = 800;
}

void Background::Update()
{
	if (!enabled) return;

	posY += GetFrameTime() * speed;//scroll the background down the screen
	if (posY >= 800)//reset it when it gets too far down
		posY = 0;
}
void Background::Draw() 
{
	if (!enabled) return;

	DrawTexturePro(*texture, Rectangle{ 5, 0, 120, 250 }, Rectangle{ posX, posY-800, width, height }, Vector2{ 0, 0 }, 0, WHITE);
	DrawTexturePro(*texture, Rectangle{ 5, 0, 120, 250 }, Rectangle{ posX + 400, posY-800, width, height }, Vector2{ 0, 0 }, 0, WHITE);//for scrolling background we need texture above
	DrawTexturePro(*texture, Rectangle{ 5, 0, 120, 250 }, Rectangle{ posX, posY, width, height }, Vector2{ 0, 0 }, 0, WHITE);//draw backgrounds differently to single entities
	DrawTexturePro(*texture, Rectangle{ 5, 0, 120, 250 }, Rectangle{ posX + 400, posY, width, height }, Vector2{ 0, 0 }, 0, WHITE);//offset to be lower
}