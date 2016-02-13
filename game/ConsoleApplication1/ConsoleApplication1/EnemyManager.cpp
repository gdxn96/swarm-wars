#include "stdafx.h"
#include "EnemyManager.h"
#include "Enemy.h"

EnemyManager::EnemyManager()
:
	m_spawnInterval(GameConstants::ENEMY_SPAWN_INTERVAL)
{
}

void EnemyManager::spawnEnemy()
{
	Vector2D spawnPosition = m_spawnPointController.getSpawnPoint();
	Vector2D direction = (GameConstants::WINDOW_CENTRE - spawnPosition).Normalize();
	m_enemies.push_back(new Enemy(spawnPosition, direction));
}

std::vector<Enemy *> EnemyManager::getEnemies()
{
	return m_enemies;
}

void EnemyManager::update(float dt)
{
	m_spawnInterval -= dt;
	if (m_spawnInterval <= 0)
	{
		m_spawnInterval = GameConstants::ENEMY_SPAWN_INTERVAL;
		spawnEnemy();
	}
	for (Enemy * enemy : m_enemies)
	{
		enemy->update(dt);
	}
}

void EnemyManager::draw(sf::RenderWindow & window)
{
	for (Enemy * enemy : m_enemies)
	{
		enemy->draw(window);
	}
}