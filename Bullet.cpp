#include "Bullet.h"

Bullet::Bullet(Texture2D* texture, float posX, float posY, float speed, int spriteX, int spriteY) : Entity(texture, posX, posY), speed(speed), hit(true), spriteX(spriteX), spriteY(spriteY)
{
    this->posX = posX;
    this->posY = posY;
}

void Bullet::Update()
{
    posY -= GetFrameTime() * speed;//make bullet move up the screen or input negative value for the opposite
    if (posY <= 0 || posY >= 800)
        hit = true;//reset bullets that are out of bounts
}



bool Bullet::IsHit()//check for used/hidden bullet
{
    return hit;
}

void Bullet::Reset(float posX, float posY)//return bullet to default, we use this to shoot unused bullets
{
    this->posX = posX;
    this-> posY = posY;
    hit = false;
}

void Bullet::Draw()
{
    DrawTexturePro(*texture, Rectangle{ (float)spriteX, (float)spriteY, 8, 8 }, Rectangle{ posX+3, posY-38, 48, 48 }, Vector2{ 0, 0 }, 0, WHITE);//draw bullet sprite
}
