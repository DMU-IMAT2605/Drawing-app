#include "Arc.h"

Arc::Arc(sf::Vector2i _pos)
{
	this->vxr.resize(61);
	this->vxr.setPrimitiveType(sf::LinesStrip);

	for (size_t i = 0; i < vxr.getVertexCount(); i++)
	{
		this->vxr[i] = sf::Vector2f( _pos.x - cos(THETA * i) * shape_size.x, _pos.y - sin(THETA * i) * shape_size.y);
	}


}

Arc::Arc(sf::Vector2i _pos, sf::Vector2f _size)
{
	this->vxr.resize(61);
	this->vxr.setPrimitiveType(sf::LinesStrip);

	for (size_t i = 0; i < vxr.getVertexCount(); i++)
	{
		this->vxr[i] = sf::Vector2f(_pos.x - cos(THETA * i) * _size.x, _pos.y - sin(THETA * i) * _size.y);

		//DONT USE IT IF YOU HAVE EPILEPSY
		//this->vxr[i].color = sf::Color::Red;
		//if (i % 2 == 0)
		//	this->vxr[i].color = sf::Color::Blue;
		//if (i % 3 == 0)
		//	this->vxr[i].color = sf::Color::Green;
	}
}

Arc::~Arc()
{}

void Arc::changeSize(sf::Vector2f _delta)
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

void Arc::setPosition(sf::Vector2i _pos)
{
	for (size_t i = 0; i < vxr.getVertexCount(); i++)
	{
		this->vxr[i] = sf::Vector2f(_pos.x - cos(THETA * i) * shape_size.x, _pos.y - sin(THETA * i) * shape_size.y);
	}
}

void Arc::render(sf::RenderTarget& _t)
{
	_t.draw(this->vxr);
}
