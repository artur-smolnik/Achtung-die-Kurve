#pragma once
#include "SFML/Graphics.hpp"
#include "Board.h"



class BoardView
{
	int x0 = 10, y0 = 10, size = 8, gap = 0;
	
	Board &board;
	sf::Font font;
	sf::Text txt;
	sf::RectangleShape rectangleShape;
	sf::CircleShape circleShape;
	sf::RenderTexture renderTexture;
	sf::Sprite sprite;
	sf::RenderWindow &renderWindow;
	int speed;
	bool gamestartCountdown;
	
public:
	BoardView();
	BoardView(Board &board, sf::RenderWindow &renderWindow);
	void draw(sf::RenderWindow &renderWindow);
	void playAgain();
	void setSpeed(int speed) { this->speed = speed; }

};

