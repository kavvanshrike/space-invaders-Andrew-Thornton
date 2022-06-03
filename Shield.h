#pragma once
#include "Entity.h"
class Shield : public Entity
{
public:
	Shield(Texture2D* texture, float posX, float posY);
	void Update();
	void Draw();
	int Receive(int i);

private:
	float spriteX;
	int hp;
};

