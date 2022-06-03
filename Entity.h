#pragma once
#include "raylib.h"

enum EntityReceiveIDs
{
	DAMAGE,
};

class Entity
{
public:
	Entity(Texture2D* texture, float posX, float posY, Rectangle spriteRec, float width, float height);
	virtual void Event();
	virtual void Update();
	virtual void Draw();
	
	bool isColliding(Entity* e);
	virtual int Receive(int i);
	bool enabled;

protected:
	Rectangle spriteRec;
	Texture2D* texture;
	float posX;
	float posY;
	float width;
	float height;
};
