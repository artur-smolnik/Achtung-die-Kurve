#include "pch.h"
#include "BoardView.h"
#include <Windows.h>
#include <iostream>



BoardView::BoardView(Board & board, sf::RenderWindow &renderWindow) : board(board), renderWindow(renderWindow)
{
	
	renderTexture.create(1000, 1000);
	//renderTexture.setSmooth(true);
	sprite.setTexture(renderTexture.getTexture());
	
	//renderTexture.clear();
	circleShape.setRadius(3);
	
	setWindowSize(renderWindow);

	renderTexture.display();
	
}



void BoardView::setWindowSize(sf::RenderWindow &renderWindow)
{
	int x, y;
	/*x = board.getColumns() * size + 2 * x0 + (board.getColumns() - 1)*gap;
	y = board.getRows() * size + 2 * y0 + (board.getRows() - 1)*gap;*/
	sf::View view;
	view.setSize(renderWindow.getSize().x, renderWindow.getSize().y);
	renderWindow.setView(view);
	renderWindow.create(sf::VideoMode(1000, 1000), "Kurve Fever");
}


void BoardView::draw(sf::RenderWindow &renderWindow)
{
	Sleep(5);
	/*if(board.detectCollision(board.getPlayerArrows().row, board.getPlayerArrows().col)!=-1)
	std::cout << board.detectCollision(board.getPlayerArrows().row, board.getPlayerArrows().col);*/

	board.move();
	if (!(renderWindow.getSize().x == board.getColumns() * size + 2 * x0 + (board.getColumns() - 1)*gap && renderWindow.getSize().y == board.getRows() * size + 2 * y0 + (board.getRows() - 1)*gap)) //do once
	{
		
	}

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
	setWindowSize(renderWindow);
}
