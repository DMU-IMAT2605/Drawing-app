#pragma once

#include "Circle.h"

class Shape
{
public:
	Shape(sf::Vector2f _rad, sf::Vector2i _pos, size_t _res);
	~Shape();

	virtual void render(sf::RenderTarget& _t);

private:
	sf::VertexArray vxr;
};



