#include "Enemy.h"
#include <stdlib.h>
#include <iostream>
float Enemy::_speed = 0.0f;
int Enemy::count = 0;
bool Enemy::loseCondition = false;

Enemy::Enemy(Texture2D* texture,float posX, float posY, float offset, float delay, Texture2D* bulletTexture, int spriteX, int spriteY) : Entity(texture, posX, posY, spriteRec, width, height),
speed(_speed), shootingTimer(0), spriteX(spriteX), spriteY(spriteY), moveTimer(0.0f), moveDelay(delay), offset(offset), towardsBottom(0.0f) 
{
	loseCondition = false;
	this->posX = posX;
	this->posY = posY;
	initial = posX;
	bullet = new Bullet(bulletTexture,posX,posY, (200 * -1), Rectangle{ 12, 0 , 8 , 8 }, 32,32);
	shootingTimer = 5 + (rand() % 35);
	width = 48;
	height = 48;
	count++;//everytimne contructor is called new enemy is added to the count
}

Enemy::~Enemy()
{
	delete bullet;
}

void Enemy::Update()
{
	//we put this up here so when enemy is shot down its bullets will still work without it
		bullet->Update();

	if (!enabled) return;
	if (posY > GetScreenHeight())
	{
		loseCondition = true;
	}
	float deltaTime = GetFrameTime();
	if (moveTimer <= 0.0f)//move enemy
	{
		if (moveTimer > -moveDelay)
		{
			posX += deltaTime * speed;
			if (towardsBottom > 0.0f)//move invader down
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
		speed = -abs(_speed);
		//posY += 16;
		towardsBottom = 16;
	}
	else if (posX < initial)//if enemy reaches its former position 
	{
		posX = initial;//prevent enemies from triggering this if statement twice in a row
		speed = abs(_speed);//reverse
		//posY += 16;//
		towardsBottom = 16;
	}
	else
	{
		if (speed > 0) speed = abs(_speed);
		else speed = -abs(_speed);

	}


	if (shootingTimer <= 0.0f && !bullet->enabled) //enemy shoot
	{
			bullet->Reset(posX-20, posY+60);//fire bullet added an offset since firing bullet from posX and posY is way off centre
			shootingTimer = 5 + (rand() % 35);//reset bullet fired
			//break;
		
	}
	else if(shootingTimer > 0.0f)
	{
		shootingTimer -= GetFrameTime();//time down to next available shot
	}
	
}
void Enemy::Draw()
{
	//draw bullets before enabled check so they continue to draw when enemy is slain
		bullet->Draw();

	if (!enabled) return;
	//DrawRectangle(posX, posY, width, height, RED);
	DrawTexturePro(*texture, Rectangle{ (float)spriteX, (float)spriteY, 8, 8 }, Rectangle{ (float)posX, (float)posY , width, height }, Vector2{ 0, 0 }, 0, WHITE);//draw enemy ship from sprite sheet
	

}
void Enemy::GetCollisions(Entity* e, int index)
{
	if (!bullet->IsHit() && bullet->isColliding(e))//check collision on all available bullets
	{
		bullet->CollisionHit(index);
		e->Receive(DAMAGE);
	}
}
int Enemy::Receive(int i)//override default receive to increase speed of all enemies
{
	switch (i)
	{
	case DAMAGE:
		enabled = false;
		_speed += 3;
		count--;
		break;
	}
	return(GetScreenHeight() - posY);
}
void Enemy::SetSpeed(float vspeed)
{
	_speed = vspeed;
}

int Enemy::GetCount()
{
	return count;
}

void Enemy::ResetCount()
{
	count = 0;
}

bool Enemy::GetLoseCondition()//use this in main to have the game end on certain conditions
{
	return loseCondition;
}


