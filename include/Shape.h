#pragma once

#include "Circle.h"

class Shape
{
public:
	Shape(sf::Vector2i _pos);
	Shape(sf::Vector2i _pos, sf::Vector2f _size);
	~Shape();

	/*virtual*/ void changeSize(sf::Vector2f _delta);
	/*virtual*/ void setPosition(sf::Vector2i _pos);
	/*virtual*/ void render(sf::RenderTarget& _t);
	
	/*virtual*/ sf::Vector2f getSize();

private:
	sf::Vector2f default_size = sf::Vector2f(30, 30);
	sf::VertexArray vxr;
};



