#pragma once

#include "Circle.h"

class Shape
{
public:
	Shape(sf::Vector2i _pos);
	Shape(sf::Vector2i _pos, sf::Vector2f _size);
	~Shape();

	void changeSize(sf::Vector2f _delta);

	sf::Vector2f getSize();
	void setPosition(sf::Vector2i _pos);

	virtual void render(sf::RenderTarget& _t);

private:
	sf::Vector2f size = sf::Vector2f(30, 30);
	sf::VertexArray vxr;
};



