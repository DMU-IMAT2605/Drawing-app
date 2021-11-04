#include "Brush.h"

Brush::Brush(sf::Vector2i _pos)
{
	this->vxr.setRadius(this->brush_size);
	this->vxr.setPosition(sf::Vector2f(_pos));
}

Brush::~Brush()
{
}

void Brush::changeSize(sf::Vector2f _delta)
{/**/}

void Brush::setPosition(sf::Vector2i _pos)
{
	vxr.setPosition(sf::Vector2f(_pos));
}

void Brush::render(sf::RenderTarget& _t)
{
	_t.draw(this->vxr);
}
