#include "Draw.h"


Draw::Draw()
{
	this->initWindow();
	this->initCircle();
}

Draw::~Draw()
{
	delete this->window;
	
	for (auto &i : this->shapes_buffer)
	{
		delete i;
	}
}

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

void Draw::drawShape(sf::Mouse& _m, sf::Window& _w)
{
	shapes_buffer.push_back(new Shape(/* put code here */);
}

void Draw::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Draw::shapeBufferHandler()
{
	if (this->shapes_buffer.size() > 1000)
	{
		this->shapes_buffer.erase(this->shapes_buffer.begin());
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

void Draw::updateInput()
{
	if (mouse->isButtonPressed(sf::Mouse::Left))
	{
		if (this->t_shapes_spawn.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->drawCircle(*mouse, *window);
			this->t_shapes_spawn.restart();
		}
	}
}

void Draw::update()
{
	this->updatePollEvents();
	this->updateInput();
	this->shapeBufferHandler();
	
}

void Draw::render()
{
	this->window->clear();

	for (auto *Circle : this->shapes_buffer)
	{
		Circle->render(*this->window);
	}


	this->window->display();
}
