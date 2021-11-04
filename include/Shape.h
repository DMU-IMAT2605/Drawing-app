#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#define PI 3.14159265
#define RESOLUTION 121
#define THETA (PI/60)
#define DEFAULT_SIZE sf::Vector2f(30, 30)


class Shape
{
public:
	Shape();

	virtual ~Shape();

	virtual void changeSize(sf::Vector2f _delta) = 0;
	virtual void setPosition(sf::Vector2i _pos) = 0;
	virtual void render(sf::RenderTarget& _t) = 0;

	sf::Vector2f getSize() { return this->def_size; };
	
protected:
	sf::Vector2f def_size = DEFAULT_SIZE;
};



