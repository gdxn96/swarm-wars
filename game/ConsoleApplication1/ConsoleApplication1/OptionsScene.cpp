#include "stdafx.h"
#include "OptionsScene.h"
#include "Polygon.h"
#include <functional>

OptionsScene::OptionsScene() : Scene(Scenes::OPTIONS)
{
	m_menu = Menu();
	createUIElements();
}

void OptionsScene::updateInput()
{
	m_menu.input();
}



void OptionsScene::update(float dt)
{
	m_menu.update(dt);
	
}

void OptionsScene::draw(sf::RenderWindow &window)
{
	sf::Event Event;
	while (window.pollEvent(Event))
	{

		// Escape key : exit 
		if (Event.key.code == sf::Keyboard::Space)
			SceneManager::getInstance()->switchTo(Scenes::GAME);
	}


	//can obviously be deleted once you start working on the scene
	sf::Text text("Options Menu", GameConstants::font, 50);
	text.setColor(sf::Color::Red);
	window.draw(text);
	m_menu.draw(window);
}


void OptionsScene::createUIElements()
{
	UIElement* element = new UIElement(UI_TYPE::BUTTON, Vector2D(700, 150), Vector2D(50, 50), "play", "play2");
	element->setFunctionality([&](){ SceneManager::getInstance()->switchTo(Scenes::GAME); });					// set functionality for element click
	element->setAlpha(0);
	element->setAppear( [element](float dt){ element->changeAlpha(510 * dt); } );								// set how element appears on screen
	element->setAppearCondition( [element](float dt)->bool{ return element->testAlpha(255, 255 * dt); } );		// set the condition that must be met when button is fully on screen
	element->setDisappear( [element](float dt){ element->changeAlpha(-510 * dt); } );								// set how element should disappear
	element->setDisappearCondition( [element](float dt)->bool{ return element->testAlpha(0, -255 * dt); } );
	m_menu.addElement(element);

	m_menu.setEnd();
}