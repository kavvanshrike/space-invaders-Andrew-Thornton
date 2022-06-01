#pragma once
#include "Entity.h"
#include "Bullet.h"

class Player : public Entity
{
public:
	Player(Texture2D* texture, float speed, Texture2D* bulletTexture);
	~Player();
	void Event();
	void Update();
	void Draw();

private:
	float speed;
	//int health;
	int posX;
	int posY;

	Bullet* bullets;
	int maxBullets;

};

