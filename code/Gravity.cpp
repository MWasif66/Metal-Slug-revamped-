#include "Gravity.h"


Gravity::Gravity(int tVelocity): g(700),terminalVelocity(tVelocity)
{
}

void Gravity::applyGravity(float& yVelocity, float dt)
{
	if (yVelocity < terminalVelocity)
		yVelocity += g * dt;
}

