#pragma once
#include "AnimatedObjects.h"
#include "Gravity.h"

struct MovementBound
{
	bool right;
	bool left;
};
class Player : public AnimatedObjects
{
	int jumpVelocity;
	Gravity gravity;
	int acceleration;
	MovementBound bound;
	int lives;
	int maxSpeed;

public:

	Player(int x, int y, int width, int height, Texture& texture, float velocityX, float velocityY,int jumpVelocity, int acc, int maxSpeed);
	virtual	~Player();
	void move(float dt);
	void setMovemntBound(bool left, bool right);
	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
};

