#include "stdafx.h"
#include "Wave.h"

Wave::Wave(float enemy1SpawnInterval, float enemy2SpawnInterval,
	float bossSpawnInterval, int maxEnemies, int pylonsToKill,
	PylonManager* pylonMgr):
	ENEMY1_INTERVAL(enemy1SpawnInterval), 
	ENEMY2_INTERVAL(enemy2SpawnInterval), 
	BOSS_INTERVAL(bossSpawnInterval),
	m_enemy1SpawnInterval(enemy1SpawnInterval),
	m_enemy2SpawnInterval(enemy2SpawnInterval),
	m_bossSpawnInterval(bossSpawnInterval),
	m_pylonsToKill(pylonsToKill),
	m_maxEnemies(maxEnemies),
	m_enemiesSpawned(0),
	m_pylonMgr(pylonMgr),
	m_alive(true)
{
	//do min max
}

void Wave::init()
{
	for (int i = 0; i < m_pylonsToKill; i++)
	{
		m_pylonMgr->killPylon();
	}
}

void Wave::setGraph(Graph<string, int> * _graph)
{
	graph = _graph;
}

void Wave::update(float dt)
{
	//update spawning timers
	m_enemy1SpawnInterval -= dt;
	m_enemy2SpawnInterval -= dt;
	m_bossSpawnInterval -= dt;

	if (m_enemy1SpawnInterval < 0)
	{
		m_enemy1SpawnInterval = ENEMY1_INTERVAL;
		spawnEnemy1();
		
	}
	if (m_enemy2SpawnInterval < 0)
	{
		m_enemy2SpawnInterval = ENEMY2_INTERVAL;
		spawnEnemy2();
	}
	if (m_bossSpawnInterval < 0)
	{
		m_bossSpawnInterval = BOSS_INTERVAL;
		spawnBoss();
	}

	//update enemies
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

	if (m_enemiesSpawned == m_maxEnemies && m_enemies.size() == 0)
	{
		kill();
	}
}

void Wave::draw(sf::RenderWindow& window)
{
	for (Enemy * enemy : m_enemies)
	{
		enemy->draw(window);
	}
}

vector<Enemy*> Wave::getEnemies()
{
	return m_enemies;
}
void Wave::visit(Node * pNode) {
	pNode->setColour(sf::Color::Magenta);
}
void Wave::spawnEnemy1()
{
	std::vector<Node *> nodes;
	if (m_enemiesSpawned < m_maxEnemies)
	{
		m_enemiesSpawned++;

		Vector2D spawnPosition = m_pylonMgr->getSpawnPoint();
		int index;
		float minDistance = 1000000000000;
		
		for (int i = 0; i < 20; i++)
		{
			if (minDistance > Vector2D::Distance(graph->nodeArray()[i]->getPosition(), spawnPosition))
			{
				minDistance = Vector2D::Distance(graph->nodeArray()[i]->getPosition(), spawnPosition);
				index = i;
			}
		}
		graph->aStar(graph->nodeArray()[index], graph->nodeArray()[20], NULL, nodes);
		printPath(nodes);
		m_enemies.push_back(new Enemy(spawnPosition, nodes,
			ENEMY_STATS::ENEMY1_HEALTH,
			ENEMY_STATS::ENEMY1_DAMAGE_PER_SECOND,
			ENEMY_STATS::ENEMY1_SPEED,
			ENEMY_STATS::ENEMY1_RADIUS,
			m_pylonMgr->getOpenSpawnPoints().size(),
			ENEMY_STATS::ENEMY1_ANIMATION_KEY));
	}
	graph->clearMarks();
	nodes.clear();
}

void Wave::spawnEnemy2()
{
	std::vector<Node *> nodes;
	if (m_enemiesSpawned < m_maxEnemies)
	{
		m_enemiesSpawned++;
		int index;
		float minDistance = 1000000000000;
		Vector2D spawnPosition = m_pylonMgr->getSpawnPoint();
		for (int i = 0; i < 20; i++)
		{
			if (minDistance > Vector2D::Distance(graph->nodeArray()[i]->getPosition(), spawnPosition))
			{
				minDistance = Vector2D::Distance(graph->nodeArray()[i]->getPosition(), spawnPosition);
				index = i;
			}
		}
		graph->aStar(graph->nodeArray()[index], graph->nodeArray()[20], NULL, nodes);
		printPath(nodes);
		
		Vector2D direction = (GameConstants::WINDOW_CENTRE - spawnPosition).Normalize();
		m_enemies.push_back(new Enemy(spawnPosition, nodes,
			ENEMY_STATS::ENEMY2_HEALTH,
			ENEMY_STATS::ENEMY2_DAMAGE_PER_SECOND,
			ENEMY_STATS::ENEMY2_SPEED,
			ENEMY_STATS::ENEMY2_RADIUS,
			m_pylonMgr->getOpenSpawnPoints().size(),
			ENEMY_STATS::ENEMY2_ANIMATION_KEY));
	}
	graph->clearMarks();
	nodes.clear();
}

void Wave::spawnBoss()
{
	std::vector<Node *> nodes;
	if (m_enemiesSpawned < m_maxEnemies)
	{
		m_enemiesSpawned++;
		int index;
		float minDistance = 1000000000000;
		Vector2D spawnPosition = m_pylonMgr->getSpawnPoint();
		for (int i = 0; i < 20; i++)
		{
			if (minDistance > Vector2D::Distance(graph->nodeArray()[i]->getPosition(), spawnPosition))
			{
				minDistance = Vector2D::Distance(graph->nodeArray()[i]->getPosition(), spawnPosition);
				index = i;
			}
		}
		graph->aStar(graph->nodeArray()[index], graph->nodeArray()[20], NULL, nodes);
		printPath(nodes);
		
		Vector2D direction = (GameConstants::WINDOW_CENTRE - spawnPosition).Normalize();
		m_enemies.push_back(new Enemy(spawnPosition, nodes,
			ENEMY_STATS::BOSS_HEALTH,
			ENEMY_STATS::BOSS_DAMAGE_PER_SECOND,
			ENEMY_STATS::BOSS_SPEED,
			ENEMY_STATS::BOSS_RADIUS,
			m_pylonMgr->getOpenSpawnPoints().size(),
			ENEMY_STATS::BOSS_ANIMATION_KEY));
	}
	graph->clearMarks();
	nodes.clear();
}

void Wave::kill()
{
	m_alive = false;
}

bool Wave::getAlive()
{
	return m_alive;
}
