#include "stdafx.h"
#include "MainMenuScene.h"

MainMenuScene::MainMenuScene() : Scene(Scenes::MAINMENU)
{

}

void MainMenuScene::update(float dt)
{
	
}

void MainMenuScene::draw(sf::RenderWindow &window)
{
	//can obviously be deleted once you start working on the scene
	sf::Text text("MainMenu", font, 50);
	text.setColor(sf::Color::Red);
	window.draw(text);
}