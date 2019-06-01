#include "pch.h"
#include "Board.h"
#include "SFML/Graphics.hpp"

Board::Board(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	this->finished = false;
	setBoard();
	
	setPlayers();
}


void Board::setPlayers()
{
	playerArrows.direction = Directions(rand() % 2);
	playerArrows.id = 0;
	playerArrows.headRow = rand() % rows;
	playerArrows.headCol = rand() % columns;

	playerWsad.direction = Directions(rand() % 2);
	playerWsad.id = 1;
	playerWsad.headRow = rand() % rows;
	playerWsad.headCol = rand() % columns;
}

void Board::move()
{
	if (playerArrows.direction == UP)
	{
		if (playerArrows.headRow - 1 < 0) playerArrows.headRow = rows - 1;
		else playerArrows.headRow -= 1;
	}
	else if (playerArrows.direction == RIGHT)
	{
		if (playerArrows.headCol + 1 >= columns) playerArrows.headCol = 0;
		else playerArrows.headCol += 1;
	}
	else if (playerArrows.direction == DOWN)
	{
		if (playerArrows.headRow + 1 >= rows) playerArrows.headRow = 0;
		else playerArrows.headRow += 1;
	}
	else  if (playerArrows.direction == LEFT)
	{
		if (playerArrows.headCol - 1 < 0) playerArrows.headCol = columns - 1;
		else playerArrows.headCol -= 1;
	}

	if (playerWsad.direction == UP)
	{
		if (playerWsad.headRow - 1 < 0) playerWsad.headRow = rows - 1;
		else playerWsad.headRow -= 1;
	}
	else if (playerWsad.direction == RIGHT)
	{
		if (playerWsad.headCol + 1 >= columns) playerWsad.headCol = 0;
		else playerWsad.headCol += 1;
	}
	else if (playerWsad.direction == DOWN)
	{
		if (playerWsad.headRow + 1 >= rows) playerWsad.headRow = 0;
		else playerWsad.headRow += 1;
	}
	else  if (playerWsad.direction == LEFT)
	{
		if (playerWsad.headCol - 1 < 0) playerWsad.headCol = columns - 1;
		else playerWsad.headCol -= 1;
	}
}

void Board::setBoard()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			board[i][j] = -1;
		}
	}
}

void Board::setDirection(Directions dir, int id)
{
	if (id == 0) playerArrows.direction = dir;
	if (id == 1) playerWsad.direction = dir;
}

Directions Board::getDirection(int id)
{
	if (id == 0) return playerArrows.direction;
	if (id == 1) return playerWsad.direction;
}


