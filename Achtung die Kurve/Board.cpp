#include "pch.h"
#include "Board.h"
#include "SFML/Graphics.hpp"

Board::Board(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	finished = false;

	board = new int*[1000];
	for (int i = 0; i < 1000; ++i) board[i] = new int[1000];
	setBoard();
	setPlayers();
}

Board::~Board()
{
	for (int i = 0; i < 1000; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}


void Board::setPlayers()
{
	playerArrows.direction = Directions(rand() % 4);
	playerArrows.id = 0;
	playerArrows.row = rand() % 1000;
	playerArrows.col = rand() % 1000;

	playerWsad.direction = Directions(rand() % 4);
	playerWsad.id = 1;
	playerWsad.row = rand() % 1000;
	playerWsad.col = rand() % 1000;
}

void Board::move()
{

	if (playerArrows.direction == UP)
	{
		if (playerArrows.row - 1 < 0 || detectCollision(playerArrows.row - 1, playerArrows.col)) finished = true;
		else
		{
			playerArrows.row -= 1;
			board[playerArrows.row][playerArrows.col] = 0;
		}
	}
	else if (playerArrows.direction == RIGHT)
	{
		if (playerArrows.col + 1 >= 1000 || detectCollision(playerArrows.row, playerArrows.col + 1)) finished = true;
		else
		{
			playerArrows.col += 1;
			board[playerArrows.row][playerArrows.col] = 0;
		}
	}
	else if (playerArrows.direction == DOWN)
	{
		if (playerArrows.row + 1 >= 1000 || detectCollision(playerArrows.row + 1, playerArrows.col)) finished = true;
		else
		{
			playerArrows.row += 1;
			board[playerArrows.row][playerArrows.col] = 0;
		}
	}
	else  if (playerArrows.direction == LEFT)
	{
		if (playerArrows.col - 1 < 0 || detectCollision(playerArrows.row, playerArrows.col - 1)) finished = true;
		else
		{
			playerArrows.col -= 1;
			board[playerArrows.row][playerArrows.col] = 0;
		}
	}



	if (playerWsad.direction == UP)
	{
		if (playerWsad.row - 1 < 0 || detectCollision(playerWsad.row - 1, playerWsad.col)) finished = true;
		else
		{
			playerWsad.row -= 1;
			board[playerWsad.row][playerWsad.col] = 1;
		}
	}
	else if (playerWsad.direction == RIGHT)
	{
		if (playerWsad.col + 1 >= 1000 || detectCollision(playerWsad.row, playerWsad.col + 1)) finished = true;
		else
		{
			playerWsad.col += 1;
			board[playerWsad.row][playerWsad.col] = 1;
		}
	}
	else if (playerWsad.direction == DOWN)
	{
		if (playerWsad.row + 1 >= 1000 || detectCollision(playerWsad.row + 1, playerWsad.col)) finished = true;
		else
		{
			playerWsad.row += 1;
			board[playerWsad.row][playerWsad.col] = 1;
		}
	}
	else  if (playerWsad.direction == LEFT)
	{
		if (playerWsad.col - 1 < 0 || detectCollision(playerWsad.row, playerWsad.col - 1)) finished = true;
		else
		{
			playerWsad.col -= 1;
			board[playerWsad.row][playerWsad.col] = 1;
		}
	}
}

void Board::claimField(int row, int col, int playerId)
{
	board[row][col] = playerId;
}

bool Board::detectCollision(int row, int col)
{
	if (board[row][col] != -1) return true;
	else return false;

}

void Board::setBoard()
{
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			board[i][j] = -1;
		}
	}
}

void Board::setDirection(Directions dir, int playerId)
{
	if (playerId == 0) playerArrows.direction = dir;
	if (playerId == 1) playerWsad.direction = dir;
}

Directions Board::getDirection(int playerId)
{
	if (playerId == 0) return playerArrows.direction;
	if (playerId == 1) return playerWsad.direction;
}

void Board::playAgain()
{
	setBoard();

	playerArrows.direction = Directions(rand() % 4);
	playerArrows.id = 0;
	playerArrows.row = rand() % 1000;
	playerArrows.col = rand() % 1000;

	playerWsad.direction = Directions(rand() % 4);
	playerWsad.id = 1;
	playerWsad.row = rand() % 1000;
	playerWsad.col = rand() % 1000;

	finished = false;

}


