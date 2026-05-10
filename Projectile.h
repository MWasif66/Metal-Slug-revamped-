#pragma once
#include "AnimatedObjects.h"

class Projectile:  public AnimatedObjects
{
protected:
	mString owner;
	int damage;
	int explosionRadius;
	bool expired; // exist on screen 

public:
	Projectile(int x, int y, int width, int height, Texture& texture, float velocityX, float velocityY, float maxSpeed, mString owner, int damage, int explosionRadius);
	virtual ~Projectile();
	Projectile(const Projectile& p);

	// retrurn true if explosion occured use to decide if to apply explosion effects or not
		virtual bool onHit() = 0;
	// on screen or not 
	bool getIsExpired() const;
	void setIsExpired(bool flag);
	int getDamage() const;
	void setDamage(int dmg);

	int getExplosionRadius() const;
	void setExplosionRadius(int r);
	mString getOwner() const;
	void setOwner(const char* owner);

};

