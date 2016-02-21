#include "stdafx.h"
#include "GameScene.h"
#include "AssetLoader.h"

GameScene::GameScene()
	:
	Scene(Scenes::GAME),
	m_bulletFactory(new BulletFactory()),
	m_numBunkers(15),
	m_paused(false),
	m_anim("staticAnimation",Vector2D (-100,-100)),
	m_collisionMgr(&m_unitController)

{
	m_anim.setFramesPerSecond(10);
	m_anim.SetLooping(true);
	m_anim.setRadius(GameConstants::WINDOW_SIZE.x/2);
	m_anim.setPosition(GameConstants::WINDOW_CENTRE);
	//create weapon list for easy retrieval
	WeaponFactory::getInstance()->createWeapons(m_bulletFactory);

	//init must be called to avoid players being created without weapons
	m_unitController.init();
	m_UnitSelector = UnitSelector(m_unitController.getUnits());
	for (int i = 0; i < m_numBunkers; i++)
	{
		m_bunkers.push_back(new Bunker(2 * GameConstants::PI / m_numBunkers * i));
	}
	
	floorSprite.setTexture(* AssetLoader::getInstance()->findTextureByKey("floor"));
	floorSprite.setPosition(Vector2f(0, 0));
	floorSprite.setScale(sf::Vector2f(0.5f,0.5f));

	gameView.setCenter(Vector2D(GameConstants::WINDOW_CENTRE).toSFMLVector());
	gameView.setSize(sf::Vector2f(GameConstants::WINDOW_SIZE.x, GameConstants::WINDOW_SIZE.y));
	

	// mini-map (upper-right corner)
	miniMapView.setViewport(sf::FloatRect(0.75f, 0.0f, 0.25f, 0.25f));
	miniMapView.zoom(0.25f);
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
	m_UnitSelector.update(dt);
	m_anim.update();
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
	window.setView(gameView);
	window.draw(floorSprite);
	for (Bunker* bunker : m_bunkers)
	{
		bunker->draw(window);
	}

	m_tower.draw(window);

	m_enemyManager.draw(window);
	m_unitController.draw(window);
	m_bulletFactory->drawBullets(window);
	m_UnitSelector.draw(window);
	//miniMapView.setCenter();
	m_unitController.drawUI(window);
	for (int i = 0; i < m_unitController.getUnits().size(); i++)
	{

		if (m_unitController.getUnits()[i]->getSelected())
		{
			miniMapView.setCenter(m_unitController.getUnits()[i]->getPosition().toSFMLVector());
		}

	}
	LightManager::getInstance()->draw(window);
	// mini map draw ----------------------------------
	window.setView(miniMapView);
	window.draw(floorSprite);
	for (Bunker* bunker : m_bunkers)
	{
		bunker->draw(window);

	}

	m_tower.draw(window);

	m_enemyManager.draw(window);
	m_unitController.draw(window);
	m_bulletFactory->drawBullets(window);
	//m_UnitSelector.draw(window);
	m_anim.draw(window);
	LightManager::getInstance()->draw(window);
	sf::RectangleShape cover;
}