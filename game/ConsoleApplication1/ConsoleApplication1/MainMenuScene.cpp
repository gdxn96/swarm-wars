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
	AudioManager::instance()->PlayGameSound("menuSong", false, 1, Vector2D(0, 0), 0);
}


void MainMenuScene::updateInput()
{
	m_menu.input();
}


void MainMenuScene::update(float dt)
{
	m_menu.update(dt);
	
}

void MainMenuScene::setRenderWindow(sf::RenderWindow *_window)
{
	window = _window;
	
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

	
	//can obviously be deleted once you start working on the scene


	//sf::Text text("MainMenu \n\n\nPress A to Continue", GameConstants::font, 50);

	//text.setColor(sf::Color::Red);
	//window.draw(text);
	window.draw(bgSprite);
	m_menu.draw(window);
}


void MainMenuScene::createUIElements()
{
	UIElement* element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x, 150), Vector2D(50, 50), ">PLAY<", "play2");
	element->setFunctionality([&](){ SceneManager::getInstance()->switchTo(Scenes::GAME); });						// set functionality for element click
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });										// set how element appears on screen
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });			// set the condition that must be met when button is fully on screen
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });									// set how element should disappear
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	element->isTextLeft(false);
	m_menu.addElement(element);

	element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x - 170, 320), Vector2D(50, 50), ">OPTIONS<", "options2");
	element->setFunctionality([&](){ SceneManager::getInstance()->switchTo(Scenes::OPTIONS); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });								
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });		
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	element->isTextLeft(true);
	m_menu.addElement(element);

	element = new UIElement(UI_TYPE::BUTTON,  Vector2D(GameConstants::WINDOW_CENTRE.x, 490), Vector2D(50, 50), ">HELP<", "help2");
	element->setFunctionality([](){SceneManager::getInstance()->switchTo(Scenes::HELP); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });		
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	element->isTextLeft(false);
	m_menu.addElement(element);
	
	element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x - 170, 660), Vector2D(50, 50), ">EXIT<", "exit2");
	element->setFunctionality([&](){ window->close(); });
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