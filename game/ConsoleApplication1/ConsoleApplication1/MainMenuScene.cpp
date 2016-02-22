#include "stdafx.h"
#include "MainMenuScene.h"
#include "InputHandler.h"
#include "Polygon.h"
#include <functional>

MainMenuScene::MainMenuScene() : Scene(Scenes::MAINMENU)
{
	m_menu = Menu();
	createUIElements();
}





void MainMenuScene::update(float dt)
{
	m_menu.update(dt);
	
}

void MainMenuScene::updateInput()
{
	m_menu.input();
}


void MainMenuScene::draw(sf::RenderWindow &window)
{
	InputHandler * input = InputHandler::getInstance();
	sf::Event Event;
	while (window.pollEvent(Event))
	{

		// Escape key : exit 
		if (Event.key.code == sf::Keyboard::Space)
			SceneManager::getInstance()->switchTo(Scenes::GAME);
		
	}
	if (input->isPressed(InputHandler::A))
	{
		SceneManager::getInstance()->switchTo(Scenes::GAME);
	}
	
	//can obviously be deleted once you start working on the scene


	sf::Text text("MainMenu \n\n\nPress A to Continue", GameConstants::font, 50);

	text.setColor(sf::Color::Red);
	window.draw(text);
	m_menu.draw(window);
}


void MainMenuScene::createUIElements()
{
	UIElement* element = new UIElement(UI_TYPE::BUTTON, Vector2D(700, 150), Vector2D(50, 50), "play", "play2");
	element->setFunctionality([&](){ SceneManager::getInstance()->switchTo(Scenes::GAME); });						// set functionality for element click
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });										// set how element appears on screen
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });			// set the condition that must be met when button is fully on screen
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });									// set how element should disappear
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	m_menu.addElement(element);

	element = new UIElement(UI_TYPE::BUTTON, Vector2D(700, 300), Vector2D(50, 50), "options", "options2");
	element->setFunctionality([&](){ SceneManager::getInstance()->switchTo(Scenes::OPTIONS); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });								
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });		
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	m_menu.addElement(element);

	element = new UIElement(UI_TYPE::CHECKBOX, Vector2D(700, 450), Vector2D(50, 50), "help", "help2");
	element->setFunctionality([element](){ element->changeText(); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });		
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	m_menu.addElement(element);

	element = new UIElement(UI_TYPE::CHECKBOX, Vector2D(700, 600), Vector2D(50, 50), "exit", "exit2");
	element->setFunctionality([](){ /*NO FUNCTIONALITY*/ });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });		
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	m_menu.addElement(element);

	m_menu.setEnd();
}