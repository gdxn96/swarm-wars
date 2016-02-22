#pragma once
#include "Vector2D.h"
#include "PylonManager.h"
#include "Enemy.h"

class EnemyManager
{
public:
	EnemyManager();
	void destroyPylon();
	void spawnEnemy();
	void update(float dt);
	void draw(sf::RenderWindow & window);

	std::vector<Enemy *> getEnemies();


private:
	std::vector<Enemy *> m_enemies;
	PylonManager m_pylonMgr;
	float m_pylonKillInterval;
	float m_spawnInterval;
};


