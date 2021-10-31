#include "Shape.h"

Shape* Shape::create(int _id, sf::Vector2i _pos, sf::Vector2f _size)
{
	switch (_id)
	{
	case 1:
		return new Circle(_pos, _size);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		return nullptr;
		break;
	}
}

Shape* Shape::createDefault(int _id, sf::Vector2i _pos)
{
	switch (_id)
	{
	case 1:
		return new Circle(_pos);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		return nullptr;
		break;
	}
}

Shape::Shape(){}

Shape::~Shape(){}

