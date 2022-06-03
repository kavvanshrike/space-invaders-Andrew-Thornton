#include "Player.h"
#include <iostream>

Player::Player(Texture2D* texture, float speed, Texture2D* bulletTexture, float delay) : Entity(texture, posX, posY, width, height), speed(speed), shootingTimer(0), shootingDelay(delay)
{
	posX = 400;//set initial position
	posY = 740;
	maxBullets = 12;
	width = 48;
	height = 48;
	bullets = new Bullet[12]{//if theres a short way of doing this I dont know it
		Bullet(bulletTexture,posX,posY, speed, 8, 8, 32, 32),
		Bullet(bulletTexture,posX,posY, speed, 8, 8, 32, 32),
		Bullet(bulletTexture,posX,posY, speed, 8, 8, 32, 32),
		Bullet(bulletTexture,posX,posY, speed, 8, 8, 32, 32),
		Bullet(bulletTexture,posX,posY, speed, 8, 8, 32, 32),
		Bullet(bulletTexture,posX,posY, speed, 8, 8, 32, 32),
		Bullet(bulletTexture,posX,posY, speed, 8, 8, 32, 32),
		Bullet(bulletTexture,posX,posY, speed, 8, 8, 32, 32),
		Bullet(bulletTexture,posX,posY, speed, 8, 8, 32, 32),
		Bullet(bulletTexture,posX,posY, speed, 8, 8, 32, 32),
		Bullet(bulletTexture,posX,posY, speed, 8, 8, 32, 32),
		Bullet(bulletTexture,posX,posY, speed, 8, 8, 32, 32)
	};
}

Player::~Player()
{
	delete[] bullets;
}

void Player::Event()
{
	if (!enabled) return;

	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))//move left
	{
		posX -= GetFrameTime() * speed;
		if (posX <= 0)
			posX = 0;
	}
	else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))//move right
	{
		posX += GetFrameTime() * speed;
		if (posX >= 752)//screenwidth - width of ship
			posX = 752;
	}
	
	if (shootingTimer <= 0.0f && IsKeyPressed(KEY_SPACE)) //press to shoot
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (bullets[i].IsHit()) //reset bullet if it has hit something
			{
				bullets[i].Reset(posX, posY);//fire bullet
				shootingTimer = shootingDelay;//add delay between shots
				break;
			}
		}
	}
	else
	{
		shootingTimer -= GetFrameTime();//time dow to next available shot
	}
}

void Player::Update()
{
	if (!enabled) return;

	Event();
	for (int i = 0; i < maxBullets; i++)
	{
		if (!bullets[i].IsHit())//update all bullet logic
		{
			bullets[i].Update();
		}
	}
}
void Player::Draw()
{
	if (!enabled) return;

	//DrawRectangle(posX, posY, width, height, RED);
	DrawTexturePro(*texture, Rectangle{ 8, 0, 8, 8 }, Rectangle{ (float)posX, (float)posY , 48, 48 }, Vector2{ 0, 0 }, 0, WHITE);//draw player ship from sprite sheet
	for (int i = 0; i < maxBullets; i++)
	{
		if (!bullets[i].IsHit())//draw all available bullets
		{
			bullets[i].Draw();
		}
	}
	
}

int Player::GetCollisions(Entity* e)
{
	int totalScore = 0;
	for (int i = 0; i < maxBullets; i++)
	{
		if (!bullets[i].IsHit() && bullets[i].isColliding(e))//draw all available bullets
		{
			//std::cout << bullets[i].posX
			bullets[i].CollisionHit();
			totalScore += e->Receive(DAMAGE);
		}
	}
	return totalScore;
}
