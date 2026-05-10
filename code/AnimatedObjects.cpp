#include "AnimatedObjects.h"

AnimatedObjects::AnimatedObjects(int x, int y, int width, int height, Texture& texture, float velocityX, float velocityY, float maxSpeed):Entity(x, y, width, height, texture), velocityX(velocityX), velocityY(velocityY), maxSpeed(maxSpeed)
{
	resetState();// default state all enemies, and player will be spawn in air and other factors when applied will change current state
}

AnimatedObjects::AnimatedObjects(const AnimatedObjects& a):Entity(a),currentState(a.currentState),velocityX(a.velocityX),velocityY(a.velocityY),maxSpeed(a.maxSpeed)
{

}

AnimatedObjects::~AnimatedObjects()
{

}

float AnimatedObjects::getVelocityX()
{
	return velocityX;
}

float AnimatedObjects::getVelocityY()
{
	return velocityY;
}

State AnimatedObjects::getCurrentState()
{
	return currentState;
}

State& AnimatedObjects::setCurrentState()
{
	return currentState;
}

void AnimatedObjects::setVelocityX(float x)
{
	velocityX = x;
}

void AnimatedObjects::setVelocityY(float y)
{
	velocityY = y;
}


State& AnimatedObjects::updateState()
{
	return currentState;
}


void AnimatedObjects::land() {
	currentState.onGround = true;
	currentState.inAir = false;
}

void AnimatedObjects::inAir() {
	currentState.onGround = false;
	currentState.inAir = true;
}
void AnimatedObjects::resetState()
{
	currentState.inAir = true;
	currentState.inWater = false;
	currentState.isBurning = false;
	currentState.isFacingLeft = false;
	currentState.isRuning = false;
	currentState.onGround = false;
}

