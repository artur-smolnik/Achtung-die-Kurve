#include "pch.h"
#include "BoardView.h"
#include <Windows.h>
#include <iostream>



BoardView::BoardView(Board & board, sf::RenderWindow &renderWindow) : board(board)
{
	
	renderTexture.create(1000, 1000);
	//renderTexture.setSmooth(true);
	sprite.setTexture(renderTexture.getTexture());
	
	//renderTexture.clear();
	circleShape.setRadius(4);
	

	renderTexture.display();
	
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
	Sleep(5);
	/*if(board.detectCollision(board.getPlayerArrows().row, board.getPlayerArrows().col)!=-1)
	std::cout << board.detectCollision(board.getPlayerArrows().row, board.getPlayerArrows().col);*/

	board.move();
	if (!(renderWindow.getSize().x == board.getColumns() * size + 2 * x0 + (board.getColumns() - 1)*gap && renderWindow.getSize().y == board.getRows() * size + 2 * y0 + (board.getRows() - 1)*gap)) //do once
	{
		
	}

	circleShape.setFillColor(sf::Color::Red);
	circleShape.setPosition(board.getPlayerArrows().col, board.getPlayerArrows().row);
	renderTexture.draw(circleShape);
	circleShape.setFillColor(sf::Color::Blue);
	circleShape.setPosition(board.getPlayerWsad().col, board.getPlayerWsad().row);
	renderTexture.draw(circleShape);
	renderTexture.display();

	renderWindow.draw(sprite);
	
	

}
//
//struct player
//{
//	int x, y, dir;
//	Color color;
//	player(Color c)
//	{
//		x = rand() % W;
//		y = rand() % H;
//		color = c;
//		dir = rand() % 4;
//	}
//	void tick()
//	{
//		if (dir == 0) y += 4;
//		if (dir == 1) x -= 4;
//		if (dir == 2) x += 4;
//		if (dir == 3) y -= 4;
//
//		if (x >= W) x = 0;  if (x < 0) x = W - 1;
//		if (y >= H) y = 0;  if (y < 0) y = H - 1;
//	}
//
//	Vector3f getColor()
//	{
//		return Vector3f(color.r, color.g, color.b);
//	}
//};
//
//int main()
//{
//	srand(time(0));
//
//	RenderWindow window(VideoMode(W, H), "The Tron Game!");
//	window.setFramerateLimit(60);
//
//	Texture texture;
//	texture.loadFromFile("background.jpg");
//	Sprite sBackground(texture);
//
//	player p1(Color::Red), p2(Color::Green);
//
//	Sprite sprite;
//	RenderTexture t;
//	t.create(W, H);
//	t.setSmooth(true);
//	sprite.setTexture(t.getTexture());
//	t.clear();  t.draw(sBackground);
//
//	bool Game = 1;
//
//	while (window.isOpen())
//	{
//		Event e;
//		while (window.pollEvent(e))
//		{
//			if (e.type == Event::Closed)
//				window.close();
//		}
//
//		if (Keyboard::isKeyPressed(Keyboard::Left)) if (p1.dir != 2) p1.dir = 1;
//		if (Keyboard::isKeyPressed(Keyboard::Right)) if (p1.dir != 1)  p1.dir = 2;
//		if (Keyboard::isKeyPressed(Keyboard::Up)) if (p1.dir != 0) p1.dir = 3;
//		if (Keyboard::isKeyPressed(Keyboard::Down)) if (p1.dir != 3) p1.dir = 0;
//
//		if (Keyboard::isKeyPressed(Keyboard::A)) if (p2.dir != 2) p2.dir = 1;
//		if (Keyboard::isKeyPressed(Keyboard::D)) if (p2.dir != 1)  p2.dir = 2;
//		if (Keyboard::isKeyPressed(Keyboard::W)) if (p2.dir != 0) p2.dir = 3;
//		if (Keyboard::isKeyPressed(Keyboard::S)) if (p2.dir != 3) p2.dir = 0;
//
//		if (!Game)	continue;
//
//		for (int i = 0; i < speed; i++)
//		{
//			p1.tick(); p2.tick();
//			if (field[p1.x][p1.y] == 1) Game = 0;
//			//if (field[p2.x][p2.y] == 1) Game = 0;
//			field[p1.x][p1.y] = 1;
//			//field[p2.x][p2.y] = 1;
//
//			CircleShape c(10);
//			c.setPosition(p1.x, p1.y); c.setFillColor(p1.color);	t.draw(c);
//			//c.setPosition(p2.x, p2.y); c.setFillColor(p2.color);	t.draw(c);
//			t.display();
//		}
//
//		////// draw  ///////
//		window.clear();
//		window.draw(sprite);
//		window.display();
//	}
//
//	return 0;
//}
