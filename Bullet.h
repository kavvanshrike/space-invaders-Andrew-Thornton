#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	Bullet(Texture2D* texture, float posX, float posY, float speed, Rectangle spriteRec, float width, float height);
	void Update();
	void Draw();

	bool IsHit();
	void Reset(float posX, float posY);

	void CollisionHit(int index = 0);

	static void SetDestroyAnimation(Texture2D* texture, float delay);

private:
	int spriteX;
	int	spriteY;
	int defSpriteX;
	int defSpriteY;
	float speed;
	bool hit;
	static Texture2D* textureDestroyAnim;
	static float animDelay;
	float animTimer;
	int totalAnimFrames;

	Texture2D* defaultTexture;
	Rectangle defaultRec;
};

