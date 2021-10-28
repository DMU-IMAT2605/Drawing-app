#include "Draw.h"


Draw::Draw()
{
	this->initWindow();
}

Draw::~Draw()
{
	delete this->window;

	for (auto& i : this->shapes_buffer)
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
	shapes_buffer.push_back(new Shape(sf::Vector2f(30.f, 30.f), _m.getPosition(_w), 120));
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

		updateInput(Session);
	}
}

void Draw::updateInput(sf::Event _e)
{	
	if (this->mouse->isButtonPressed(sf::Mouse::Left))
	{
		if (this->t_shapes_spawn.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->drawShape(*mouse, *window);
			this->t_shapes_spawn.restart();
		}
	}

	if (_e.type == sf::Event::MouseWheelMoved)
	{
		// display number of ticks mouse wheel has moved
		std::cout << _e.mouseWheel.delta << '\n';
	}
}

void Draw::update()
{
	this->updatePollEvents();
	this->shapeBufferHandler();

}

void Draw::render()
{
	this->window->clear();

	for (auto* Circle : this->shapes_buffer)
	{
		Circle->render(*this->window);
	}


	this->window->display();
}
