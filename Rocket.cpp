#include "Rocket.h"

Rocket::Rocket(int x, int y, int width, int height, Texture& texture, float velocityX, float velocityY, float maxSpeed, mString owner, int damage, int explosionRadius)
	:Projectile(x, y, width, height, texture, velocityX, velocityY, maxSpeed, owner, damage, explosionRadius)
{
	expired = false;
}

Rocket::~Rocket()
{

}

Rocket::Rocket(const Rocket& r):Projectile(r)
{
	expired = false;
}

void Rocket::move(float dt)
{
	if (!expired)
	{
	position.x += velocityX * dt;
	position.y += velocityY * dt;
	}
}

bool Rocket::onHit()
{
	expired = true;
	return true;
}

void Rocket::update(float dt)
{
	move(dt);
}

void Rocket::render(RenderWindow& window)
{

	texture.loadFromFile("Sprites/Rocket.png");
	sprite.setTexture(texture);

	float width = texture.getSize().x, height = texture.getSize().y;

	sprite.setOrigin(width / 2, height / 2);

	(velocityX < 0) ?
		sprite.setScale(hitBox.width * 2.0f / width, hitBox.height * 2.0f) : sprite.setScale(-hitBox.width * 2.0f / width, hitBox.height * 2.0f);
	sprite.setPosition(position.x, position.y);
}

void Rocket::reset(int x, int y, float vX, float vY)
{
	position.x = x;
	position.y = y;
	velocityX = vX;
	velocityY = vY;   
	expired = false;
	resetState();
}
