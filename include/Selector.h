#pragma once

#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Octagon.h"
#include "Hexagon.h"
#include "Arc.h"
#include "Line.h"
#include "Brush.h"

/// Creates selector menu and input buttons
/// 
/// This UI helps tracking previously used shapes, indicates currently selected shape and allows user input.

class Selector
{
private:
	/// <summary>
	/// Background shape.
	sf::RectangleShape selector_box; 
	/// Line's extended hit box.
	sf::RectangleShape line_box;	

	/// Square's button image.
	sf::RectangleShape rect;	//id: 1
	/// Circle's button image.
	sf::CircleShape circle;		//id: 2
	/// Triangle's button image.
	sf::ConvexShape triangle;	//id: 3
	/// Octagon's button image.
	sf::CircleShape octagon;	//id: 4
	/// Hexagon's button image.
	sf::CircleShape hexagon;	//id: 5
	/// Arc's button image.
	sf::ConvexShape arc;		//id: 6
	/// Line's button image.
	sf::RectangleShape line;	//id::7
	/// Brush's button image.
	sf::CircleShape brush;		//id: 8

	/// Starting shape pushed into buffer.
	int selected_shape = 1;

	/// Initializes shapes buttons' settings.
	/// @param &_win is a refrence to the \link window \endlink in Draw.
	void initVariables(sf::RenderWindow& _win);

public: 
	/// Selector box constructor.
	/// @param &_win is a refrence to the \link window \endlink in Draw.
	Selector(sf::RenderWindow& _win);
	/// Destructor
	~Selector();
	///	Gets updated whenever shape button is pressed.
	/// @return Selected Shape.
	int getSelected();
	///	Tells, whether mouse cursor is currently inside selector box.
	/// @param _mpos is a variable describing \link mouse \endlink position.
	/// @return bool depending on \link mouse \endlink position relatively to the \link window \endlink.
	///> Located inside \link updateInput() \endlink.
	bool contains(sf::Vector2i _mpos);
	/// Gets mouse position relative to the window and updates selected shape in case one of the buttons is pressed.
	/// @param _mouse is a refrence to an actual mouse object in Draw. 
	/// @param _window is a refrence to an actual window object in Draw.
	void updateInput(sf::Mouse& _mouse, sf::RenderWindow& _window);
	/// Renders selector box on screen.
	/// @param &_target is a refrence to the \link window \linkend
	void render(sf::RenderTarget& _target);
	/// </summary>
};

