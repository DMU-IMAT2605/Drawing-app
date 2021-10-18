#include "Circle.h"

Circle::Circle(sf::Vector2f _rad, sf::Vector2f _pos, int _res)
{
	circle_shape(_rad, _pos, _res);
}

Circle::~Circle()
{}

inline sf::VertexArray Circle::circle_shape(sf::Vector2f _radius, sf::Vector2f _pos, int _res)
{
	vxr.resize(_res);
	vxr.setPrimitiveType(sf::LinesStrip);

	for (size_t i = 0; i < _res; i++)
	{
		float radians = (360 / _res * i) / (360 / PI / 2);
		vxr[i] = sf::Vector2f( _pos.x + cos(radians) * _radius.x, _pos.y + sin(radians) * _radius.y);
	}
	
	vxr[_res-1] = vxr[0];
	
	return vxr;
}

void Circle::render(sf::RenderTarget& _t)
{
	_t.draw(this->vxr);
}