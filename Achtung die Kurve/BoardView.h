#pragma once
#include "SFML/Graphics.hpp"
#include "Board.h"
#include <vector>



class BoardView
{
	int x0 = 10, y0 = 10, size = 8, gap = 0;
	
	Board &board;
	
	void setWindowSize(sf::RenderWindow &renderWindow);
	sf::Font font;
	sf::Text txt;
	
	sf::CircleShape circleShape;
	
	sf::RenderTexture renderTexture;
	sf::Sprite sprite;


	
public:
	BoardView();
	BoardView(Board &board);
	void draw(sf::RenderWindow &renderWindow);

};

