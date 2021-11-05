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
	std::vector<Shape*>	brush_buffer;	
	std::vector<Shape*> shapes_index_buffer;

	sf::Clock t_shapes_spawn;

	bool f_click_registered = false;
	sf::Vector2f line_position_1;

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
	Draw();
	virtual ~Draw();

	void run();
};



