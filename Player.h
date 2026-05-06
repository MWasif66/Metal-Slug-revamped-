#pragma once
#include "AnimatedObjects.h"



class Player : public AnimatedObjects
{
	float jumpVelocity;

public:
	void move();

};

