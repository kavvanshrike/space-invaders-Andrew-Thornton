#include "Background.h"
Background::Background(Texture2D* texture, float speed) : Entity(texture, posX, posY), speed(speed), posX(0), posY(0)
{
}

void Background::Update()
{
	posY += GetFrameTime() * speed;//scroll the background down the screen
	if (posY >= 800)//reset it when it gets too far down
		posY = 0;
}
void Background::Draw() 
{
	DrawTexturePro(*texture, Rectangle{ 5, 0, 120, 250 }, Rectangle{ (float)posX, (float)posY-800, 400, 800 }, Vector2{ 0, 0 }, 0, WHITE);
	DrawTexturePro(*texture, Rectangle{ 5, 0, 120, 250 }, Rectangle{ (float)posX + 400, (float)posY-800, 400, 800 }, Vector2{ 0, 0 }, 0, WHITE);//for scrolling background we need texture above
	DrawTexturePro(*texture, Rectangle{ 5, 0, 120, 250 }, Rectangle{ (float)posX, (float)posY, 400, 800 }, Vector2{ 0, 0 }, 0, WHITE);//draw backgrounds differently to single entities
	DrawTexturePro(*texture, Rectangle{ 5, 0, 120, 250 }, Rectangle{ (float)posX + 400, (float)posY, 400, 800 }, Vector2{ 0, 0 }, 0, WHITE);//offset to be lower
}