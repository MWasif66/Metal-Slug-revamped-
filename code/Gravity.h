#pragma once
class Gravity
{
	const int g;
	int terminalVelocity;
public:
	// terminal velocity will be diffferent like for arial enemy it is lower then general
	Gravity(int tVelocity);
	void applyGravity(float &yVelocity, float dt);
};

