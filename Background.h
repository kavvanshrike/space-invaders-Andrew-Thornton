#pragma once
#include "Entity.h"
class Background : public Entity
{
public:
	Background(Texture2D* texture,float speed);
	void Update();
	void Draw();

private:
	float speed;
};

