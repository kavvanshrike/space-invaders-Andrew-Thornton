#pragma once
#include "raylib.h"

class Entity
{
public:
	Entity(Texture2D* texture, int posX, int posY);
	virtual void Event();
	virtual void Update();
	virtual void Draw();
	int posX;
	int posY;

protected:
	Texture2D* texture;
	
};
