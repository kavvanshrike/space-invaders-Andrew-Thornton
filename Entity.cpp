#include "Entity.h"
#include <iostream>

Entity::Entity(Texture2D* texture, float posX, float posY, float width, float height)
{
	this->texture = texture;
	this->posX = posX;
	this->posY = posY;
	this->width = width;
	this->height = height;
	enabled = true;
}


void Entity::Event()
{
	if (!enabled) return;
}

void Entity::Update()
{
	if (!enabled) return;
}
void Entity::Draw()
{
	if (!enabled) return;
	DrawTexture(*texture, 0,0, WHITE );
}

bool Entity::isColliding(Entity* e)
{
	if (!enabled || !e->enabled) return false;
	//return false;
	return (posX+width >= e->posX 
		&& posY + height >= e->posY
		&& posX < e->posX + e->width
		&& posY < e->posY + e->height);//check if intersects
}

int Entity::Receive(int i)
{
	switch (i)
	{
	case DAMAGE:
		enabled = false;
		break;
	}
	return(GetScreenHeight() - posY);
}
