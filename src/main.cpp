/*! \mainpage Lab 2 - Shapes
*
* This program gives you a basic SFML window in which to draw your shapes.
*
* The classes and files you use are up to you.  
*
* This software froms the basis of your submission for lab book 1
*/

/*! \file main.cpp
* \brief Main file for the application
*
* Contains the entry point of the application 
*/

#include <main.h>

int main() //!< Entry point for the application
{
	sf::RenderWindow window(sf::VideoMode(1024, 800), "Lab Book 1 - Shapes");
	window.setFramerateLimit(60);

	sf::Mouse mouse;
	Draw* drawing;
	drawing = new Draw;
	
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
			


		window.clear();
		drawing->update_input(mouse, window);
		drawing->render(window);
		window.display();
	}
}

