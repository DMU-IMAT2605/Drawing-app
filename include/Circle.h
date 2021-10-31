#pragma once

#include <Shape.h>

#define PI 3.14159265
#define RESOLUTION 360
#define RAD (PI/60)


class Circle: public Shape
{
public:
	Circle();
	Circle(sf::Vector2i _pos);
	Circle(sf::Vector2i _pos, sf::Vector2f _size);
	~Circle();

	void changeSize(sf::Vector2f _delta);
	void setPosition(sf::Vector2i _pos);
	void render(sf::RenderTarget& _t);

private:
	sf::VertexArray vxr;
};


