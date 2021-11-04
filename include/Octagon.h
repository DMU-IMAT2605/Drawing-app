#pragma once
#include "Shape.h"
class Octagon :	public Shape
{
public:
	Octagon(sf::Vector2i _pos);
	Octagon(sf::Vector2i _pos, sf::Vector2f _size);
	~Octagon();

	void changeSize(sf::Vector2f _delta);
	void setPosition(sf::Vector2i _pos);
	void render(sf::RenderTarget& _t);

private:
	sf::VertexArray vxr;
};

