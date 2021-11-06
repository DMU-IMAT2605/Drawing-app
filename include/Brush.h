#pragma once
#include "Shape.h"
/// <summary>
/// This class draws multiple circles imitating a brush
class Brush : public Shape
{
public:
	/// <summary>
	/// Overridden contructor that creates an brush with default dimensions.
	/// @param _pos is mouse position.
	Brush(sf::Vector2i _pos);
	/// Deconstructor
	///> *Empty*
	~Brush();

	void changeSize(sf::Vector2f _delta);
	void setPosition(sf::Vector2i _pos);
	void render(sf::RenderTarget& _t);

private:
	///Default brush size.
	int brush_size = 5;
	/// Creates a simple circle using SFML.
	///> *I'm changing cariable type from VertexArray to CircleShape in order to make the computations easier.*
	sf::CircleShape circle;
/// </summary>
};


