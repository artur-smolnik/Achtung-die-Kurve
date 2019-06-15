#include "pch.h"
#include "IntroView.h"

IntroView::IntroView(sf::RenderWindow &renderWindow) : renderWindow(renderWindow)
{
}

void IntroView::draw()
{
	if (!font.loadFromFile("airstrike.ttf")) {
		abort();
	}

	txt.setFont(font);
	txt.setString("ACHTUNG");
	txt.setPosition(50, 20);
	txt.setOutlineThickness(4);
	txt.setOutlineColor(sf::Color::Red);
	txt.setFillColor(sf::Color::Blue);
	txt.setCharacterSize(100);
	renderWindow.draw(txt);

	txt.setFont(font);
	txt.setString("DIE");
	txt.setPosition(250, 120);
	txt.setOutlineThickness(4);
	txt.setOutlineColor(sf::Color::Red);
	txt.setFillColor(sf::Color::Blue);
	txt.setCharacterSize(100);
	renderWindow.draw(txt);

	txt.setFont(font);
	txt.setString("KURVE");
	txt.setPosition(230, 200);
	txt.setOutlineThickness(4);
	txt.setOutlineColor(sf::Color::Red);
	txt.setFillColor(sf::Color::Blue);
	txt.setCharacterSize(210);
	renderWindow.draw(txt);

	rect.setSize(sf::Vector2f(300, 100));
	rect.setPosition(100, 600);
	rect.setFillColor(sf::Color::Blue);
	rect.setOutlineThickness(4);
	rect.setOutlineColor(sf::Color::Red);
	txt_play.setFont(font);
	txt_play.setFillColor(sf::Color::Red);
	txt_play.setOutlineThickness(3);
	txt_play.setOutlineColor(sf::Color::Black);
	txt_play.setString("Play");
	txt_play.setPosition(115, 580);
	txt_play.setCharacterSize(100);
	renderWindow.draw(rect);
	renderWindow.draw(txt_play);


	identities.setFont(font);
	identities.setString("ARTUR SMOLNIK");
	identities.setPosition(650, 160);
	identities.setFillColor(sf::Color::Red);
	identities.setCharacterSize(35);
	renderWindow.draw(identities);

	
	identities.setString("249092");
	identities.setPosition(750, 200);
	identities.setFillColor(sf::Color::Red);
	identities.setCharacterSize(35);
	renderWindow.draw(identities);


}