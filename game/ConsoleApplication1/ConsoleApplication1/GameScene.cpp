#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() 
: 
	Scene(Scenes::GAME),
	m_bulletFactory(new BulletFactory())
{
	WeaponFactory::getInstance()->createWeapons(m_bulletFactory);
	m_unitController = UnitController();
}

void GameScene::update(float dt)
{
	m_unitController.update(dt);
	m_bulletFactory->UpdateBullets(dt);
}

void GameScene::pause()
{

}

void GameScene::draw(sf::RenderWindow &window)
{
	m_unitController.draw(window);
	m_bulletFactory->drawBullets(window);

	//can obviously be deleted once you start working on the game
	sf::Text text("Game", font, 50);
	text.setColor(sf::Color::Red);
	window.draw(text);
}