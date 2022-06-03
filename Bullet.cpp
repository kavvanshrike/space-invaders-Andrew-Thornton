#include "Bullet.h"
float Bullet::animDelay = 0.0f;
Texture2D* Bullet::textureDestroyAnim;

Bullet::Bullet(Texture2D* texture, float posX, float posY, float speed, Rectangle spriteRec, float width, float height) : Entity(texture, posX, posY, spriteRec, width, height), speed(speed),
hit(false), spriteX(spriteX), spriteY(spriteY), animTimer(0), totalAnimFrames(4)
{
    enabled = false;
    defSpriteX = spriteRec.x;//keep default values
    defSpriteY = spriteRec.y;
    spriteX = defSpriteX;
    spriteY = defSpriteY;
    this->posX = posX + 8;
    this->posY = posY - 38;
    defaultTexture = texture;
    defaultRec = spriteRec;
}

void Bullet::Update()
{
    if (!enabled) return;

    posY -= GetFrameTime() * speed;//make bullet move up the screen or input negative value for the opposite
    if (posY <= 0 || posY >= 800)
        hit = true;//reset bullets that are out of bounds

    if (hit)
    {
        if (animTimer <= 0)
        {
            spriteX += 8;
            totalAnimFrames--;
            animTimer = animDelay;

            if (totalAnimFrames <= 0) enabled = false;
        }
        animTimer -= GetFrameTime();
    }
    else
    {
        if (posY < -height || posY > GetScreenHeight())
            hit = true;
    }
}



bool Bullet::IsHit()//check for used/hidden bullet
{
    return hit;
}

void Bullet::Reset(float posX, float posY)//return bullet to default, we use this to shoot unused bullets
{
    this->posX = posX + 8;
    this->posY = posY - 38;
    hit = false;
    enabled = true;
    texture = defaultTexture;
    spriteRec = defaultRec;
    totalAnimFrames = 4;
    animTimer = 0;
}

void Bullet::SetDestroyAnimation(Texture2D texture, float delay)
{

}

void Bullet::CollisionHit(int index)
{
    hit = true;
    if (textureDestroyAnim != NULL)
    {
        texture = textureDestroyAnim;
        switch (index)
        {
        case 1:
            spriteRec = Rectangle{40, 48, 8, 8};//change position where destroyed sprite iterates
            break;
        case -1:
            spriteRec = Rectangle{72, 48, 8, 8 };
            break;
        default:
            spriteRec = Rectangle{ 72, 56, 8, 8 };
            break;

        }
    }
}

void Bullet::Draw()
{
    if (!enabled) return;
    //DrawRectangle(posX, posY, width, height, RED);
    DrawTexturePro(*texture, spriteRec, Rectangle{ posX, posY, width, height }, Vector2{ 0, 0 }, 0, WHITE);//draw bullet sprite
}
