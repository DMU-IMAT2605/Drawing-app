#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
/// Pi number.
#define PI 3.14159265
/// Amount of steps in calculating a circle.
#define RESOLUTION 121
/// Degree value of each step.
#define THETA (PI/60)
/// Any shape's default size
#define DEFAULT_SIZE sf::Vector2f(30, 30);
/// 
/// Virtual base class for geometrical shapes.
///
/// Contains a template of functions that useful in handling any shapes available through this app.
/// 
class Shape
{
public:
	/// <summary>
	/// Constructor.
	///> *empty*
	Shape();
	/// Virtual destructor.
	///> *empty*
	virtual ~Shape();
	/// Changes shape's size depending on input (*see also*).
	/// @param _delta is a two dimensional vector that gets mosuewheel input goes from -1 to 1 in both **X** & **Y**.
	/// @see [***User Manual***](../html/index.html "Link title")
	virtual void changeSize(sf::Vector2f _delta) = 0;
	/// Sets position for the shape indexator.
	/// It isn't necesarily used to set shape's position as it's usually done by the constructor.
	/// @param _pos is mouse position.
	virtual void setPosition(sf::Vector2i _pos) = 0;
	/// Renders shape on screen.
	/// @param &_target is a refrence to the \link window \linkend
	virtual void render(sf::RenderTarget& _t) = 0;
	/// Gets current size of a shape
	/// @return \link shape_size \linkend
	sf::Vector2f getSize() { return this->shape_size; };
	
protected:
	/// Shape size initialized with the default value.
	sf::Vector2f shape_size = DEFAULT_SIZE;
	/// </summary>
};



