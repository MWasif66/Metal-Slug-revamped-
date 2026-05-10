#pragma once
#include "AnimatedObjects.h"

class Projectile:  public AnimatedObjects
{
	mString owner;
	int damage;
	bool exist; // exist on screen 

};

