#include "Bullet.h"

Bullet::Bullet(Texture2D* texture, float posX, float posY, float speed, int spriteX, int spriteY, float width, float height) : Entity(texture, posX, posY, width, height), speed(speed), hit(true), spriteX(spriteX), spriteY(spriteY)
{
    this->posX = posX + 8;
    this->posY = posY - 38;
}

void Bullet::Update()
{
    if (!enabled) return;

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
    this->posX = posX + 8;
    this-> posY = posY - 38;
    hit = false;
}

void Bullet::CollisionHit()
{
    hit = true;
}

void Bullet::Draw()
{
    if (!enabled) return;
    //DrawRectangle(posX, posY, width, height, RED);
    DrawTexturePro(*texture, Rectangle{ (float)spriteX, (float)spriteY, 8, 8 }, Rectangle{ posX, posY, width, height }, Vector2{ 0, 0 }, 0, WHITE);//draw bullet sprite
}
