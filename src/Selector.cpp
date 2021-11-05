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
	rect.setSize(sf::Vector2f(40.f, 40.f));
	rect.setOutlineThickness(5.f);
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::Green);
	rect.setPosition(sf::Vector2f(_win.getSize().x - 52.f, 100.f));

	//Circle
	circle.setRadius(20.f);
	circle.setOutlineThickness(5.f);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineColor(sf::Color::White);
	circle.setPosition(sf::Vector2f(_win.getSize().x - 52.f, 160.f));

	//Triangle
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(0.f, 34.64f));	
	triangle.setPoint(1, sf::Vector2f(40.f, 34.64f));
	triangle.setPoint(2, sf::Vector2f(20.f, 0.f));
	triangle.setOutlineThickness(5.f);
	triangle.setFillColor(sf::Color::Transparent);
	triangle.setOutlineColor(sf::Color::White);
	triangle.setPosition(sf::Vector2f(_win.getSize().x - 52.f, 222.7f));

	//Octagon
	octagon.setPointCount(8);
	octagon.setRadius(20);
	octagon.setOutlineThickness(5.f);
	octagon.setFillColor(sf::Color::Transparent);
	octagon.setOutlineColor(sf::Color::White);
	octagon.setPosition(sf::Vector2f(_win.getSize().x - 52.f, 280.f));

	//Hexagon
	hexagon.setPointCount(6);
	hexagon.setRadius(20);
	hexagon.setOutlineThickness(5.f);
	hexagon.setFillColor(sf::Color::Transparent);
	hexagon.setOutlineColor(sf::Color::White);
	hexagon.setPosition(sf::Vector2f(_win.getSize().x - 12.f, 340.f));
	hexagon.setRotation(90.f);

	//Arc

	arc.setPointCount(61);
	for (size_t i = 0; i < arc.getPointCount(); i++)
	{
		arc.setPoint(i, sf::Vector2f(20.f - cos(THETA * i) * 20.f, 40.f - sin(THETA * i)* 30.f ));
	}
	arc.setPosition(sf::Vector2f(_win.getSize().x - 52.f, 390.f));
	arc.setOutlineThickness(5.f);
	arc.setFillColor(sf::Color::Transparent);
	arc.setOutlineColor(sf::Color::White);

	//Line
	line_box.setSize(sf::Vector2f(40.f, 40.f));
	line.setSize(sf::Vector2f(2.f, 40.f));
	line.setRotation(90.f);
	line.setOutlineThickness(2.5f);
	line.setFillColor(sf::Color::White);
	line.setOutlineColor(sf::Color::White);
	line.setPosition(sf::Vector2f(_win.getSize().x - 12.f, 465.f)); \
	line_box.setPosition(sf::Vector2f(_win.getSize().x - 52.f, 445.f));
	
	//Dot
	dot.setRadius(3.f);
	dot.setOutlineThickness(5.f);
	dot.setFillColor(sf::Color::White);
	dot.setOutlineColor(sf::Color::White);
	dot.setPosition(sf::Vector2f(_win.getSize().x - 34.f, 500.f));

	//Selector box
	selector_box.setSize(sf::Vector2f(60.f, 436.f));
	selector_box.setOutlineThickness(5.f);
	selector_box.setFillColor(sf::Color::Color(169, 169, 169));
	selector_box.setOutlineColor(sf::Color::Color(169, 169, 169));
	selector_box.setPosition(sf::Vector2f(_win.getSize().x - 60.f, 90.f));
}

void Selector::updateInput(sf::Mouse& _mouse, sf::RenderWindow& _window)
{
	sf::Vector2f mouse_pos = sf::Vector2f(_mouse.getPosition(_window));

	if (rect.getGlobalBounds().contains(mouse_pos) && selected_shape != 1) {	//rectangle
		rect.setOutlineColor(sf::Color::Red);
		if (_mouse.isButtonPressed(sf::Mouse::Left)) 
		{
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

	if (octagon.getGlobalBounds().contains(mouse_pos) && selected_shape != 4) {	//octagon
		octagon.setOutlineColor(sf::Color::Red);

		if (_mouse.isButtonPressed(sf::Mouse::Left))
		{
			selected_shape = 4;
			octagon.setOutlineColor(sf::Color::Green);
		}
	}
	else if (selected_shape != 4)
		octagon.setOutlineColor(sf::Color::White);

	if (hexagon.getGlobalBounds().contains(mouse_pos) && selected_shape != 5) {	//hexagon
		hexagon.setOutlineColor(sf::Color::Red);

		if (_mouse.isButtonPressed(sf::Mouse::Left))
		{
			selected_shape = 5;
			hexagon.setOutlineColor(sf::Color::Green);
		}
	}
	else if (selected_shape != 5)
		hexagon.setOutlineColor(sf::Color::White);

	if (arc.getGlobalBounds().contains(mouse_pos) && selected_shape != 6) {	//arc
		arc.setOutlineColor(sf::Color::Red);

		if (_mouse.isButtonPressed(sf::Mouse::Left))
		{
			selected_shape = 6;
			arc.setOutlineColor(sf::Color::Green);
		}
	}
	else if (selected_shape != 6)
		arc.setOutlineColor(sf::Color::White);

	if (line_box.getGlobalBounds().contains(mouse_pos) && selected_shape != 7) {	//line
		line.setOutlineColor(sf::Color::Red);
		line.setFillColor(sf::Color::Red);

		if (_mouse.isButtonPressed(sf::Mouse::Left))
		{
			selected_shape = 7;
			line.setFillColor(sf::Color::Green);
			line.setOutlineColor(sf::Color::Green);
		}
	}
	else if (selected_shape != 7) {

		line.setFillColor(sf::Color::White);
		line.setOutlineColor(sf::Color::White);
	}

	if (dot.getGlobalBounds().contains(mouse_pos) && selected_shape != 8) {	//dot
		dot.setOutlineColor(sf::Color::Red);
		dot.setFillColor(sf::Color::Red);

		if (_mouse.isButtonPressed(sf::Mouse::Left))
		{
			selected_shape = 8;
			dot.setFillColor(sf::Color::Green);
			dot.setOutlineColor(sf::Color::Green);
		}
	}
	else if (selected_shape != 8)
	{
		dot.setFillColor(sf::Color::White);
		dot.setOutlineColor(sf::Color::White);
	}
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
	_target.draw(this->octagon);
	_target.draw(this->hexagon);
	_target.draw(this->arc);
	_target.draw(this->line);
	_target.draw(this->dot);
}


