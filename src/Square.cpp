#include "Square.h"

Square::Square(sf::Vector2i _pos)
{
	this->vxr.resize(5);
	this->vxr.setPrimitiveType(sf::LinesStrip);

	this->vxr[0] = sf::Vector2f(_pos.x - shape_size.x, _pos.y - shape_size.y);
	this->vxr[1] = sf::Vector2f(_pos.x + shape_size.x, _pos.y - shape_size.y);
	this->vxr[2] = sf::Vector2f(_pos.x + shape_size.x, _pos.y + shape_size.y);
	this->vxr[3] = sf::Vector2f(_pos.x - shape_size.x, _pos.y + shape_size.y);
	this->vxr[4] = vxr[0];
}

Square::Square(sf::Vector2i _pos, sf::Vector2f _size)
{
	this->vxr.resize(5);
	this->vxr.setPrimitiveType(sf::LinesStrip);

	this->vxr[0] = sf::Vector2f(_pos.x - _size.x, _pos.y - _size.y);
	this->vxr[1] = sf::Vector2f(_pos.x + _size.x, _pos.y - _size.y);
	this->vxr[2] = sf::Vector2f(_pos.x + _size.x, _pos.y + _size.y);
	this->vxr[3] = sf::Vector2f(_pos.x - _size.x, _pos.y + _size.y);
	this->vxr[4] = vxr[0];
}

Square::~Square()
{}

void Square::changeSize(sf::Vector2f _delta)
{
	if ((this->shape_size.y == 1 && _delta.y < 0) || (this->shape_size.x == 1 && _delta.x < 0))
		return;
	if (_delta == sf::Vector2f(30, 30))
	{
		shape_size = _delta;
		return;
	}

	this->shape_size += _delta;
}

void Square::setPosition(sf::Vector2i _pos)
{
	this->vxr[0] = sf::Vector2f(_pos.x - shape_size.x, _pos.y - shape_size.y);
	this->vxr[1] = sf::Vector2f(_pos.x + shape_size.x, _pos.y - shape_size.y);
	this->vxr[2] = sf::Vector2f(_pos.x + shape_size.x, _pos.y + shape_size.y);
	this->vxr[3] = sf::Vector2f(_pos.x - shape_size.x, _pos.y + shape_size.y);
	this->vxr[4] = vxr[0];
}

void Square::render(sf::RenderTarget& _t)
{
	_t.draw(this->vxr);
}
