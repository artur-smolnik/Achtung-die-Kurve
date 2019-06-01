#include "pch.h"
#include "BoardView.h"



BoardView::BoardView(Board & board) : board(board)
{
	
	
}

void BoardView::setRectanglesVector()
{
	for (int i = 0; i < board.getRows(); i++)
	{
		for (int j = 0; j < board.getColumns(); j++)
		{
			sf::RectangleShape rectangle(sf::Vector2f(size, size));
			rectangle.setFillColor(sf::Color::Green);
			rectangle.setPosition(x0 + j * size + j * gap, y0 + i * size + i * gap);
			rectangles.push_back(rectangle);
		}
	}

	
}

void BoardView::setWindowSize(sf::RenderWindow &renderWindow)
{
	int x, y;
	x = board.getColumns() * size + 2 * x0 + (board.getColumns() - 1)*gap;
	y = board.getRows() * size + 2 * y0 + (board.getRows() - 1)*gap;
	sf::View view;
	view.setSize(renderWindow.getSize().x, renderWindow.getSize().y);
	renderWindow.setView(view);
	renderWindow.create(sf::VideoMode(x, y), "Kurve Fever");
}


void BoardView::draw(sf::RenderWindow &renderWindow)
{
	if (!(renderWindow.getSize().x == board.getColumns() * size + 2 * x0 + (board.getColumns() - 1)*gap && renderWindow.getSize().y == board.getRows() * size + 2 * y0 + (board.getRows() - 1)*gap)) //do once
	{
		setWindowSize(renderWindow);
		for (int i = 0; i < board.getRows(); i++)
		{
			for (int j = 0; j < board.getColumns(); j++)
			{
				sf::RectangleShape rectangle(sf::Vector2f(size, size));
				rectangle.setFillColor(sf::Color::Green);
				rectangle.setPosition(x0 + j * size + j * gap, y0 + i * size + i * gap);
				rectangles.push_back(rectangle);
			}
		}

		for (int i = 0; i < rectangles.size(); i++)
		{
			renderWindow.draw(rectangles[i]);
		}
		arrowsRectangle.setSize((sf::Vector2f(size, size)));
		arrowsRectangle.setFillColor(sf::Color::Red);
		arrowsRectangle.setPosition(x0 + board.getPlayerArrows().headCol * size + board.getPlayerArrows().headCol * gap, y0 + board.getPlayerArrows().headRow * size + board.getPlayerArrows().headRow * gap);
		renderWindow.draw(arrowsRectangle);

		wsadRectangle.setSize((sf::Vector2f(size, size)));
		wsadRectangle.setFillColor(sf::Color::Blue);
		wsadRectangle.setPosition(x0 + board.getPlayerWsad().headCol * size + board.getPlayerWsad().headCol * gap, y0 + board.getPlayerWsad().headRow * size + board.getPlayerWsad().headRow * gap);
		renderWindow.draw(wsadRectangle);

	}
	
	board.move();
	//collision detection
	//arrowsRectangle.move(sf::Vector2f(size, size))
	//renderWindow.draw(arrowsRectangle);
	//wsadRectangle.setPosition(x0 + board.getPlayerWsad().headCol * size + board.getPlayerWsad().headCol * gap, y0 + board.getPlayerWsad().headRow * size + board.getPlayerWsad().headRow * gap);
	//renderWindow.draw(wsadRectangle);
	
	
	
}