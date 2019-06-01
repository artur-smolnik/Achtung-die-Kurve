#pragma once
#include "SFML/Graphics.hpp"
#include "Board.h"




class BoardView
{
	int x0 = 10, y0 = 10, size = 4, gap = 2;
	std::vector<sf::RectangleShape> rectangles;
	Board &board;
	void setRectanglesVector();
	void setWindowSize(sf::RenderWindow &renderWindow);
	sf::Font font;
	sf::Text txt;

	sf::RectangleShape arrowsRectangle, wsadRectangle;
public:
	BoardView();
	BoardView(Board &board);
	void draw(sf::RenderWindow &renderWindow);

};

