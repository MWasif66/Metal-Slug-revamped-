#include "bullet.h"

Bullet::Bullet(int x, int y, int width, int height, Texture& texture, float velocityX, float velocityY, float maxSpeed, mString owner, int explosionRadius)
	:Projectile(x, y,  width, height,  texture, velocityX, velocityY, maxSpeed, owner, 3, explosionRadius)
{
	expired = false;
}

Bullet::~Bullet()
{
}

Bullet::Bullet(const Bullet& b):Projectile(b)
{
	expired = false;
}

void Bullet::move(float dt)
{
	if (!expired)
	{
		position.x +=  velocityX*dt;
		position.y += velocityY*dt;
	}
}

// explosion occurs
bool Bullet::onHit()
{
	expired = true;
	return false;
}




void Bullet::update(float dt)
{
	move(dt);
}

void Bullet::render(RenderWindow& window)
{

		texture.loadFromFile("Sprites/Rocket.png");
	sprite.setTexture(texture);

	float width = texture.getSize().x, height = texture.getSize().y;

	sprite.setOrigin(width / 2, height / 2);

	(velocityX < 0) ?
		sprite.setScale(hitBox.width * 2.0f / width, hitBox.height * 2.0f) : sprite.setScale(-hitBox.width * 2.0f / width, hitBox.height * 2.0f);
	sprite.setPosition(position.x, position.y);
}


void Bullet::reset(int x, int y, float vX, float vY)
{
	position.x = x;
	position.y = y;
	velocityX = vX;
	velocityY = vY;
	expired = false;
	resetState(); 
}



