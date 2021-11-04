#pragma once
#include "Shape.h"
class Arc : public Shape
{
public:
	Arc(sf::Vector2i _pos);
	Arc(sf::Vector2i _pos, sf::Vector2f _size);
	~Arc();

	void changeSize(sf::Vector2f _delta);
	void setPosition(sf::Vector2i _pos);
	void render(sf::RenderTarget& _t);

private:
	sf::VertexArray vxr;
};

