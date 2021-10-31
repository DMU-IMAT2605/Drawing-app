#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Shape
{
public:
	Shape();
	virtual ~Shape();
	static Shape* create(int _id, sf::Vector2i _pos, sf::Vector2f _size);
	static Shape* createDefault(int _id, sf::Vector2i _pos);

	virtual void changeSize(sf::Vector2f _delta) = 0;
	virtual void setPosition(sf::Vector2i _pos) = 0;
	virtual void render(sf::RenderTarget& _t) = 0;

	sf::Vector2f getSize() { return this->size; };
	
protected:
	sf::Vector2f size = sf::Vector2f(30, 30);
};



