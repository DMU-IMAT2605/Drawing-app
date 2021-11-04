#include "Hexagon.h"

Hexagon::Hexagon(sf::Vector2i _pos)
{
	this->vxr.resize(7);
	this->vxr.setPrimitiveType(sf::LinesStrip);

	for (size_t i = 0; i < vxr.getVertexCount(); i++)
	{
		this->vxr[i] = sf::Vector2f(_pos.x + cos((PI/3) * i) * shape_size.x, _pos.y + sin((PI / 3) * i) * shape_size.y);
	}

	this->vxr[vxr.getVertexCount() - 1] = vxr[0];
}

Hexagon::Hexagon(sf::Vector2i _pos, sf::Vector2f _size)
{
	this->vxr.resize(7);
	this->vxr.setPrimitiveType(sf::LinesStrip);

	for (size_t i = 0; i < vxr.getVertexCount(); i++)
	{
		this->vxr[i] = sf::Vector2f(_pos.x + cos((PI / 3) * i) * _size.x, _pos.y + sin((PI / 3) * i) * _size.y);

		//DONT USE IT IF YOU HAVE EPILEPSY
		//this->vxr[i].color = sf::Color::Red;
		//if (i % 2 == 0)
		//	this->vxr[i].color = sf::Color::Blue;
		//if (i % 3 == 0)
		//	this->vxr[i].color = sf::Color::Green;
	}

	this->vxr[vxr.getVertexCount() - 1] = vxr[0];
}

Hexagon::~Hexagon()
{}

void Hexagon::changeSize(sf::Vector2f _delta)
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

void Hexagon::setPosition(sf::Vector2i _pos)
{
	for (size_t i = 0; i < vxr.getVertexCount(); i++)
	{
		this->vxr[i] = sf::Vector2f(_pos.x + cos((PI / 3) * i) * shape_size.x, _pos.y + sin((PI / 3) * i) * shape_size.y);
	}

	this->vxr[vxr.getVertexCount() - 1] = vxr[0];
}

void Hexagon::render(sf::RenderTarget& _t)
{
	_t.draw(this->vxr);
}
