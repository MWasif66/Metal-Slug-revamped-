#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


const int GRAVITY = 10;// it will be used in many entities

using namespace sf;
struct Position	// for the position
{
	int x;
	int y;
};

struct HitBox
{
	int width;
	int height;
};

//TODO:  add entity count to entity manager
class Entity
{
protected:
	Position position;
	HitBox hitBox;
	Texture texture;
	Sprite sprite;
	bool isAlive;

public:
	Entity(int x, int y, int width, int height, Texture &texture);
	Entity( const Entity& e);
	virtual ~Entity();
	
	Position getPosition() const;	// for movement and colision
	void setPosition(int x, int y);
	HitBox getHitBox() const;
	//void setHitBox(); don't think its needed
	void setTexture(Texture t); //for animations if implemented

	virtual void update() = 0;
	virtual void render(sf:: RenderWindow & window) = 0;	// passing window to draw sprites of each entity

};

