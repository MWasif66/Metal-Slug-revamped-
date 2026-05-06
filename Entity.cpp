#include "Entity.h"

Entity::Entity(int x, int y, int width, int height, Texture &texture)
{
	position.x = x;
	position.y = y;
	hitBox.height = height;
	hitBox.width = width;
	this->texture = texture;
	this->sprite.setTexture(texture);
	isAlive = true;
}

Entity::Entity(const Entity& e)
{
	this->hitBox = e.hitBox;
	this->position = e.position;
	this->sprite = e.sprite;
	this->texture = e.texture;
	this->isAlive = e.isAlive;
}


Entity::~Entity()
{

}

Position Entity::getPosition() const
{
	return position;
}

void Entity::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

HitBox Entity::getHitBox() const
{
	return hitBox;
}

void Entity::setTexture(Texture t)
{
	sprite.setTexture(t);
}
