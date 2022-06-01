#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	Bullet(Texture2D* texture, float speed);
	void Update();
	void Draw();

	bool IsHit();
	void Reset();

private:
	float speed;
	bool hit;
};

