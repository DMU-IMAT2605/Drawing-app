#pragma once

#include "Shape.h"

class Selector
{
private:
	sf::RectangleShape selector_box;

	sf::CircleShape circle;
	sf::RectangleShape rect;
	sf::RectangleShape line, line_box;
	sf::ConvexShape triangle;	

	int selected_shape;

	void initVariables(sf::RenderWindow& _win);

public:
	Selector(sf::RenderWindow& _win);
	~Selector();
	bool contains(sf::Vector2i _mpos);
	void update_input(sf::Mouse& _mouse, sf::RenderWindow& _window);
	void render(sf::RenderTarget& _target);
};

