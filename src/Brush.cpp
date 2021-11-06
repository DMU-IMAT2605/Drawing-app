#include "Brush.h"

Brush::Brush(sf::Vector2i _pos)
{
	this->circle.setRadius(this->brush_size);
	this->circle.setPosition(sf::Vector2f(_pos));
}

Brush::~Brush()
{
}

void Brush::changeSize(sf::Vector2f _delta)
{/**/}

void Brush::setPosition(sf::Vector2i _pos)
{
	circle.setPosition(sf::Vector2f(_pos));
}

void Brush::render(sf::RenderTarget& _t)
{
	_t.draw(this->circle);
}
