#include "Selector.h"

Selector::Selector(sf::RenderWindow& _win)
{
	initVariables(_win);
}

Selector::~Selector()
{
}

int Selector::getSelected()
{
	return selected_shape;
}

void Selector::initVariables(sf::RenderWindow& _win)
{
	//Rectangle
	rect.setSize(sf::Vector2f(30.f, 30.f));
	rect.setOutlineThickness(5.f);
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::White);
	rect.setPosition(sf::Vector2f(_win.getSize().x - 45.f, 100.f));

	//Circle
	circle.setRadius(15.f);
	circle.setOutlineThickness(5.f);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineColor(sf::Color::White);
	circle.setPosition(sf::Vector2f(_win.getSize().x - 45.f, 155.f));

	//Triangle
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(0.f, 30.f));	triangle.setPoint(1, sf::Vector2f(30.f, 30.f));	triangle.setPoint(2, sf::Vector2f(15.f, 0.f));
	triangle.setOutlineThickness(5.f);
	triangle.setFillColor(sf::Color::Transparent);
	triangle.setOutlineColor(sf::Color::White);
	triangle.setPosition(sf::Vector2f(_win.getSize().x - 45.f, 215.f));

	//Line
	line.setSize(sf::Vector2f(0.f, 30.f));	line_box.setSize(sf::Vector2f(35.f, 35.f));
	line.setOutlineThickness(3.f);
	line.setFillColor(sf::Color::Transparent);
	line.setOutlineColor(sf::Color::White);
	line.setPosition(sf::Vector2f(_win.getSize().x - 28.5f, 270.f)); line_box.setPosition(sf::Vector2f(_win.getSize().x - 45.f, 270.f));


	//Selector box
	selector_box.setSize(sf::Vector2f(50.f, 215.f));
	selector_box.setOutlineThickness(5.f);
	selector_box.setFillColor(sf::Color::Color(169, 169, 169));
	selector_box.setOutlineColor(sf::Color::Color(169, 169, 169));
	selector_box.setPosition(sf::Vector2f(_win.getSize().x - 55.f, 90.f));
}

void Selector::update_input(sf::Mouse& _mouse, sf::RenderWindow& _window)
{
	sf::Vector2f mouse_pos = sf::Vector2f(_mouse.getPosition(_window));

	if (rect.getGlobalBounds().contains(mouse_pos) && selected_shape != 1) {	//rectangle
		rect.setOutlineColor(sf::Color::Red);
		if (_mouse.isButtonPressed(sf::Mouse::Left)) {
			selected_shape = 1;
			rect.setOutlineColor(sf::Color::Green);
		}
	}
	else if (selected_shape != 1)
		rect.setOutlineColor(sf::Color::White);

	if (circle.getGlobalBounds().contains(mouse_pos) && selected_shape != 2) {	//circle
		circle.setOutlineColor(sf::Color::Red);
		if (_mouse.isButtonPressed(sf::Mouse::Left))
		{
			selected_shape = 2;
			circle.setOutlineColor(sf::Color::Green);
		}
	}
	else if (selected_shape != 2)
		circle.setOutlineColor(sf::Color::White);

	if (triangle.getGlobalBounds().contains(mouse_pos) && selected_shape != 3) {	//triangle
		triangle.setOutlineColor(sf::Color::Red);

		if (_mouse.isButtonPressed(sf::Mouse::Left))
		{
			selected_shape = 3;
			triangle.setOutlineColor(sf::Color::Green);
		}
	}
	else if (selected_shape != 3)
		triangle.setOutlineColor(sf::Color::White);

	if (line_box.getGlobalBounds().contains(mouse_pos) && selected_shape != 4) {	//line
		line.setOutlineColor(sf::Color::Red);

		if (_mouse.isButtonPressed(sf::Mouse::Left))
		{
			selected_shape = 4;
			line.setOutlineColor(sf::Color::Green);
		}
	}
	else if (selected_shape != 4)
		line.setOutlineColor(sf::Color::White);
}

bool Selector::contains(sf::Vector2i _mpos)
{
	if (selector_box.getGlobalBounds().contains(sf::Vector2f(_mpos)))
		return true;

	return false;
}

void Selector::render(sf::RenderTarget& _target)
{
	_target.draw(this->selector_box);

	_target.draw(this->rect);
	_target.draw(this->circle);
	_target.draw(this->triangle);
	_target.draw(this->line);
}


