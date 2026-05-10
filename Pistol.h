#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:
	Pistol(float fireRate) :Weapon("Bullet", fireRate, -1, 3)
	{
		baseFireRate = 0.25;
	}
	Pistol(const Pistol& p) :Weapon(p)
	{

	}
	virtual ~Pistol()
	{

	}
};

