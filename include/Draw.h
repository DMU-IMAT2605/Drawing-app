#pragma once

#include "Shape.h"

class Draw

{
private:
	// Vars - PR
	sf::RenderWindow* window;
	sf::Mouse* mouse;
	
	std::vector<Shape*> shapes_buffer;

	std::string choosen_shape;

	sf::Clock t_shapes_spawn;

	// Funcs - PR
	void initWindow();

	void drawShape(sf::Mouse& _m, sf::Window& _w);

	void shapeBufferHandler();

	void updatePollEvents();
	void updateInput();

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



