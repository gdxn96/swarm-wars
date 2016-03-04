#include "stdafx.h"
#include "MainMenuScene.h"
#include "InputHandler.h"
#include "Polygon.h"
#include <functional>
#include "AssetLoader.h"
#include "AudioMgr.h"

MainMenuScene::MainMenuScene() : Scene(Scenes::MAINMENU)
{
	m_menu = Menu();
	createUIElements();
	bgTexture = AssetLoader::getInstance()->findTextureByKey("bgMenu");

	bgSprite.setTexture(bgTexture);
	
	bgSprite.setPosition(0,0);
	bgSprite.setSize(Vector2D(GameConstants::WINDOW_SIZE).toSFMLVector());
	
}


void MainMenuScene::updateInput()
{
	m_menu.input();
}


void MainMenuScene::update(float dt)
{
	m_menu.update(dt);
	
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
	window.draw(bgSprite);
	m_menu.draw(window);
}


void MainMenuScene::createUIElements()
{
	UIElement* element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x, GameConstants::WINDOW_CENTRE.y/3.6f), Vector2D(50, 50), ">PLAY<", "play2");
	element->setFunctionality([&](){ SceneManager::getInstance()->switchTo(Scenes::SELECT); });						// set functionality for element click
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });										// set how element appears on screen
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });			// set the condition that must be met when button is fully on screen
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });									// set how element should disappear
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	element->isTextLeft(false);
	m_menu.addElement(element);

	element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x - 170, GameConstants::WINDOW_CENTRE.y / 1.68f), Vector2D(50, 50), ">OPTIONS<", "options2");
	element->setFunctionality([&](){ SceneManager::getInstance()->switchTo(Scenes::OPTIONS); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });								
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });		
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	element->isTextLeft(true);
	m_menu.addElement(element);

	element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x, GameConstants::WINDOW_CENTRE.y / 1.1f), Vector2D(50, 50), ">HELP<", "help2");
	element->setFunctionality([](){SceneManager::getInstance()->switchTo(Scenes::HELP); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });		
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	element->isTextLeft(false);
	m_menu.addElement(element);
	
	element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x - 170, GameConstants::WINDOW_CENTRE.y / 0.8f), Vector2D(50, 50), ">EXIT<", "exit2");
	element->setFunctionality([&](){ std::exit(EXIT_SUCCESS); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });		
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	element->isTextLeft(true);
	m_menu.addElement(element);

	m_menu.setEnd();
}