#include "Player.h"

Player::Player(int x, int y, int width, int height, Texture& texture, float velocityX, float velocityY, int jumpVelocity, int acc, int maxSpeed):AnimatedObjects(x, y, width, height, texture, velocityX, velocityY,maxSpeed),jumpVelocity(jumpVelocity),gravity(maxSpeed),acceleration(acc)
{
	// at start free to move
	bound.left = false;	
	bound.right = false;
	lives = 3;

}

Player::~Player()
{

}


void Player::move(float dt)
{
	
	// vertical movement
	if (currentState.inAir)
	{
		gravity.applyGravity(velocityY, dt);
	}
	else if (currentState.onGround)
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			velocityY = 0;
			velocityY -= jumpVelocity;
			
			currentState.onGround = false;
			currentState.inAir = true;
		}
		else
		{
			velocityY = 0.0f;
		}
	}

	// horizontal movement // crouch yet to add
	if (Keyboard::isKeyPressed(Keyboard::Right) && !bound.right)
	{
		if (velocityX < maxSpeed) velocityX += acceleration * dt;
		currentState.isRuning = true;
		currentState.isFacingLeft = false;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left) && !bound.left)
	{
		if (velocityX > -maxSpeed) velocityX -= acceleration * dt;
		currentState.isRuning = true;
		currentState.isFacingLeft = true;
	}
	else
	{

		velocityX = 0.0f;
		currentState.isRuning = false;
	}

	// appy velocity
	position.x += velocityX;
	position.y += velocityY;
}

void Player::setMovemntBound(bool left, bool right)
{
	bound.left = left;
	bound.right = right;
}

void Player::update(float dt)
{
	move(dt);
}

void Player::render(sf::RenderWindow& window)
{
	float width = 31, height = 38, x=3,y=813;


	if (currentState.inAir)
	{
		y = 1820;
	}



	sprite.setTextureRect(sf::IntRect(x, y, width, height));
	
	sprite.setOrigin(width/2,height/2);
	
	if(currentState.isFacingLeft)
	
		sprite.setScale(-hitBox.width* 2.0f / width , hitBox.height *2.0f / height );
	else
		sprite.setScale(hitBox.width* 2.0f/ width , hitBox.height *2.0f / height );

	
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
}



