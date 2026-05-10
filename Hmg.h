#pragma once
#include "Weapon.h"
class Hmg : public Weapon
{
	Hmg(float fireRate) :Weapon("Bullet", fireRate, 120, 3)
	{
		baseFireRate = 1.0f/8;
	}
	Hmg(const Hmg& p) :Weapon(p)
	{

	}
	virtual ~Hmg()
	{

	}
};

