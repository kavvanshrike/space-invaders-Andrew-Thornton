#include "Entity.h"

Entity::Entity(Texture2D* texture, float posX, float posY)
{
	this->texture = texture;
	this->posX = posX;
	this->posY = posY;
}


void Entity::Event()
{

}

void Entity::Update()
{

}
void Entity::Draw()
{
	DrawTexture(*texture, 0,0, WHITE );
}