#pragma once
#include "Entity.h"




struct State
{
	bool inWater;	// for water terrain and thus gravity
	bool inAir;
	bool onGround;	
	bool isBurning; // to apply burn effects 
	bool isFacingLeft;	// for animations 
	bool isRuning;
};

class AnimatedObjects : public Entity
{
protected:
	State currentState;
	float velocityX;
	float velocityY;
	float maxSpeed;
public:
	
	AnimatedObjects(int x, int y, int width, int height, Texture& texture, float velocityX, float velocityY,float maxSpeed);
	AnimatedObjects(const AnimatedObjects& a);
	virtual ~AnimatedObjects();

	float getVelocityX();
	float getVelocityY();
	State getCurrentState();
	State& setCurrentState();

	void setVelocityX(float x);
	void setVelocityY(float y);
	State& updateState();
	void land();
	void inAir();

	void resetState();

	
};