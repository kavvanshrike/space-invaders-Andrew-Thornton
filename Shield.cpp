#include "Shield.h"

Shield::Shield(Texture2D* texture, float posX, float posY) : Entity(texture, posX, posY,spriteRec, width, height), hp(4), spriteX(88)
{
	width = 64;
	height = 64;
}

void Shield::Update()
{
	if (!enabled) return;

	if (hp > 0)
		spriteX = 40+((hp - 1) * 16);
}
void Shield::Draw()
{
	if (!enabled) return;

	DrawTexturePro(*texture, Rectangle{ spriteX, 32, 16, 16 }, Rectangle{ posX, posY, 64, 64 }, Vector2{ 0, 0 }, 0, WHITE);
}

int Shield::Receive(int i)
{
	switch (i)
	{
	case DAMAGE:
		hp--;
		if(hp <=0) enabled = false;
		break;
	}
	return 0;
}
