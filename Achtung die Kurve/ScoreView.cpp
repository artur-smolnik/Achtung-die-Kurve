#include "pch.h"
#include "ScoreView.h"
#include <string>

ScoreView::ScoreView(Board &board, sf::RenderWindow &renderWIndow) : board(board), renderWIndow(renderWIndow)
{
	if (!font.loadFromFile("airstrike.ttf")) {
		abort();
	}
}

void ScoreView::draw(sf::RenderWindow &renderWindow)
{
	if (!(renderWindow.getSize().x == 600 && renderWindow.getSize().y == 500)) setWindowSize(renderWindow);
	//txt.setString("SNAKE'S LENGTH: " + std::to_string(board.getSnakeLength()));
	txt.setFont(font);
	txt.setString("GAME OVER");
	txt.setPosition(50, 50);
	txt.setOutlineThickness(4);
	txt.setOutlineColor(sf::Color::Red);
	txt.setFillColor(sf::Color::Blue);
	txt.setCharacterSize(150);
	renderWindow.draw(txt);


	rect_exit.setSize(sf::Vector2f(445, 150));
	rect_exit.setPosition(285, 400);
	rect_exit.setFillColor(sf::Color::Blue);
	rect_exit.setOutlineThickness(4);
	rect_exit.setOutlineColor(sf::Color::Red);
	txt.setFont(font);
	txt.setString("EXIT");
	txt.setOutlineThickness(2);
	txt.setOutlineColor(sf::Color::Black);
	txt.setFillColor(sf::Color::Red);
	txt.setPosition(305, 365);	
	txt.setCharacterSize(150);
	renderWindow.draw(rect_exit);
	renderWindow.draw(txt);

	rect_play_again.setSize(sf::Vector2f(680, 230));
	rect_play_again.setPosition(155, 600);
	rect_play_again.setFillColor(sf::Color::Blue);
	rect_play_again.setOutlineThickness(4);
	rect_play_again.setOutlineColor(sf::Color::Red);
	txt.setFont(font);
	txt.setString("PLAY");
	txt.setPosition(290, 550);
	txt.setFillColor(sf::Color::Red);
	txt.setCharacterSize(150);
	renderWindow.draw(rect_play_again);
	renderWindow.draw(txt);

	txt.setString("AGAIN");
	txt.setPosition(220, 650);
	renderWindow.draw(txt);
}

void ScoreView::setWindowSize(sf::RenderWindow &renderWindow)
{
	sf::View view;
	view.setSize(renderWindow.getSize().x, renderWindow.getSize().y);
	renderWindow.setView(view);
	renderWindow.create(sf::VideoMode(1000, 1000), "ACHTUNG DIE KURVE");
}