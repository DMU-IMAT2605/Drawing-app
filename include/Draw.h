#pragma once
#pragma once

#include "Shape.h"
#include "Circle.h"

class Draw

{
private:
	// Vars - PR
	sf::RenderWindow* window;
	sf::Mouse* mouse;
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



