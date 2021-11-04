#pragma once

#include "Selector.h"

class Draw

{
private:
	// Vars - PR
	sf::RenderWindow* window;
	sf::Mouse* mouse;
	Selector* selector_box;	//test
	Shape* shape;

	int selection_buffer[2];
	std::vector<Shape*> shapes_buffer;
	std::vector<Shape*> shapes_index_buffer;

	sf::Clock t_shapes_spawn;

	bool f_click_registered = false;
	sf::Vector2f p1, p2;

	// Funcs - PR
	void initWindow();
	void initShape();

	void mouseTracker();

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



