#include "Draw.h"


Draw::Draw()
{
	this->initWindow();
	this->initShape();
	this->selector_box = new Selector(*this->window);	//test
}

Draw::~Draw()
{
	delete this->window;
	delete this->mouse;
	delete this->shape;
	delete this->selector_box;	//test

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

void Draw::initShape()
{
	this->shape = new Circle(mouse->getPosition(*window));
	shapes_buffer.push_back(new Circle(mouse->getPosition(*window)));
}

void Draw::shadowShape()
{
	shapes_buffer[0]->setPosition(mouse->getPosition(*window));
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
	int delta = _e.mouseWheel.delta; //Less memory efficient but makes it easier to read the code. Fair trade IMHO

	if (selector_box->contains(mouse->getPosition(*window)) == 0)
	{
		if (this->mouse->isButtonPressed(sf::Mouse::Left))
		{
			if (this->t_shapes_spawn.getElapsedTime().asSeconds() >= 0.1f)
			{
				this->shapes_buffer.push_back(new Circle(mouse->getPosition(*window), shape->getSize()));
				this->t_shapes_spawn.restart();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			this->shapes_buffer[0]->changeSize(sf::Vector2f(30, 30));
			this->shape->changeSize(sf::Vector2f(30, 30));
		}

		if (_e.type == sf::Event::MouseWheelMoved)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				this->shapes_buffer[0]->changeSize(sf::Vector2f(delta, 0));
				this->shape->changeSize(sf::Vector2f(delta, 0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
			{
				this->shapes_buffer[0]->changeSize(sf::Vector2f(0, delta));
				this->shape->changeSize(sf::Vector2f(0, delta));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				this->shapes_buffer[0]->changeSize(sf::Vector2f(delta, delta));
				this->shape->changeSize(sf::Vector2f(delta, delta));
			}
		}
	}
}

void Draw::update()
{
	this->updatePollEvents();
	this->shapeBufferHandler();
	this->shadowShape();
	this->selector_box->update_input(*this->mouse, *this->window);	//test
}

void Draw::render()
{
	this->window->clear();


	for (auto* Shapes : this->shapes_buffer)

	{
		Shapes->render(*this->window);
	}
	this->selector_box->render(*this->window);	//test

	this->window->display();
}
