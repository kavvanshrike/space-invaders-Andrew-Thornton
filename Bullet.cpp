#include "Bullet.h"
float Bullet::animDelay = 0.0f;
Texture2D* Bullet::textureDestroyAnim = NULL;

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

    posY -= GetFrameTime() * speed * (hit ? 0.3 : 1);//make bullet move up the screen or input negative value for the opposite
    //the multiplier at the end means that the position of the bullet explosion slows down on impact so it doesn't rapidly jet forward after hitting something
    if (hit)
    {
        if (animTimer <= 0)
        {
            this->spriteX += 8;
            totalAnimFrames--;
            animTimer = animDelay;
            this->width = 48;
            this->height = 48;
            spriteRec.x = spriteX;//need this to update sprite properly
            if (totalAnimFrames <= 0) enabled = false;
        }
        animTimer -= GetFrameTime();
    }
    else
    {
        if (posY < -height|| posY > GetScreenHeight())//reset bullets that are out of bounds
            hit = true;
    }
}



bool Bullet::IsHit()//check for used/hidden bullet
{
    return hit;
}

void Bullet::Reset(float posX, float posY)//return bullet to default, we use this to shoot unused bullets
{
    this->spriteX = defSpriteX;
    this->posX = posX + 8;
    this->posY = posY - 38;
    this->width = 32;
    this->height = 32;
    hit = false;
    enabled = true;
    texture = defaultTexture;
    spriteRec = defaultRec;
    totalAnimFrames = 4;
    animTimer = 0;
}

void Bullet::SetDestroyAnimation(Texture2D* vtexture, float delay)
{
    textureDestroyAnim = vtexture;
    animDelay = delay;
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
            this->posX += 8;
            this->posY -= 38;
            this->spriteX = 40;
            spriteRec = Rectangle{40, 48, 8, 8};//change position where destroyed sprite iterates
            break;
        case -1:
            this->posX -= 8;
            this->posY -= 38;
            this->spriteX = 72;
            spriteRec = Rectangle{72, 48, 8, 8 };
            break;
        default:
            this->posX += 8;
            this->posY -= 38;
            this->spriteX = 72;
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
