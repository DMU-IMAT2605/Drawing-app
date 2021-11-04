#pragma once

#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Octagon.h"
#include "Hexagon.h"
#include "Arc.h"
#include "Line.h"

class Selector
{
private:
	sf::RectangleShape selector_box;
	sf::RectangleShape line_box;	

	sf::RectangleShape rect;	//id: 1
	sf::CircleShape circle;		//id: 2
	sf::ConvexShape triangle;	//id: 3
	sf::CircleShape octagon;	//id: 4
	sf::CircleShape hexagon;	//id: 5
	sf::ConvexShape arc;		//id: 6
	sf::RectangleShape line;	//id::7
	sf::CircleShape dot;		//id: 8

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

