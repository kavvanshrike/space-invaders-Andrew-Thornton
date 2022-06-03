#pragma once
#include "Entity.h"
class Ship : public Entity
{
public:
	Ship(Texture2D* texture, float posX, float posY, float speed);
	void Update();
	void Draw();

private:
	float moveTimer;
	float speed;
};

