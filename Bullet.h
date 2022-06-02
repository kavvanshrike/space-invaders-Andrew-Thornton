#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	Bullet(Texture2D* texture, float posX, float posY, float speed, int spriteX, int spriteY);
	void Update();
	void Draw();

	bool IsHit();
	void Reset(float posX, float posY);

private:
	int spriteX;
	int	spriteY;
	float speed;
	bool hit;
};

