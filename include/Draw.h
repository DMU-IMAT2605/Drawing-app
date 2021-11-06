#pragma once

#include "Selector.h"

/// Draws shapes and selector menu on the screen
/// 
///	Draw utilises all of the existing classes and has most of its functions labeled as private for a better security.
/// Instantiates pointers to the subclasses constructors as well as creates pointer-type containers for those classes.
/// Has a timer and initialization functions as well as updaters and render handler.
/// 
class Draw
/// <summary>
{
private:
	///Render Window object.
	sf::RenderWindow* window;
	///Mouse object.
	sf::Mouse* mouse;
	///Selector object.
	///@see Selector
	Selector* selector_box;	
	///Shape object
	///@see Shape
	Shape* shape;

	/// Stores all the shapes rendered on screen.
	///> MAX size == 1000
	std::vector<Shape*> shapes_buffer;
	/// Stores the Brush trail, because we don't want \link shapes_buffer \endlink to end up 
	/// running out of memory. Long Brush inputs could take up a lot of space in memory.
	std::vector<Shape*>	brush_buffer;	
	/// Stores the "default" constructor parameters of a Shape to be displayed on the screen dynamically.
	/// Each Shape has its own id:
	/// Stores the "default" constructor parameters of a Shape to be displayed on the screen dynamically.
	/// Each Shape has its own id:
	/// - Square id: 1
	/// - Circle id: 2
	/// - Triangle id: 3
	/// - Octagon id: 4
	/// - Hexagon id: 5
	/// - Arc id: 6
	/// - Line id: 7
	/// - Brush id: 8
	std::vector<Shape*> shapes_index_buffer;
	/// Stores id's of the current and previous shapes put on screen.
	///> Need this in order to set shape's size to the default in case it's been changed.
	int selection_buffer[2];
	/// Doesn't let you draw more than one shape every 0.5 seconds.
	sf::Clock t_shapes_spawn;
	/// Tells whether line's first point has been captured
	bool f_click_registered = false;
	/// Captures line's first point
	sf::Vector2f p1;

	/// Initializes window with the preset instructions
	void initWindow();
	///	Initializes Shape class and pushes it back into the \link shapes_buffer \endlink. 
	/// Sets \link selection_buffer \endlink  to the default starting value. 
	void initShape();
	/// Sets \link shapes_index_buffer \endlink to the cursor position.
	///> shapes_index_buffer is an indexator of the selected shape.
	void mouseTracker();
	/// Keeps \link shapes_buffer \endlink size less than 1000 pieces.
	/// @see brush_buffer is a separate container for the Brush subclass of Shape.
	void shapeBufferHandler();
	/// Runs the event loop.
	void updatePollEvents();
	/// Gets the user input and binds it with transformation functions within Shape class.
	/// <param name="_e"> 
	/// is a refrence to the local sf::Event variable used in \link updatePollEvents() \endlink. 
	/// 
	/// Input is being updated within the event loop, which runs constantly while using the app.
	/// </param>
	///> Located inside \link updatePollEvent() \endlink.
	void updateInput(sf::Event& _e);
	/// Container function for all of the other update methods.
	///> Located inside \link run() \endlink.
	void update();
	/// Container function for all of the other render methods.
	///> Located inside \link run() \endlink.
	void render();

public: 

	/// Contains other classes' constructors and initialization functions which contain contructors as well.
	Draw();
	/// Releases all the memory from the heap when the poll events stop.
	virtual ~Draw();
	/// Starts the update and render functions.
	void run();
	/// </summary>
};



