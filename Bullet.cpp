#include "Bullet.h"

Bullet::Bullet(Texture2D* texture, int posX, int posY, float speed):Entity(texture, posX, posY), speed(speed), hit(true)
{
    this->posX = posX;
    this->posY = posY;
}

void Bullet::Update()
{
    posY -= GetFrameTime() * speed;
    if (posY <= 0)
        hit = true;
}



bool Bullet::IsHit()
{
    return hit;
}

void Bullet::Reset(int posX, int posY)
{
    this->posX = posX;
    this-> posY = posY;
    hit = false;
}

void Bullet::Draw()
{
    DrawTexturePro(*texture, Rectangle{ 8, 8, 8, 8 }, Rectangle{ (float)posX+3, (float)posY-38, 48, 48 }, Vector2{ 0, 0 }, 0, WHITE);
}
