#pragma once

#include "SFML/Graphics.hpp"

#define PI 3.14159265

class Circle
{
public:
	Circle(sf::Vector2f _rad, sf::Vector2f _pos, int _res);
	~Circle();

	sf::VertexArray circle_shape(sf::Vector2f _rad, sf::Vector2f _pos, int _res);
	void render(sf::RenderTarget& _t);

private:
	sf::VertexArray vxr;
};



