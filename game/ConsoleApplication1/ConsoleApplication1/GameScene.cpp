#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() 
: 
	Scene(Scenes::GAME),
	m_bulletFactory(new BulletFactory()),
	m_numBunkers(10),
	m_paused(false),
	m_collisionMgr(&m_unitController)
{
	//create weapon list for easy retrieval
	WeaponFactory::getInstance()->createWeapons(m_bulletFactory);

	//init must be called to avoid players being created without weapons
	m_unitController.init();

	for (int i = 0; i < m_numBunkers; i++)
	{
		m_bunkers.push_back(new Bunker(2 * GameConstants::PI / m_numBunkers * i));
	}
}

void GameScene::update(float dt)
{
	if (!m_paused)
	{
		m_enemyManager.update(dt);
		m_unitController.update(dt);
		m_bulletFactory->UpdateBullets(dt);

		checkCollisions(dt);
		checkBunkers();

		m_paused = !m_tower.getAlive();
	}

	
}


void GameScene::checkBunkers()
{
	for (int i = 0; i < m_bunkers.size(); i++)
	{
		if (!m_bunkers.at(i)->isAlive())
		{
			delete m_bunkers[i];
			m_bunkers.erase(m_bunkers.begin() + i);
		}

	}
}

void GameScene::checkCollisions(float dt)
{
	m_collisionMgr.checkBulletsTower(m_bulletFactory->getBullets(), m_tower);
	m_collisionMgr.checkEnemyUnitRange(m_enemyManager.getEnemies(), m_unitController.getUnits());
	m_collisionMgr.checkEnemyTower(m_enemyManager.getEnemies(), m_tower);
	m_collisionMgr.checkEnemyBullets(m_enemyManager.getEnemies(), m_bulletFactory->getBullets());
	m_collisionMgr.checkEnemyBunker(m_enemyManager.getEnemies(), m_bunkers, dt);
}

void GameScene::pause()
{

}

void GameScene::draw(sf::RenderWindow &window)
{
	for (Bunker* bunker : m_bunkers)
	{
		bunker->draw(window);
	}

	m_tower.draw(window);

	m_enemyManager.draw(window);
	m_unitController.draw(window);
	m_bulletFactory->drawBullets(window);

	

	//can obviously be deleted once you start working on the game
	if (!m_paused)
	{
		sf::Text text("Game", GameConstants::font, 50);
		text.setColor(sf::Color::Red);
		window.draw(text);
	}
	else
	{
		sf::Text text("GameOver", GameConstants::font, 50);
		text.setColor(sf::Color::Red);
		window.draw(text);
	}
	
}