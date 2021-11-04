#include "Draw.h"


Draw::Draw()
{
	this->initWindow();
	this->initShape();
	this->selector_box = new Selector(*this->window);
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

	for (auto& i : this->shapes_index_buffer)
	{
		delete i;
	}
}

void Draw::initWindow()
{
	// INITIAL VALUES
	std::string title = "Shapes";
	sf::VideoMode window_bounds(1600, 1000);
	sf::ContextSettings settings; settings.antialiasingLevel = 8;
	unsigned framerate_limit = 144;
	bool veritical_sync_enabled = false;
	// // // // // //


	this->window = new sf::RenderWindow(window_bounds,
		title, sf::Style::Titlebar
		| sf::Style::Close, settings);

	this->window->setPosition(sf::Vector2i(500, 200));

	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(veritical_sync_enabled);
}

void Draw::initShape()
{
	this->shape = new Square(mouse->getPosition(*window));	
	shapes_index_buffer.push_back(new Square(mouse->getPosition(*window)));
	shapes_index_buffer.push_back(new Circle(mouse->getPosition(*window)));
	shapes_index_buffer.push_back(new Triangle(mouse->getPosition(*window)));	
	shapes_index_buffer.push_back(new Octagon(mouse->getPosition(*window)));
	shapes_index_buffer.push_back(new Hexagon(mouse->getPosition(*window)));	
	//TODO: Implement rest of the shapes + commenting + uml

	selection_buffer[0] = 1;

}

void Draw::mouseTracker()
{
	shapes_index_buffer[selector_box->getSelected() - 1]->setPosition(mouse->getPosition(*window));
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

	this->selector_box->update_input(*this->mouse, *this->window);

	if (selector_box->contains(mouse->getPosition(*window)) == 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			this->shapes_index_buffer[selector_box->getSelected() - 1]->changeSize(sf::Vector2f(30, 30));
			this->shape->changeSize(sf::Vector2f(30, 30));
		}

		if (_e.type == sf::Event::MouseWheelMoved)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				this->shapes_index_buffer[selector_box->getSelected() - 1]->changeSize(sf::Vector2f(delta, 0));
				this->shape->changeSize(sf::Vector2f(delta, 0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
			{
				this->shapes_index_buffer[selector_box->getSelected() - 1]->changeSize(sf::Vector2f(0, delta));
				this->shape->changeSize(sf::Vector2f(0, delta));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				this->shapes_index_buffer[selector_box->getSelected() - 1]->changeSize(sf::Vector2f(delta, delta));
				this->shape->changeSize(sf::Vector2f(delta, delta));
			}
		}

		if (this->mouse->isButtonPressed(sf::Mouse::Left))
		{
			selection_buffer[1] = selection_buffer[0];
			selection_buffer[0] = selector_box->getSelected();

			if (this->t_shapes_spawn.getElapsedTime().asSeconds() >= 0.1f)
			{
				switch (selector_box->getSelected())
				{
				case 1:
					this->shapes_buffer.push_back(new Square(mouse->getPosition(*window), this->shape->getSize()));
					break;

				case 2:
					this->shapes_buffer.push_back(new Circle(mouse->getPosition(*window), this->shape->getSize()));
					break;

				case 3:
					this->shapes_buffer.push_back(new Triangle(mouse->getPosition(*window), this->shape->getSize()));
					break;

				case 4:
					this->shapes_buffer.push_back(new Octagon(mouse->getPosition(*window), this->shape->getSize()));
					break;

				case 5:
					this->shapes_buffer.push_back(new Hexagon(mouse->getPosition(*window), this->shape->getSize()));
					break;

				default:
					break;
				}
				
				this->t_shapes_spawn.restart();
			}
		}
	}
	else 
	{

		if (this->mouse->isButtonPressed(sf::Mouse::Left))
		{
			selection_buffer[1] = selection_buffer[0];
			selection_buffer[0] = selector_box->getSelected();
			if (selection_buffer[0] != selection_buffer[1]) {
				this->shapes_index_buffer[selector_box->getSelected() - 1]->changeSize(DEFAULT_SIZE);
				this->shape->changeSize(sf::Vector2f(30, 30));
			}
		}
	}
	
}

void Draw::update()
{
	this->updatePollEvents();
	this->shapeBufferHandler();
	this->mouseTracker();
	
}

void Draw::render()
{
	this->window->clear();

	for (auto&& Shapes : shapes_buffer)
	{
		Shapes->render(*this->window);
	}
	
	shapes_index_buffer[selector_box->getSelected() - 1]->render(*this->window);

	this->selector_box->render(*this->window);

	this->window->display();
}
