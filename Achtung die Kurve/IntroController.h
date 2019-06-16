#pragma once
#include <SFML/Graphics.hpp>
#include "IntroView.h"
#include "Board.h"
#include "BoardView.h"

class IntroController
{
	bool finished = false;
	IntroView & introView;
	Board &board;
	BoardView &boardView;
public:
	IntroController(IntroView &introView, Board &board, BoardView &boardView);
	void handleEvent();
	void draw(sf::RenderWindow &renderWindow);
	bool isFinished() const { return finished; }
	void setFinishedToFalse() { finished = false; }
};
