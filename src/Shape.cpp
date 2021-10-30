#include "Shape.h"

Shape::Shape(sf::Vector2i _pos)
{
	this->vxr.resize(RESOLUTION);
	this->vxr.setPrimitiveType(sf::LinesStrip);

	for (size_t i = 0; i < RESOLUTION; i++)
	{
		//float radians = (360 / RESOLUTION * i) / (360 / PI / 2);
		this->vxr[i] = sf::Vector2f(_pos.x + cos(RAD * i) * default_size.x, _pos.y + sin(RAD * i) * default_size.y);
	}

	this->vxr[RESOLUTION - 1] = vxr[0];
}

Shape::Shape(sf::Vector2i _pos, sf::Vector2f _size)
{
	this->vxr.resize(RESOLUTION);
	this->vxr.setPrimitiveType(sf::LinesStrip);

	for (size_t i = 0; i < RESOLUTION; i++)
	{
		//float radians = (360 / RESOLUTION * i) / (360 / PI / 2);
		this->vxr[i] = sf::Vector2f(_pos.x + cos(RAD*i) * _size.x, _pos.y + sin(RAD*i) * _size.y);
	}

	this->vxr[RESOLUTION - 1] = vxr[0];
}

Shape::~Shape()
{

}

void Shape::changeSize(sf::Vector2f _delta)
{
	if ((this->default_size.y == 1 && _delta.y < 0) || (this->default_size.x == 1 && _delta.x < 0))
		return;

	if (_delta == sf::Vector2f(30, 30))
	{
		default_size = _delta;
		return;
	}

	this->default_size += _delta;
}

sf::Vector2f Shape::getSize()
{
	return this->default_size;
}

Shape* Shape::Create(int _id)
{
	switch (_id)
	{
	case 1:
		return new Circle;
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;

	default:
		return nullptr;
	}

}

void Shape::setPosition(sf::Vector2i _pos)
{
	for (size_t i = 0; i < RESOLUTION; i++)
	{
		//float radians = (360 / RESOLUTION * i) / (360 / PI / 2);
		this->vxr[i] = sf::Vector2f(_pos.x + cos(RAD * i) * default_size.x, _pos.y + sin(RAD * i) * default_size.y);
	}

	this->vxr[RESOLUTION - 1] = vxr[0];
}

void Shape::render(sf::RenderTarget& _t)
{
	_t.draw(this->vxr);
}

