#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	Bullet(Texture2D* texture, float posX, float posY, float speed, int spriteX, int spriteY, float width, float height);
	void Update();
	void Draw();

	bool IsHit();
	void Reset(float posX, float posY);

	void CollisionHit();

private:
	int spriteX;
	int	spriteY;
	float speed;
	bool hit;
};

