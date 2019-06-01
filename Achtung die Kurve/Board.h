#pragma once
#include <vector>

enum Directions
{
	UP, RIGHT, DOWN, LEFT
};

struct Player
{
	Directions direction;
	int id;
	int headRow;
	int headCol;
};
class Board
{
	int rows, columns;
	Player playerWsad;
	Player playerArrows;
	int board[300][300]; //keeps id info
	bool finished;
	void setStartingPosition();
	bool detectCollision();
	void setPlayers();

	void setBoard();

public:
	Board(int rows, int columns);
	void setDirection(Directions dir, int id);
	Directions getDirection(int id);
	bool isFinished() { return finished; }
	void playAgain();
	int getRows() { return rows; }
	int getColumns() { return columns; }
	void move();
	int getFieldId(int row, int col) { return board[row][col]; }
	Player getPlayerWsad() { return playerWsad; }
	Player getPlayerArrows() { return playerArrows;  }
		
		
};

