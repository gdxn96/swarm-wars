#pragma once
#include "Vector2D.h"
#include <vector>
#include "GameConstants.h"
#include "Pylon.h"

class PylonManager
{
public:
	PylonManager();
	void createPylons(float pylonRadius, float spawnRadius);
	void draw(sf::RenderWindow& window);
	void killPylon();
	bool hasDeadPylons();
	Vector2D getSpawnPoint();

private:
	std::vector<Pylon> m_pylons;
	std::vector<Pylon> m_deadPylons;
};
