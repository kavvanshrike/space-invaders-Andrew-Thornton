#pragma once
#include "Entity.h"
#include "Bullet.h"

class Player : public Entity
{
public:
	Player(Texture2D* texture, float speed, Texture2D* bulletTexture, float delay);
	~Player();
	void Event();
	void Update();
	void Draw();

private:
	float speed;
	//int health;
	float posX;
	float posY;

	Bullet* bullets;
	int maxBullets;
	float shootingTimer;
	float shootingDelay;

};

