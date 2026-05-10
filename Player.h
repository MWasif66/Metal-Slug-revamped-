#pragma once
#include "AnimatedObjects.h"
#include "Gravity.h"
#include "Weapon.h"
#include "Pistol.h"
struct MovementBound
{
	bool right;
	bool left;
};
class Player : public AnimatedObjects
{
	Weapon* weapon;
	int grenadeCount;
	int lives;
	int saturation;
	int jumpVelocity;
	Gravity gravity;
	int acceleration;
	MovementBound bound;
	Timer grenadeCooldown;

public:

	Player(int x, int y, int width, int height, Texture& texture, int jumpVelocity, int acc, int maxSpeed, float fireRate, int lives, int grenades)
		:AnimatedObjects(x, y, width, height, texture, 0.0f, 0.0f, maxSpeed), jumpVelocity(jumpVelocity), gravity(maxSpeed), acceleration(acc),lives(lives),grenadeCount(grenades),grenadeCooldown(0.5f)
	{
		weapon = new Pistol(fireRate);
		bound.left = false;
		bound.right = false;
		saturation = 0;
		
	}

	virtual	~Player();
	void move(float dt);
	void setMovemntBound(bool left, bool right);
	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
	virtual bool throwGranade(bool fireGranade);
	virtual bool shoot();

	void addSaturation(int s);
	
};

