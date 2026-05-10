#include "Grenade.h"

Grenade::Grenade(int x, int y, int width, int height, Texture& texture, float velocityX, float velocityY, float maxSpeed, mString owner, int damage, int explosionRadius)
	:Projectile(x, y, width, height, texture, velocityX, velocityY, maxSpeed, owner, damage, explosionRadius),gravity(maxSpeed)
{
	expired = false;
}

Grenade::~Grenade()
{
}

Grenade::Grenade(const Grenade& g):Projectile(g),gravity(g.gravity)
{
}

void Grenade::move(float dt)
{
	if (!expired)
	{
	gravity.applyGravity(velocityY, dt);
	position.x += velocityX * dt;
	position.y += velocityY * dt;
	}
}

bool Grenade::onHit()
{
	expired = true;
	return true;
}

void Grenade::update(float dt)
{
	move(dt);
}

void Grenade::render(RenderWindow& window)
{

	texture.loadFromFile("Sprites/Grenade.png");
	sprite.setTexture(texture);
	
	float width = texture.getSize().x, height = texture.getSize().y;

	sprite.setOrigin(width / 2, height / 2);

	(velocityX<0)?
		sprite.setScale(hitBox.width * 2.0f / width, hitBox.height * 2.0f): sprite.setScale(-hitBox.width * 2.0f / width, hitBox.height * 2.0f);
	sprite.setPosition(position.x, position.y);

}

void Grenade::reset(int x, int y, float vX, float vY)
{
	position.x = x;
	position.y = y;
	velocityX = vX;
	velocityY = vY;   // gravity will build up naturally from 0
	expired = false;
	resetState();
}


