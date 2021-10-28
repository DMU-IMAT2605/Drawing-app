#include "Shape.h"

Shape::Shape(sf::Vector2f _rad, sf::Vector2i _pos, size_t _res)
{
	vxr.resize(_res);
	vxr.setPrimitiveType(sf::LinesStrip);

	for (size_t i = 0; i < _res; i++)
	{
		float radians = (360 / _res * i) / (360 / PI / 2);
		vxr[i] = sf::Vector2f(_pos.x + cos(radians) * _rad.x, _pos.y + sin(radians) * _rad.y);
	}

	vxr[_res - 1] = vxr[0];
}

Shape::~Shape()
{

}

void Shape::render(sf::RenderTarget& _t)
{
	_t.draw(this->vxr);
}

