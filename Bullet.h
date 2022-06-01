#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	Bullet(Texture2D* texture, int posX, int posY, float speed);
	void Update();
	void Draw();

	bool IsHit();
	void Reset(int posX, int posY);

private:
	float speed;
	bool hit;
};

