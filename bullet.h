#pragma once
#include "Projectile.h"
class Bullet: public Projectile
{
public:

	Bullet(int x, int y, int width, int height, Texture& texture, float directionX, float directionY, float maxSpeed, mString owner, int explosionRadius);// damage =3, explosion radius =0
	virtual ~Bullet();
	Bullet(const Bullet& b);

	void move(float dt);
	bool onHit() override;
	void update(float dt) override;
	void render(RenderWindow& window) override;
	void reset(int x, int y, float vX, float vY);
};

