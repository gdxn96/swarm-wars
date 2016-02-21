#include "stdafx.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include <iostream>

EnemyManager::EnemyManager()
:
	m_spawnInterval(GameConstants::ENEMY_SPAWN_INTERVAL)
{
}

void EnemyManager::spawnEnemy()
{
	Vector2D spawnPosition = m_pylonMgr.getSpawnPoint();
	Vector2D direction = (GameConstants::WINDOW_CENTRE - spawnPosition).Normalize();
	m_enemies.push_back(new Enemy(	spawnPosition, direction, 
									GameConstants::ENEMY1_HEALTH, 
									GameConstants::ENEMY1_DAMAGE_PER_SECOND, 
									GameConstants::ENEMY1_SPEED, 
									GameConstants::ENEMY1_RADIUS,
									3));
}

std::vector<Enemy *> EnemyManager::getEnemies()
{
	return m_enemies;
}

void EnemyManager::update(float dt)
{
	m_spawnInterval -= dt;
	m_pylonKillInterval -= dt;

	if (m_spawnInterval <= 0)
	{
		m_spawnInterval = GameConstants::ENEMY_SPAWN_INTERVAL;

		if (m_enemies.size() < 60 && m_pylonMgr.getOpenSpawnPoints().size() > 0)
		{
			spawnEnemy();
		}
	}

	for (int i = 0; i < m_enemies.size(); i++)
	{
		if (m_enemies[i]->getAlive())
		{
			m_enemies[i]->update(dt);
		}
		else
		{
			delete m_enemies[i];
			m_enemies.erase(m_enemies.begin() + i);
		}
	}
	m_pylonMgr.update(dt);
}

void EnemyManager::draw(sf::RenderWindow & window)
{
	for (Enemy * enemy : m_enemies)
	{
		enemy->draw(window);
	}

	m_pylonMgr.draw(window);
}

