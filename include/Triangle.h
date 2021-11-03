#pragma once
#include "Shape.h"
class Triangle :  public Shape
{
public:
	Triangle(sf::Vector2i _pos);
	Triangle(sf::Vector2i _pos, sf::Vector2f _size);
	~Triangle();

	void changeSize(sf::Vector2f _delta);
	void setPosition(sf::Vector2i _pos);
	void render(sf::RenderTarget& _t);

private:
	sf::VertexArray vxr;
};

