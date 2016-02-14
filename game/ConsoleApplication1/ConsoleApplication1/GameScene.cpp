#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() 
: 
	Scene(Scenes::GAME),
	m_bulletFactory(new BulletFactory()),
	m_numBunkers(10)
{
	//create weapon list for easy retrieval
	WeaponFactory::getInstance()->createWeapons(m_bulletFactory);

	//init must be called to avoid players being created without weapons
	m_unitController.init();
	//m_enemyManager.spawnEnemy();

	for (int i = 0; i < m_numBunkers; i++)
	{
		m_bunkers.push_back(Bunker(2 * GameConstants::PI / m_numBunkers * i));
	}
}

void GameScene::update(float dt)
{
	m_enemyManager.update(dt);
	m_unitController.update(dt);
	m_bulletFactory->UpdateBullets(dt);

	checkCollisions();
}

void GameScene::checkCollisions()
{
	m_collisionMgr.checkEnemyUnitRange(m_enemyManager.getEnemies(), m_unitController.getUnits());
}

void GameScene::pause()
{

}

void GameScene::draw(sf::RenderWindow &window)
{
	m_enemyManager.draw(window);
	m_unitController.draw(window);
	m_bulletFactory->drawBullets(window);

	for (Bunker bunker : m_bunkers)
	{
		bunker.draw(window);
	}

	m_tower.draw(window);

	//can obviously be deleted once you start working on the game
	sf::Text text("Game", font, 50);
	text.setColor(sf::Color::Red);
	window.draw(text);
}