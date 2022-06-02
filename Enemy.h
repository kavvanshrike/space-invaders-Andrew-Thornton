#pragma once
#include "Entity.h"
#include "Bullet.h"
class Enemy : public Entity
{
public:
	Enemy(Texture2D* texture,float posX, float posY, float speed, float offset, float delay, Texture2D* bulletTexture ,int spriteX, int spriteY);
	~Enemy();
	void Update();
	void Draw();
	
private:
	float speed;
	float posX;
	float posY;
	int spriteX;
	int	spriteY;
	float towardsBottom;
	

	Bullet* bullet;
	float shootingTimer;
	float moveTimer;
	float moveDelay;
	float initial;
	float offset;

};
