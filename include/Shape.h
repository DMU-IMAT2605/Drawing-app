#pragma once

#include "Circle.h"

class Shape
{
public:
	Shape(sf::Vector2f _rad, sf::Vector2f _pos, float _res);
	~Shape();

	virtual void render(sf::RenderTarget& _t);

private:

};

Shape::Shape(sf::Vector2f _rad, sf::Vector2f _pos, float _res)
{
	Circle(_rad, _pos, _res);
}

Shape::~Shape()
{
}