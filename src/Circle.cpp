#include "Circle.h"

Circle::Circle(sf::Vector2i _pos)
{
	this->vxr.resize(RESOLUTION);
	this->vxr.setPrimitiveType(sf::LinesStrip);

	for (size_t i = 0; i < RESOLUTION; i++)
	{
		this->vxr[i] = sf::Vector2f(_pos.x + cos(RAD * i) * size.x, _pos.y + sin(RAD * i) * size.y);
	}

	this->vxr[RESOLUTION - 1] = vxr[0];
}

Circle::Circle(sf::Vector2i _pos, sf::Vector2f _size)
{
	this->vxr.resize(RESOLUTION);
	this->vxr.setPrimitiveType(sf::LinesStrip);

	for (size_t i = 0; i < RESOLUTION; i++)
	{
		this->vxr[i] = sf::Vector2f(_pos.x + cos(RAD * i) * _size.x, _pos.y + sin(RAD * i) * _size.y);
	}

	this->vxr[RESOLUTION - 1] = vxr[0];
}

Circle::~Circle()
{}

void Circle::changeSize(sf::Vector2f _delta)
{
	if ((this->size.y == 1 && _delta.y < 0) || (this->size.x == 1 && _delta.x < 0))
		return;
	if (_delta == sf::Vector2f(30, 30))
	{
		size = _delta;
		return;
	}

	this->size += _delta;
}

void Circle::setPosition(sf::Vector2i _pos)
{
	for (size_t i = 0; i < RESOLUTION; i++)
	{
		this->vxr[i] = sf::Vector2f(_pos.x + cos(RAD * i) * size.x, _pos.y + sin(RAD * i) * size.y);
	}

	this->vxr[RESOLUTION - 1] = vxr[0];
}

void Circle::render(sf::RenderTarget& _t)
{
	_t.draw(this->vxr);
}




