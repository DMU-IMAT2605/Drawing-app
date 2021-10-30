#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

#define PI 3.14159265
#define RESOLUTION 360
#define RAD (PI/60)


class Circle: public Shape
{
public:
	Circle(sf::Vector2f _rad, sf::Vector2f _pos, size_t _res);
	~Circle();

	void changeSize(sf::Vector2f _delta);
	void setPosition(sf::Vector2i _pos);
	void render(sf::RenderTarget& _t);

	sf::Vector2f getSize();

private:
	sf::VertexArray vxr;
	sf::VertexArray circle_shape(sf::Vector2f _rad, sf::Vector2f _pos, size_t _res);
};


