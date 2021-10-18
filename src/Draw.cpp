#include "Draw.h"

void Draw::initWindow()
{
	// INITIAL VALUES
	std::string title = "Shapes";
	sf::VideoMode window_bounds(1600, 1000);
	unsigned framerate_limit = 144;
	bool veritical_sync_enabled = false;
	// // // // // //


	this->window = new sf::RenderWindow(window_bounds,
		title, sf::Style::Titlebar
		| sf::Style::Close);

	this->window->setPosition(sf::Vector2i(500, 200));

	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(veritical_sync_enabled);
}

Draw::Draw()
{
	this->initWindow();
	
	this->circle = new Circle(sf::Vector2f(100.f, 100.f), sf::Vector2f(400.f, 400.f), 90);
}

Draw::~Draw()
{
	delete this->window;
}

void Draw::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Draw::updatePollEvents()
{
	sf::Event Session;
	while (this->window->pollEvent(Session))
	{
		if (Session.Event::type == sf::Event::Closed || Session.key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Draw::update()
{
	this->updatePollEvents();

	// Write code here...
}

void Draw::render()
{
	this->window->clear();

	this->circle->render(*this->window);

	this->window->display();
}
