#pragma once

#include "Shape.h"

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

