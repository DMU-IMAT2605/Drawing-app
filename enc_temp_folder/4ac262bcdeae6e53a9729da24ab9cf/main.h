#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class Draw{
private:
	sf::CircleShape circle;
	sf::RectangleShape rect;
	sf::RectangleShape line, line_box;
	sf::ConvexShape triangle;	//point count == 3
	sf::RectangleShape selector_box;
	
	std::string selected_shape;
	sf::RectangleShape selected_rect;
	sf::CircleShape selected_circle;
	sf::ConvexShape selected_triangle;
	sf::RectangleShape selected_line;

	void init_variables();

public:
	Draw();

	std::string get_selected_item();
	sf::FloatRect _selected_obj();
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

	if (rect.getGlobalBounds().contains(mouse_pos) && selected_shape != "rectangle") {
		rect.setOutlineColor(sf::Color::Red);
		if (_mouse.isButtonPressed(sf::Mouse::Left)) {
			selected_shape = "rectangle";
			rect.setOutlineColor(sf::Color::Green);

			selected_rect.setSize(sf::Vector2f(60.f, 60.f));
			selected_rect.setOutlineThickness(3.f);
			selected_rect.setFillColor(sf::Color::Transparent);
			selected_rect.setOutlineColor(sf::Color::White);
			selected_rect.setPosition(sf::Vector2f(_window.getSize().x / 2 - selected_rect.getGlobalBounds().width / 2, _window.getSize().y / 2 - selected_rect.getGlobalBounds().height / 2));
		}
	}
	else if (selected_shape != "rectangle")
		rect.setOutlineColor(sf::Color::White);

	if (circle.getGlobalBounds().contains(mouse_pos) && selected_shape != "circle") {
		circle.setOutlineColor(sf::Color::Red);
		if (_mouse.isButtonPressed(sf::Mouse::Left))
		{
			selected_shape = "circle";
			circle.setOutlineColor(sf::Color::Green);

			selected_circle.setRadius(25.f);
			selected_circle.setOutlineThickness(5.f);
			selected_circle.setFillColor(sf::Color::Transparent);
			selected_circle.setOutlineColor(sf::Color::White);
			selected_circle.setPosition(sf::Vector2f(_window.getSize().x / 2 - selected_circle.getGlobalBounds().width / 2, _window.getSize().y / 2 - selected_circle.getGlobalBounds().height / 2));
		}
	}
	else if (selected_shape != "circle")
		circle.setOutlineColor(sf::Color::White);

	if (triangle.getGlobalBounds().contains(mouse_pos) && selected_shape != "triangle") {
		triangle.setOutlineColor(sf::Color::Red);

		if (_mouse.isButtonPressed(sf::Mouse::Left))
		{
			selected_shape = "triangle";
			triangle.setOutlineColor(sf::Color::Green);

			selected_triangle.setPointCount(3);
			selected_triangle.setPoint(0, sf::Vector2f(0.f, 50.f));	selected_triangle.setPoint(1, sf::Vector2f(50.f, 50.f));	selected_triangle.setPoint(2, sf::Vector2f(25.f, 0.f));
			selected_triangle.setOutlineThickness(3.f);
			selected_triangle.setFillColor(sf::Color::Transparent);
			selected_triangle.setOutlineColor(sf::Color::White);
			selected_triangle.setPosition(sf::Vector2f(_window.getSize().x / 2 - selected_triangle.getGlobalBounds().width / 2, _window.getSize().y / 2 - selected_triangle.getGlobalBounds().height / 2));
		}
	}
	else if (selected_shape != "triangle")
		triangle.setOutlineColor(sf::Color::White);
	
	if (line_box.getGlobalBounds().contains(mouse_pos) && selected_shape != "line") {
		line.setOutlineColor(sf::Color::Red);

		if (_mouse.isButtonPressed(sf::Mouse::Left))
		{
			selected_shape = "line";
			line.setOutlineColor(sf::Color::Green);


			selected_line.setSize(sf::Vector2f(0.f, 50.f));
			selected_line.setOutlineThickness(1.5f);
			selected_line.setFillColor(sf::Color::Transparent);
			selected_line.setOutlineColor(sf::Color::White);
			selected_line.setPosition(sf::Vector2f(_window.getSize().x / 2 - selected_line.getGlobalBounds().width / 2, _window.getSize().y / 2 - selected_line.getGlobalBounds().height / 2));
		}
	}
	else if (selected_shape != "line")
		line.setOutlineColor(sf::Color::White);
}

std::string Draw::get_selected_item() {
	return selected_shape;
}

sf::FloatRect Draw::_selected_obj() {
	if (selected_shape == "rectangle")
		return selected_rect.getGlobalBounds();

	//if (selected_shape == "triangle")
	//	return selected_triangle.getGlobalBounds();

	//if (selected_shape == "circle")
	//	return selected_circle.getGlobalBounds();

	//if (selected_shape == "line")
	//	return selected_line.getGlobalBounds();
}

void Draw::render(sf::RenderTarget& _target)
{
	_target.draw(this->selector_box);

	if (selected_shape == "rectangle")
		_target.draw(this->selected_rect);
	else if (selected_shape == "circle")
		_target.draw(this->selected_circle);
	else if (selected_shape == "triangle")
		_target.draw(this->selected_triangle);
	else if (selected_shape == "line")
		_target.draw(this->selected_line);

	_target.draw(this->rect);
	_target.draw(this->circle);
	_target.draw(this->triangle);
	_target.draw(this->line);
}




