#pragma once
#include "Vector2D.h"
#include "SpawnPointController.h"
#include "Enemy.h"

class EnemyManager
{
public:
	EnemyManager();
	void spawnEnemy();
	void update(float dt);
	void draw(sf::RenderWindow & window);

	std::vector<Enemy *> getEnemies();


private:
	std::vector<Enemy *> m_enemies;
	SpawnPointController m_spawnPointController;
	float m_spawnInterval;
};


