#pragma once

#include "SFML/Graphics.hpp"
#include "Circle.h"

class Draw_Buffer

{
private:
	// Vars - PR
	sf::RenderWindow* window;
	sf::Mouse* mouse;

	Circle* circle_shad;
	
	std::vector<Circle*> shapes_buffer;

	sf::Clock t_shapes_spawn;

	// Funcs - PR
	void initWindow();
	void initCircle();

	void drawCircle(sf::Mouse& _m, sf::Window& _w);

	void shapeBufferHandler();

	void updatePollEvents();
	void updateInput();

	void update();
	void render();

public:
	// Constr & Deconstr -
	Draw_Buffer();
	virtual ~Draw_Buffer();

	// Vars - PB

	// Funcs - PB
	void run();
};



