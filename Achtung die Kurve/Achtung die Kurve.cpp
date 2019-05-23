// Achtung die Kurve.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	sf::CircleShape shape(20.f);

	// set the shape color to green
	shape.setFillColor(sf::Color(100, 250, 50));

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		shape.setPosition(0, 0);
		window.draw(shape);

		shape.setPosition(100, 100);
		window.draw(shape);

		// end the current frame
		window.display();
	}

	return 0;
}
