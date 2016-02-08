#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() : Scene(Scenes::GAME)
{

}

void GameScene::update(float dt)
{
	
}

void GameScene::pause()
{

}

void GameScene::draw(sf::RenderWindow &window)
{
	//can obviously be deleted once you start working on the game
	sf::Text text("Game", font, 50);
	text.setColor(sf::Color::Red);
	window.draw(text);
}