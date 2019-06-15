#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.h"
class IntroView
{
	sf::RectangleShape rect;
	sf::Font font;
	sf::Text txt;
	sf::Text txt_play;
	sf::Text identities;
	sf::RenderWindow &renderWindow;
public:
	
	IntroView(sf::RenderWindow &renderWindow);
	sf::RenderWindow &getWindow() { return renderWindow; }
	sf::RectangleShape &getRect() { return rect; }
	void draw(sf::RenderWindow &renderWindow);


};