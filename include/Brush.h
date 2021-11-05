#pragma once
#include "Shape.h"

class Brush : public Shape
{
public:
	Brush(sf::Vector2i _pos);
	~Brush();

	void changeSize(sf::Vector2f _delta);
	void setPosition(sf::Vector2i _pos);
	void render(sf::RenderTarget& _t);

private:
	//I'm changing cariable type to CircleShape in order to make the computations easier
	int brush_size = 5;
	sf::CircleShape vxr;
};

