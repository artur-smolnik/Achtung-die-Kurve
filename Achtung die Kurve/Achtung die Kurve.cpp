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

	
		

	


	/*boardView.draw(renderWindow);
	renderWindow.display();*/
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




/*
void handleKeyboardArrows(sf::RectangleShape &rectangleShape, std::vector<sf::FloatRect> &positions)
{

	srand(time(NULL));
	while (true)
	{	
		Sleep(3);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			std::cout << "Up" << std::endl;
			rectangleShape.move(sf::Vector2f(0, -2));
			for (int i = 0; i < positions.size()- 5; i++)
			{
				if(positions[i].height == NULL) 
				{
					std::cout << "        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
					break;
				}
				if(positions[i].intersects(rectangleShape.getGlobalBounds()))
				{
					std::cout << "        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
					break;
				}
				else positions.push_back(rectangleShape.getGlobalBounds());
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			std::cout << "RIGHT" << std::endl;
			rectangleShape.move(sf::Vector2f(2, 0));
			for (int i = 0; i < positions.size() - 5; i++)
			{
				if (positions[i].height == NULL) break;
				if (positions[i].intersects(rectangleShape.getGlobalBounds()))
				{
					std::cout << "        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
					break;
				}
				else positions.push_back(rectangleShape.getGlobalBounds());
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			std::cout << "DOWN" << std::endl;
			rectangleShape.move(sf::Vector2f(0, 2));
			for (int i = 0; i < positions.size() - 5; i++)
			{
				if (positions[i].height == NULL) break;
				if (positions[i].intersects(rectangleShape.getGlobalBounds()))
				{
					std::cout << "        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
					break;
				}
				else positions.push_back(rectangleShape.getGlobalBounds());
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			std::cout << "LEFT" << std::endl;
			rectangleShape.move(sf::Vector2f(-2, 0));
			for (int i = 0; i < positions.size() - 5; i++)
			{
				if (positions[i].height == NULL)
				{
					for (int i = 0; i < positions.size() - 5; i++) std::cout << positions.size() << std::endl;
					break;
				}
				if (positions[i].intersects(rectangleShape.getGlobalBounds()))
				{
					std::cout << "        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
					break;
				}
				else positions.push_back(rectangleShape.getGlobalBounds());
			}
		}
	//	rectangleShape.move(sf::Vector2f(0, -2));
		std::cout << positions.size() << std::endl;
	}
}

void handleKeyboardWsad()
{
	while (true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			std::cout << "W" << std::endl;
			Sleep(70);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			std::cout << "S" << std::endl;
			Sleep(70);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			std::cout << "A" << std::endl;
			Sleep(70);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			std::cout << "D" << std::endl;
			Sleep(70);
		}
	}
}

*/