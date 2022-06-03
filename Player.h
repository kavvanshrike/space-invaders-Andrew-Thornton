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

	int Receive(int i);

	int GetCollisions(Entity* e);

	void SetThrottle(Texture2D* texture, Rectangle rectangle);

private:
	float speed;

	Bullet* bullets;
	int maxBullets;
	float shootingTimer;
	float shootingDelay;

	int lives;

	Texture2D* textureThrottle;
	Rectangle throttleRec;

};

