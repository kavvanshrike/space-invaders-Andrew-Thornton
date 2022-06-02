#include "Enemy.h"
#include <stdlib.h>
#include <iostream>
Enemy::Enemy(Texture2D* texture,float posX, float posY, float speed, float offset, float delay, Texture2D* bulletTexture, int spriteX, int spriteY) : Entity(texture, posX, posY), 
speed(speed), shootingTimer(0), posX(posX), posY(posY), spriteX(spriteX), spriteY(spriteY), moveTimer(0.0f), moveDelay(delay), offset(offset), towardsBottom(0.0f)
{
	initial = posX;
	bullet = new Bullet(bulletTexture,posX,posY, (200 * -1), 12, 0);
	shootingTimer = 5 + (rand() % 55);
}

Enemy::~Enemy()
{
	delete bullet;
}

void Enemy::Update()
{
	float deltaTime = GetFrameTime();
	if (moveTimer <= 0.0f)//move enemy
	{
		if (moveTimer > -moveDelay)
		{
			posX += deltaTime * speed;
			if (towardsBottom > 0.0f)
			{
				towardsBottom -= deltaTime * abs(speed);
				posY += deltaTime * abs(speed);
			}
		}
		else
			moveTimer = moveDelay;
	}
	moveTimer -= deltaTime;
	
	if (posX >= (initial + offset))//if hits right side
	{
		posX = initial + offset-1;//i had bugs where random columns of enemies would yeet down the screen so we make sure this can't loop
		speed = -abs(speed);
		//posY += 16;
		towardsBottom = 16;
	}
	else if (posX < initial)//if enemy reaches its former position 
	{
		posX = initial;//prevent enemies from triggering this if statement twice in a row
		speed = abs(speed);//reverse
		//posY += 16;//
		towardsBottom = 16;
	}


	if (shootingTimer <= 0.0f) //enemy shoot
	{
		if (bullet->IsHit()) //reset bullet if it has hit something
		{
			bullet->Reset(posX-20, posY+60);//fire bullet added an offset since firing bullet from posX and posY is way off centre
			shootingTimer = 5 + (rand() % 55);//reset bullet fired
			//break;
		}
	}
	else if(shootingTimer > 0.0f)
	{
		shootingTimer -= GetFrameTime();//time down to next available shot
	}
	if (!bullet->IsHit())
		bullet->Update();
}
void Enemy::Draw()
{
	if (!bullet->IsHit())
		bullet->Draw();
	DrawTexturePro(*texture, Rectangle{ (float)spriteX, (float)spriteY, 8, 8 }, Rectangle{ (float)posX, (float)posY , 48, 48 }, Vector2{ 0, 0 }, 0, WHITE);//draw enemy ship from sprite sheet
	

}