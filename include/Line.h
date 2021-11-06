#pragma once
#include "Shape.h"

/// This class draws a line
class Line : public Shape
{
public:
	/// <summary>
	/// Default constructor
	Line() {};
	/// Overridden contructor that creates a line.
	/// @param _f is mosue's position when the first click is registered
	/// @param _s is mosue's position when the second click is registered
	Line(sf::Vector2f _f, sf::Vector2f _s);
	/// Deconstructor
	///> *Empty*
	~Line();
	
	void render(sf::RenderTarget& _t);

private:
	/// An array that stores positions of all of the vertexes of a shape.
	sf::VertexArray vxr;
	/// This method is unused, because it does not apply \link Line \linkend's properties
	///> *Empty*
	void setPosition(sf::Vector2i _pos);	
	/// This method is unused, because it does not apply \link Line \linkend's properties
	///> *Empty*
	void changeSize(sf::Vector2f _delta);	
	/// </summary>
};


