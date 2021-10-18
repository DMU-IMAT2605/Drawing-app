#pragma once

#include "SFML/Graphics.hpp"
#include "Circle.h"

class Draw

{
private:
	// Vars - PR
	sf::RenderWindow* window;
	Circle* circle;

	// Funcs - PR
	void initWindow();

public:
	// Constr & Deconstr -
	Draw();
	virtual ~Draw();

	// Vars - PB

	// Funcs - PB
	void run();
	void updatePollEvents();
	void update();
	void render();
};



