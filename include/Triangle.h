#pragma once

#include "Shape.h"

/// This class draws an triangle
class Triangle :  public Shape
{
public:
	/// <summary>
	/// Overridden contructor that creates an triangle with default dimensions.
	/// @param _pos is mouse position.
	Triangle(sf::Vector2i _pos);	
	/// Overridden contructor that creates an triangle with a custom dimensions.
	/// @param _pos is mouse position.
	/// @param _size is a value that you would like to assign to a new shape.
	Triangle(sf::Vector2i _pos, sf::Vector2f _size);
	/// Deconstructor
	///> *Empty*
	~Triangle();

	void changeSize(sf::Vector2f _delta);
	void setPosition(sf::Vector2i _pos);
	void render(sf::RenderTarget& _t);

private:
	/// An array that stores positions of all of the vertexes of a shape.
	sf::VertexArray vxr;
	/// </summary>
};

	