#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.h"
class IntroView
{
	sf::RenderTexture renderTexture;
	sf::Sprite sprite;
	sf::RectangleShape rectPlay, rectSlowSpeed, rectNormalSpeed, rectFastSpeed;
	sf::CircleShape circleShape;
	sf::Font font;
	sf::Text txt, txtPlay, txtSlowSpeed, txtNormalSpeed, txtFastSpeed;
	sf::RenderWindow &renderWindow;
public:
	
	IntroView(sf::RenderWindow &renderWindow);
	sf::RenderWindow &getWindow() { return renderWindow; }
	sf::RectangleShape &getRect() { return rectPlay; }
	void draw(sf::RenderWindow &renderWindow);
	sf::RectangleShape &getRectSlowSpeed() { return rectSlowSpeed; }
	sf::RectangleShape &getRectNormalSpeed() { return rectNormalSpeed; }
	sf::RectangleShape &getRectFastSpeed() { return rectFastSpeed; }
	sf::Text &getTxtNormal() { return txtNormalSpeed; }
	sf::Text &getTxtSlow() { return txtSlowSpeed; }
	sf::Text &getTxtFast() { return txtFastSpeed; }
};