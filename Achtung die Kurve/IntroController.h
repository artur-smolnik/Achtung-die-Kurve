#pragma once
#include <SFML/Graphics.hpp>
#include "IntroView.h"
#include "Board.h"

class IntroController
{
	bool finished = false;
	IntroView & introView;
	Board &board;
public:
	IntroController(IntroView &introView, Board &board);
	void handleEvent();
	void draw(sf::RenderWindow &renderWindow);
	bool isFinished() const { return finished; }
	void setFinishedToFalse() { finished = false; }
};
