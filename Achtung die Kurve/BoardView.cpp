#include "pch.h"
#include "BoardView.h"
#include <Windows.h>



BoardView::BoardView(Board & board, sf::RenderWindow &renderWindow) : board(board), renderWindow(renderWindow)
{
	
	renderTexture.create(1000, 1000);
	sprite.setTexture(renderTexture.getTexture());
	circleShape.setRadius(3);
	renderTexture.display();
	speed = 4;
}





void BoardView::draw(sf::RenderWindow &renderWindow)
{
	Sleep(speed);
	
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
}
