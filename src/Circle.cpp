#include "Circle.h"

Circle::Circle(sf::Vector2i _pos)
{
	this->vxr.resize(RESOLUTION);
	this->vxr.setPrimitiveType(sf::LinesStrip);

	for (size_t i = 0; i < RESOLUTION; i++)
	{
		this->vxr[i] = sf::Vector2f(_pos.x + cos(RAD * i) * def_size.x, _pos.y + sin(RAD * i) * def_size.y);
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
		
		//DONT USE IT IF YOU HAVE EPILEPSY
		//this->vxr[i].color = sf::Color::Red;
		//if (i % 2 == 0)
		//	this->vxr[i].color = sf::Color::Blue;
		//if (i % 3 == 0)
		//	this->vxr[i].color = sf::Color::Green;
	}

	this->vxr[RESOLUTION - 1] = vxr[0];
}

Circle::~Circle()
{}

void Circle::changeSize(sf::Vector2f _delta)
{
	if ((this->def_size.y == 1 && _delta.y < 0) || (this->def_size.x == 1 && _delta.x < 0))
		return;
	if (_delta == sf::Vector2f(30, 30))
	{
		def_size = _delta;
		return;
	}

	this->def_size += _delta;
}

void Circle::setPosition(sf::Vector2i _pos)
{
	for (size_t i = 0; i < RESOLUTION; i++)
	{
		this->vxr[i] = sf::Vector2f(_pos.x + cos(RAD * i) * def_size.x, _pos.y + sin(RAD * i) * def_size.y);
	}

	this->vxr[RESOLUTION - 1] = vxr[0];
}

void Circle::render(sf::RenderTarget& _t)
{
	_t.draw(this->vxr);
}




