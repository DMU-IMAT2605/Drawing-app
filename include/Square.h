#pragma once

#include "Shape.h"

//#define DEF_SIZE_X def_size.x / 2
//#define DEF_SIZE_Y def_size.y / 2

class Square :	public Shape
{
public:
	Square(sf::Vector2i _pos);
	Square(sf::Vector2i _pos, sf::Vector2f _size);
	~Square();

	void changeSize(sf::Vector2f _delta);
	void setPosition(sf::Vector2i _pos);
	void render(sf::RenderTarget& _t);

private:
		sf::VertexArray vxr;
};

