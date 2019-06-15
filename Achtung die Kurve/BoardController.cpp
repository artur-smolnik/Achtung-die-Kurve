#include "pch.h"
#include "BoardController.h"
#include <iostream>

BoardController::BoardController(BoardView &boardView, Board &board) : boardView(boardView), board(board) {}




void BoardController::handleEvent(sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up && board.getDirection(0) != DOWN)
		{
			board.setDirection(UP, 0);
			std::cout << "UP" << std::endl;
		}
		else if (event.key.code == sf::Keyboard::Right && board.getDirection(0) != LEFT)
		{
			board.setDirection(RIGHT, 0);
			std::cout << "RIGHT" << std::endl;

		}
		else if (event.key.code == sf::Keyboard::Down && board.getDirection(0) != UP)
		{
			board.setDirection(DOWN, 0);
			std::cout << "DOWN" << std::endl;

		}
		else if (event.key.code == sf::Keyboard::Left && board.getDirection(0) != RIGHT)
		{
			board.setDirection(LEFT, 0);
			std::cout << "LEFT" << std::endl;
		}

		if (event.key.code == sf::Keyboard::W && board.getDirection(1) != DOWN)
		{
			board.setDirection(UP, 1);
		}
		else if (event.key.code == sf::Keyboard::D && board.getDirection(1) != LEFT)
		{
			board.setDirection(RIGHT, 1);
		}
		else if (event.key.code == sf::Keyboard::S && board.getDirection(1) != UP)
		{
			board.setDirection(DOWN, 1);
		}
		else if (event.key.code == sf::Keyboard::A && board.getDirection(1) != RIGHT)
		{
			board.setDirection(LEFT, 1);
		}
	}
}

void BoardController::playAgain()
{
	board.playAgain();
	boardView.playAgain();
}

void BoardController::draw(sf::RenderWindow &renderWindow)
{
	boardView.draw(renderWindow);
}