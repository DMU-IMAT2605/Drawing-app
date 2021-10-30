#pragma once

#include "Circle.h"

class Shape
{
public:
	Shape(sf::Vector2i _pos);
	Shape(sf::Vector2i _pos, sf::Vector2f _size);
	~Shape();

	virtual void changeSize(sf::Vector2f _delta) = 0;
	virtual void setPosition(sf::Vector2i _pos) = 0;
	virtual void render(sf::RenderTarget& _t) = 0;

	virtual sf::Vector2f getSize() = 0;

private:
	sf::Vector2f default_size = sf::Vector2f(30, 30);
	sf::VertexArray vxr;
};



