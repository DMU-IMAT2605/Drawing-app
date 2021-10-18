#include "Draw_Buffer.h"


Draw_Buffer::Draw_Buffer()
{
	this->initWindow();
	this->initCircle();
}

Draw_Buffer::~Draw_Buffer()
{
	delete this->window;
	
	for (auto &i : this->shapes_buffer)
	{
		delete i;
	}
}

void Draw_Buffer::initWindow()
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

void Draw_Buffer::initCircle()
{
	//this->circle = new Circle;
}

void Draw_Buffer::drawCircle(sf::Mouse& _m, sf::Window& _w)
{
	shapes_buffer.push_back(new Circle(sf::Vector2f(100.f, 100.f), sf::Vector2f(_m.getPosition(_w).x, _m.getPosition(_w).y), 120));
}

void Draw_Buffer::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Draw_Buffer::shapeBufferHandler()
{
	if (this->shapes_buffer.size() > 1000)
	{
		this->shapes_buffer.erase(this->shapes_buffer.begin());
	}
}

void Draw_Buffer::updatePollEvents()
{
	sf::Event Session;
	while (this->window->pollEvent(Session))
	{
		if (Session.Event::type == sf::Event::Closed || Session.key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Draw_Buffer::updateInput()
{
	sf::Vector2f arr[2];
	if (mouse->isButtonPressed(sf::Mouse::Left))
	{

		if (this->t_shapes_spawn.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->drawCircle(*mouse, *window);
			this->t_shapes_spawn.restart();
		}
	}
}

void Draw_Buffer::update()
{
	this->updatePollEvents();
	this->updateInput();
	this->shapeBufferHandler();
	
}

void Draw_Buffer::render()
{
	this->window->clear();

	for (auto *Circle : this->shapes_buffer)
	{
		Circle->render(*this->window);
	}


	this->window->display();
}
