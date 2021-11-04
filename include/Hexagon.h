#pragma once
#include "Shape.h"
class Hexagon : public Shape
{
public:
	Hexagon(sf::Vector2i _pos);
	Hexagon(sf::Vector2i _pos, sf::Vector2f _size);
	~Hexagon();

	void changeSize(sf::Vector2f _delta);
	void setPosition(sf::Vector2i _pos);
	void render(sf::RenderTarget& _t);

private:
	sf::VertexArray vxr;
};

