#include "stdafx.h"
#include "MainMenuScene.h"
#include "Polygon.h"

MainMenuScene::MainMenuScene() : Scene(Scenes::MAINMENU)
{

}

void MainMenuScene::update(float dt)
{
	
}

void MainMenuScene::draw(sf::RenderWindow &window)
{
	sf::Event Event;
	while (window.pollEvent(Event))
	{

		// Escape key : exit 
		if (Event.key.code == sf::Keyboard::Space)
			SceneManager::getInstance()->switchTo(Scenes::GAME);
	}

	
	//can obviously be deleted once you start working on the scene
	sf::Text text("MainMenu \n\n\nPress Space to Continue", font, 50);
	text.setColor(sf::Color::Red);
	window.draw(text);
}