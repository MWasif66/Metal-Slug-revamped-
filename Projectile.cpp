#include "Projectile.h"

Projectile::Projectile(int x, int y, int width, int height, Texture& texture, float velocityX, float velocityY, float maxSpeed, mString owner, int damage, int explosionRadius)
	: AnimatedObjects(x, y, width, height, texture, velocityX, velocityY, maxSpeed), owner(owner), damage(damage), explosionRadius(explosionRadius)
{

}

Projectile::~Projectile()
{

}

Projectile::Projectile(const Projectile& p):AnimatedObjects(p)
{
	this->damage = damage;
	this->expired = expired;
	this->explosionRadius = explosionRadius;
	this->owner = owner;
}

bool Projectile::getIsExpired() const
{
	return expired;
}

void Projectile::setIsExpired(bool flag) 
{
	expired = flag;
}

int Projectile::getDamage() const
{
	return damage;
}

void Projectile::setDamage(int dmg)
{
	damage = dmg;
}

int Projectile::getExplosionRadius() const
{
	return explosionRadius;
}

void Projectile::setExplosionRadius(int r)
{
	explosionRadius = r;
}

mString Projectile::getOwner() const
{
	return owner;
}

void Projectile::setOwner(const char* owner)
{
	this->owner = owner;
}


