#pragma once 
#include "Enemy.h"
#include "PylonManager.h"
#include <vector>

class Wave
{
public:
	Wave(float enemy1SpawnInterval, float enemy2SpawnInterval, 
		float bossSpawnInterval, int maxEnemies, int pylonsToKill,
		PylonManager * pylonMgr);
	void update(float dt);
	void draw(sf::RenderWindow& window);
	vector<Enemy*> getEnemies();
	void spawnEnemy1();
	void spawnEnemy2();
	void spawnBoss();
	void kill();
	void init();
	bool getAlive();

private:
	PylonManager * m_pylonMgr;
	std::vector<Enemy *> m_enemies;
	int m_pylonsToKill;
	int m_maxEnemies;
	int m_enemiesSpawned;
	bool m_alive;

	const float ENEMY1_INTERVAL;
	const float ENEMY2_INTERVAL;
	const float BOSS_INTERVAL;

	float m_enemy1SpawnInterval;
	float m_enemy2SpawnInterval;
	float m_bossSpawnInterval;
};