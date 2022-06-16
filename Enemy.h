#pragma once
#include "Entity.h"
#include "Bullet.h"
class Enemy : public Entity
{
public:
	Enemy(Texture2D* texture,float posX, float posY, float offset, float delay, Texture2D* bulletTexture ,int spriteX, int spriteY);
	~Enemy();
	void Update();
	void Draw();

	void GetCollisions(Entity* e, int index);
	int Receive(int i);

	static void SetSpeed(float vspeed);
	static int GetCount();
	static void ResetCount();
	static bool GetLoseCondition();
	
private:
	static float _speed;
	float speed;
	int spriteX;
	int	spriteY;
	float towardsBottom;
	

	Bullet* bullet;
	float shootingTimer;
	float moveTimer;
	float moveDelay;
	float initial;
	float offset;
	static bool loseCondition;
	static int count;

};

