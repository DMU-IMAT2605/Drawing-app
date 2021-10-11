#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class Draw{
private:
	sf::CircleShape circle;
	sf::RectangleShape rect;
	sf::RectangleShape line, line_box;
	sf::FloatRect mouse_rect;
	sf::ConvexShape triangle;	//point count == 3
	sf::Vector2i starting_position;
	sf::RectangleShape selector_box;
	
	void init_variables();

public:
	Draw();

	void update_input(sf::Mouse& _mouse, sf::RenderWindow& _window);
	void render(sf::RenderTarget& _target);
};

////////////////////////////////////////////////////////////
// Class definition
Draw::Draw(){
	init_variables();
}

void Draw::init_variables()
{
	//Rectangle
	rect.setSize(sf::Vector2f(30.f, 30.f));
	rect.setOutlineThickness(5.f);
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::White);
	rect.setPosition(sf::Vector2f(15.f, 100.f));

	//Circle
	circle.setRadius(15.f);
	circle.setOutlineThickness(5.f);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineColor(sf::Color::White);
	circle.setPosition(sf::Vector2f(15.f, 155.f));

	//Triangle
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(0.f, 30.f));	triangle.setPoint(1, sf::Vector2f(30.f, 30.f));	triangle.setPoint(2, sf::Vector2f(15.f, 0.f));
	triangle.setOutlineThickness(5.f);
	triangle.setFillColor(sf::Color::Transparent);
	triangle.setOutlineColor(sf::Color::White);
	triangle.setPosition(sf::Vector2f(15.f, 215.f));

	//Line
	line.setSize(sf::Vector2f(0.f, 30.f));	line_box.setSize(sf::Vector2f(35.f, 35.f));
	line.setOutlineThickness(3.f);
	line.setFillColor(sf::Color::Transparent);
	line.setOutlineColor(sf::Color::White);
	line.setPosition(sf::Vector2f(30.f, 270.f)); line_box.setPosition(sf::Vector2f(10.f, 270.f));


	//Selector box
	selector_box.setSize(sf::Vector2f(50.f, 215.f));
	selector_box.setOutlineThickness(5.f);
	selector_box.setFillColor(sf::Color::Color(169, 169, 169));
	selector_box.setOutlineColor(sf::Color::Color(169, 169, 169));
	selector_box.setPosition(sf::Vector2f(5.f, 90.f));
}

void Draw::update_input(sf::Mouse& _mouse, sf::RenderWindow& _window)
{
	sf::Vector2f mouse_pos = sf::Vector2f(_mouse.getPosition(_window));

	if (rect.getGlobalBounds().contains(mouse_pos))
		rect.setOutlineColor(sf::Color::Red);
	if (circle.getGlobalBounds().contains(mouse_pos))
		circle.setOutlineColor(sf::Color::Red);
	if (triangle.getGlobalBounds().contains(mouse_pos))
		triangle.setOutlineColor(sf::Color::Red);
	if (line_box.getGlobalBounds().contains(mouse_pos))
		line.setOutlineColor(sf::Color::Red);
	
}

void Draw::render(sf::RenderTarget& _target)
{
	_target.draw(this->selector_box);

	_target.draw(this->rect);
	_target.draw(this->circle);
	_target.draw(this->triangle);
	_target.draw(this->line);
}