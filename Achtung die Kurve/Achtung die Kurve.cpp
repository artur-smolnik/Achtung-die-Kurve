// Achtung die Kurve.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <Windows.h>
#include <set>
#include <vector>
#include <string>
#include "Board.h"
#include "BoardView.h"
#include "BoardController.h"
#include "GameManager.h"
#include "ScoreController.h"
#include "ScoreView.h"
#include "IntroView.h"
#include "IntroController.h"

int main()
{
	srand(time(NULL));
	sf::RenderWindow renderWindow(sf::VideoMode(1000, 1000), "My window");
	
	Board board(100, 100);
	BoardView boardView(board);
	BoardController boardController(boardView, board);
	/*ScoreView scoreView(board, renderWindow);
	ScoreController scoreController(scoreView);
	IntroView introView(renderWindow);
	IntroController introController(introView, board);
	
	GameManager gameManager(boardController, scoreController, introController);
	*/

	

	


	while (renderWindow.isOpen())
	{

		sf::Event event;
		while (renderWindow.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) renderWindow.close();
			boardController.handleEvent(event);
		}


		renderWindow.clear();
		boardView.draw(renderWindow);
		//gm.draw(w);

		renderWindow.display();
	}

	getchar();
	return 0;
}



