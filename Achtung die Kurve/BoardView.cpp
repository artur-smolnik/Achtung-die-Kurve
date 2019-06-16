#include "pch.h"
#include "BoardView.h"
#include <Windows.h>
#include <string>


BoardView::BoardView(Board & board, sf::RenderWindow &renderWindow) : board(board), renderWindow(renderWindow)
{
	if (!font.loadFromFile("airstrike.ttf")) {
		abort();
	}
	renderTexture.create(1000, 1000);
	sprite.setTexture(renderTexture.getTexture());
	renderTexture.clear();
	txt.setFont(font);
	txt.setFillColor(sf::Color::Red);
	txt.setOutlineColor(sf::Color::Blue);
	txt.setOutlineThickness(5);
	txt.setPosition(370, 250);
	txt.setCharacterSize(300);
	rectangleShape.setFillColor(sf::Color::Black);
	rectangleShape.setSize(sf::Vector2f(250, 250));
	rectangleShape.setPosition(375, 350);
	circleShape.setRadius(3);
	speed = 4;
	gamestartCountdown = true;
}

void BoardView::draw(sf::RenderWindow &renderWindow)
{
	if (gamestartCountdown)
	{
		renderTexture.clear();
		circleShape.setFillColor(sf::Color::Red);
		circleShape.setPosition(board.getPlayerArrows().col, board.getPlayerArrows().row);
		renderTexture.draw(circleShape);
		circleShape.setFillColor(sf::Color::Blue);
		circleShape.setPosition(board.getPlayerWsad().col, board.getPlayerWsad().row);
		renderTexture.draw(circleShape);
		
		txt.setString("3");
		renderTexture.draw(rectangleShape);
		renderTexture.draw(txt);
		renderTexture.display();
		renderWindow.draw(sprite);
		renderWindow.display();
		Sleep(1000);
		txt.setString("2");
		renderTexture.draw(rectangleShape);
		renderTexture.draw(txt);
		renderTexture.display();
		renderWindow.draw(sprite);
		renderWindow.display();
		Sleep(1000);
		txt.setString("1");
		renderTexture.draw(rectangleShape);
		renderTexture.draw(txt);
		renderTexture.display();
		renderWindow.draw(sprite);
		renderWindow.display();
		Sleep(1000);
		renderTexture.draw(rectangleShape);
		gamestartCountdown = false;
	}

	Sleep(speed);
	
	board.move();
	
	circleShape.setFillColor(sf::Color::Red);
	circleShape.setPosition(board.getPlayerArrows().col, board.getPlayerArrows().row);
	renderTexture.draw(circleShape);
	circleShape.setFillColor(sf::Color::Blue);
	circleShape.setPosition(board.getPlayerWsad().col, board.getPlayerWsad().row);
	renderTexture.draw(circleShape);
	
	
	
	
	renderTexture.display();

	renderWindow.draw(sprite);
	
	

}
void BoardView::playAgain()
{
	renderTexture.clear();
	board.playAgain();
	gamestartCountdown = true;
}
