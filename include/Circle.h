#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

#define PI 3.14159265

class Circle
{
public:
	Circle(sf::Vector2f _rad, sf::Vector2f _pos, size_t _res);
	~Circle();

	void render(sf::RenderTarget& _t);

private:
	sf::VertexArray vxr;
	sf::VertexArray circle_shape(sf::Vector2f _rad, sf::Vector2f _pos, size_t _res);
};


