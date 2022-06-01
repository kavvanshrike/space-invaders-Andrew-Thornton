#include "Bullet.h"

Bullet::Bullet(Texture2D* texture, float speed):Entity(texture, posX, posY), speed(speed), hit(false)
{

}

void Bullet::Update()
{
}

void Bullet::Draw()
{
}

bool Bullet::IsHit()
{
    return hit;
}

void Bullet::Reset()
{

}
