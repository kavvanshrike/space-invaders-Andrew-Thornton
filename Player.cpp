#include "Player.h"

Player::Player(Texture2D* texture, float speed, Texture2D* bulletTexture) : Entity(texture, posX, posY), speed(speed)
{
	posX = 400;//set initial position
	posY = 740;
	maxBullets = 10;
	bullets = new Bullet[12]{//if theres a short way of doing this I dont know it
		Bullet(bulletTexture, speed * 3.0f),
		Bullet(bulletTexture, speed * 3.0f),
		Bullet(bulletTexture, speed * 3.0f),
		Bullet(bulletTexture, speed * 3.0f),
		Bullet(bulletTexture, speed * 3.0f),
		Bullet(bulletTexture, speed * 3.0f),
		Bullet(bulletTexture, speed * 3.0f),
		Bullet(bulletTexture, speed * 3.0f),
		Bullet(bulletTexture, speed * 3.0f),
		Bullet(bulletTexture, speed * 3.0f),
		Bullet(bulletTexture, speed * 3.0f),
		Bullet(bulletTexture, speed * 3.0f)
	};
}

Player::~Player()
{
	delete[] bullets;
}

void Player::Event()
{
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
	
	if (IsKeyPressed(KEY_SPACE))
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (!bullets[i].IsHit())
			{
				bullets[i].Update();
			}
		}
	}
}

void Player::Update()
{
	Event();
	for (int i = 0; i < maxBullets; i++)
	{
		if (!bullets[i].IsHit())
		{
			bullets[i].Update();
		}
	}
}
void Player::Draw()
{
	
	DrawTexturePro(*texture, Rectangle{ 8, 0, 8, 8 }, Rectangle{ (float)posX, (float)posY , 48, 48 }, Vector2{ 0, 0 }, 0, WHITE);//draw player ship from sprite sheet
	
}