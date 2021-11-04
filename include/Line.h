#pragma once
#include "Shape.h"

class Line : public Shape
{
public:
	Line() {};
	Line(sf::Vector2f _x, sf::Vector2f _y);
	~Line();

	void setPosition(sf::Vector2i _pos);	//unused
	void changeSize(sf::Vector2f _delta);	//unused
	
	void render(sf::RenderTarget& _t);

private:
	sf::VertexArray vxr;

};

