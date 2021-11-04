#include "Line.h"

Line::Line(sf::Vector2f _x, sf::Vector2f _y)
{
	vxr.resize(2);
	vxr.setPrimitiveType(sf::LineStrip);
	this->vxr[0] = _x;
	this->vxr[1] = _y;
}

Line::~Line()
{
}

void Line::setPosition(sf::Vector2i _pos)
{
	this->vxr[0] = sf::Vector2f(_pos);
}

void Line::changeSize(sf::Vector2f _delta)
{
	this->vxr[1] = _delta;
}

void Line::render(sf::RenderTarget& _t)
{
	_t.draw(this->vxr);
}