#include "pch.h"
#include "IntroController.h"


IntroController::IntroController(IntroView &introView, Board &board, BoardView &boardView) : introView(introView), board(board), boardView(boardView)
{
}

void IntroController::handleEvent()
{
	auto mouse_pos = sf::Mouse::getPosition(introView.getWindow());  // those two lines can be found on sfml forum 
	auto translated_pos = introView.getWindow().mapPixelToCoords(mouse_pos);

	if (introView.getRect().getGlobalBounds().contains(translated_pos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			finished = true;
		}
	}
	else if (introView.getRectSlowSpeed().getGlobalBounds().contains(translated_pos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			introView.getTxtSlow().setOutlineColor(sf::Color::Cyan);
			introView.getTxtNormal().setOutlineColor(sf::Color::Black);
			introView.getTxtFast().setOutlineColor(sf::Color::Black);
			introView.getTxtSlow().setOutlineThickness(5);
			introView.getTxtNormal().setOutlineThickness(3);
			introView.getTxtFast().setOutlineThickness(3);
			boardView.setSpeed(3);
		}
	}
	else if (introView.getRectNormalSpeed().getGlobalBounds().contains(translated_pos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			introView.getTxtNormal().setOutlineColor(sf::Color::Cyan);
			introView.getTxtSlow().setOutlineColor(sf::Color::Black);
			introView.getTxtFast().setOutlineColor(sf::Color::Black);
			introView.getTxtSlow().setOutlineThickness(3);
			introView.getTxtNormal().setOutlineThickness(5);
			introView.getTxtFast().setOutlineThickness(3);
			boardView.setSpeed(2);
		}
	}
	else if (introView.getRectFastSpeed().getGlobalBounds().contains(translated_pos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			introView.getTxtFast().setOutlineColor(sf::Color::Cyan);
			introView.getTxtSlow().setOutlineColor(sf::Color::Black);
			introView.getTxtNormal().setOutlineColor(sf::Color::Black);
			introView.getTxtSlow().setOutlineThickness(3);
			introView.getTxtNormal().setOutlineThickness(3);
			introView.getTxtFast().setOutlineThickness(5);
			boardView.setSpeed(1);
		}
	}
}

void IntroController::draw(sf::RenderWindow &renderWindow)
{
	introView.draw(renderWindow);
}

