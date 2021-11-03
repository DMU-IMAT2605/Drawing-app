#pragma once

#include "Shape.h"
#include "Circle.h"
#include "Square.h"

class Selector
{
private:
	sf::RectangleShape selector_box;

	sf::RectangleShape rect; //id: 1
	sf::CircleShape circle;	//id: 2
	sf::ConvexShape triangle;	//id: 3
	sf::RectangleShape line, line_box;	//id::4

	int selected_shape = 1;

	void initVariables(sf::RenderWindow& _win);

public: 
	Selector(sf::RenderWindow& _win);
	~Selector();
	int getSelected();
	bool contains(sf::Vector2i _mpos);
	void update_input(sf::Mouse& _mouse, sf::RenderWindow& _window);
	void render(sf::RenderTarget& _target);
};

