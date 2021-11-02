#pragma once
#pragma once

#include "Selector.h"
#include "Circle.h"
#include "Square.h"

class Draw

{
private:
	// Vars - PR
	sf::RenderWindow* window;
	sf::Mouse* mouse;
	Selector* selector_box;	//test
	Shape* shape;

	std::vector<Shape*> shapes_buffer;

	sf::Clock t_shapes_spawn;

	// Funcs - PR
	void initWindow();
	void initShape();

	void shadowShape();

	void shapeBufferHandler();

	void updatePollEvents();
	void updateInput(sf::Event _e);

	void update();
	void render();

public: 
	// Constr & Deconstr -
	Draw();
	virtual ~Draw();

	// Vars - PB

	// Funcs - PB
	void run();
};



