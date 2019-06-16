#include "pch.h"
#include "IntroView.h"

IntroView::IntroView(sf::RenderWindow &renderWindow) : renderWindow(renderWindow)
{
	if (!font.loadFromFile("airstrike.ttf")) {
		abort();
	}
	renderTexture.create(1000, 1000);
	sprite.setTexture(renderTexture.getTexture());

	txt.setFont(font);
	txt.setString("ACHTUNG");
	txt.setPosition(50, 20);
	txt.setOutlineThickness(4);
	txt.setOutlineColor(sf::Color::Red);
	txt.setFillColor(sf::Color::Blue);
	txt.setCharacterSize(100);
	renderTexture.draw(txt);

	txt.setFont(font);
	txt.setString("DIE");
	txt.setPosition(250, 120);
	txt.setOutlineThickness(4);
	txt.setOutlineColor(sf::Color::Red);
	txt.setFillColor(sf::Color::Blue);
	txt.setCharacterSize(100);
	renderTexture.draw(txt);

	txt.setFont(font);
	txt.setString("KURVE");
	txt.setPosition(230, 200);
	txt.setOutlineThickness(4);
	txt.setOutlineColor(sf::Color::Red);
	txt.setFillColor(sf::Color::Blue);
	txt.setCharacterSize(210);
	renderTexture.draw(txt);

	txt.setFont(font);
	txt.setFillColor(sf::Color::Blue);
	txt.setOutlineThickness(2);
	txt.setOutlineColor(sf::Color::Cyan);
	txt.setString("CHOOSE SPEED");
	txt.setPosition(550, 430);
	txt.setCharacterSize(45);
	renderTexture.draw(txt);

	rectPlay.setSize(sf::Vector2f(300, 100));
	rectPlay.setPosition(100, 650);
	rectPlay.setFillColor(sf::Color::Blue);
	rectPlay.setOutlineThickness(4);
	rectPlay.setOutlineColor(sf::Color::Red);
	txt.setFont(font);
	txt.setFillColor(sf::Color::Red);
	txt.setOutlineThickness(3);
	txt.setOutlineColor(sf::Color::Black);
	txt.setString("Play");
	txt.setPosition(115, 630);
	txt.setCharacterSize(100);
	renderTexture.draw(rectPlay);
	renderTexture.draw(txt);

	rectSlowSpeed.setSize(sf::Vector2f(450, 100));
	rectSlowSpeed.setPosition(500, 500);
	rectSlowSpeed.setFillColor(sf::Color::Blue);
	rectSlowSpeed.setOutlineThickness(4);
	rectSlowSpeed.setOutlineColor(sf::Color::Red);
	txtSlowSpeed.setFont(font);
	txtSlowSpeed.setFillColor(sf::Color::Red);
	txtSlowSpeed.setOutlineThickness(3);
	txtSlowSpeed.setOutlineColor(sf::Color::Black);
	txtSlowSpeed.setString("SLOW");
	txtSlowSpeed.setPosition(580, 480);
	txtSlowSpeed.setCharacterSize(100);
	renderTexture.draw(rectSlowSpeed);
	renderTexture.draw(txtSlowSpeed);

	rectNormalSpeed.setSize(sf::Vector2f(450, 100));
	rectNormalSpeed.setPosition(500, 650);
	rectNormalSpeed.setFillColor(sf::Color::Blue);
	rectNormalSpeed.setOutlineThickness(4);
	rectNormalSpeed.setOutlineColor(sf::Color::Red);
	txtNormalSpeed.setFont(font);
	txtNormalSpeed.setFillColor(sf::Color::Red);
	txtNormalSpeed.setOutlineThickness(3);
	txtNormalSpeed.setOutlineColor(sf::Color::Black);
	txtNormalSpeed.setString("NORMAL");
	txtNormalSpeed.setPosition(510, 630);
	txtNormalSpeed.setCharacterSize(100);
	renderTexture.draw(rectNormalSpeed);
	renderTexture.draw(txtNormalSpeed);

	rectFastSpeed.setSize(sf::Vector2f(450, 100));
	rectFastSpeed.setPosition(500, 800);
	rectFastSpeed.setFillColor(sf::Color::Blue);
	rectFastSpeed.setOutlineThickness(4);
	rectFastSpeed.setOutlineColor(sf::Color::Red);
	txtFastSpeed.setFont(font);
	txtFastSpeed.setFillColor(sf::Color::Red);
	txtFastSpeed.setOutlineThickness(3);
	txtFastSpeed.setOutlineColor(sf::Color::Black);
	txtFastSpeed.setString("FAST");
	txtFastSpeed.setPosition(600, 780);
	txtFastSpeed.setCharacterSize(100);
	renderTexture.draw(rectFastSpeed);
	renderTexture.draw(txtFastSpeed);

	txt.setFont(font);
	txt.setString("ARROWS PLAYER");
	txt.setPosition(100, 500);
	txt.setFillColor(sf::Color::Red);
	txt.setCharacterSize(35);
	renderTexture.draw(txt);

	txt.setFont(font);
	txt.setString("WSAD PLAYER");
	txt.setPosition(100, 860);
	txt.setFillColor(sf::Color::Blue);
	txt.setCharacterSize(35);
	renderTexture.draw(txt);

	txt.setFont(font);
	txt.setString("ARTUR SMOLNIK");
	txt.setPosition(650, 160);
	txt.setFillColor(sf::Color::Red);
	txt.setCharacterSize(35);
	renderTexture.draw(txt);

	txt.setFont(font);
	txt.setString("249092");
	txt.setPosition(750, 200);
	txt.setFillColor(sf::Color::Red);
	txt.setCharacterSize(35);
	renderTexture.draw(txt);

	circleShape.setFillColor(sf::Color::Red);
	circleShape.setRadius(4);
	
	for(int i = 0; i < 200; i+=2)	
	{
		circleShape.setFillColor(sf::Color::Red);
		circleShape.setPosition(110 + i, 550);
		renderTexture.draw(circleShape);
		circleShape.setPosition(110 + i, 850);
		circleShape.setFillColor(sf::Color::Blue);
		renderTexture.draw(circleShape);
	}

	renderTexture.display();
}

void IntroView::draw(sf::RenderWindow &renderWindow)
{
	renderTexture.draw(rectSlowSpeed);
	renderTexture.draw(rectNormalSpeed);
	renderTexture.draw(rectFastSpeed);
	renderTexture.draw(txtSlowSpeed);
	renderTexture.draw(txtNormalSpeed);
	renderTexture.draw(txtFastSpeed);
	renderTexture.display();
	renderWindow.draw(sprite);

}