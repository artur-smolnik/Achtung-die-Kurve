#include "pch.h"
#include "BoardView.h"
#include <Windows.h>
#include <iostream>



BoardView::BoardView(Board & board) : board(board)
{
	renderTexture.create(1000, 1000);
	//renderTexture.setSmooth(true);
	sprite.setTexture(renderTexture.getTexture());
	
	//renderTexture.clear();
	circleShape.setRadius(10);
	circleShape.setPosition(board.getPlayerArrows().row, board.getPlayerArrows().col);
	renderTexture.draw(circleShape);
	circleShape.setPosition(board.getPlayerWsad().row, board.getPlayerWsad().col);
	renderTexture.draw(circleShape);

	renderTexture.display();
	//setWindowSize(renderWindow);

}



void BoardView::setWindowSize(sf::RenderWindow &renderWindow)
{
	int x, y;
	x = board.getColumns() * size + 2 * x0 + (board.getColumns() - 1)*gap;
	y = board.getRows() * size + 2 * y0 + (board.getRows() - 1)*gap;
	sf::View view;
	view.setSize(renderWindow.getSize().x, renderWindow.getSize().y);
	renderWindow.setView(view);
	renderWindow.create(sf::VideoMode(x, y), "Kurve Fever");
}


void BoardView::draw(sf::RenderWindow &renderWindow)
{
	Sleep(10);
	board.move();
	if (!(renderWindow.getSize().x == board.getColumns() * size + 2 * x0 + (board.getColumns() - 1)*gap && renderWindow.getSize().y == board.getRows() * size + 2 * y0 + (board.getRows() - 1)*gap)) //do once
	{
		
	}


	circleShape.setPosition(board.getPlayerArrows().col, board.getPlayerArrows().row);
	renderTexture.draw(circleShape);
	/*circleShape.setPosition(board.getPlayerWsad().row, board.getPlayerWsad().col);
	renderTexture.draw(circleShape);*/
	renderTexture.display();

	renderWindow.draw(sprite);
	
	

}
