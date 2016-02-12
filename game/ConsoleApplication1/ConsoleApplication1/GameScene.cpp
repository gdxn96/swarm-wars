#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() 
: 
	Scene(Scenes::GAME),
	m_bulletFactory(new BulletFactory())
{
	//create weapon list for easy retrieval
	WeaponFactory::getInstance()->createWeapons(m_bulletFactory);

	//init must be called to avoid players being created without weapons
	m_unitController.init();
}

void GameScene::update(float dt)
{
	m_enemyManager.update(dt);
	m_unitController.update(dt);
	m_bulletFactory->UpdateBullets(dt);
}

void GameScene::pause()
{

}

void GameScene::draw(sf::RenderWindow &window)
{
	m_enemyManager.draw(window);
	m_unitController.draw(window);
	m_bulletFactory->drawBullets(window);

	//can obviously be deleted once you start working on the game
	sf::Text text("Game", font, 50);
	text.setColor(sf::Color::Red);
	window.draw(text);
}