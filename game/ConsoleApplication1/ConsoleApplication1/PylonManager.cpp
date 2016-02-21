#include "stdafx.h"
#include "PylonManager.h"


PylonManager::PylonManager()
{
	float spawnRadius;
	float pylonRadius;

	if (GameConstants::WINDOW_SIZE.x <= GameConstants::WINDOW_SIZE.y)
	{
		pylonRadius = GameConstants::WINDOW_SIZE.x / 2;
		spawnRadius = pylonRadius + (GameConstants::WINDOW_SIZE.x / 4);
	}
	else
	{
		pylonRadius = GameConstants::WINDOW_SIZE.y / 2;
		spawnRadius = pylonRadius + (GameConstants::WINDOW_SIZE.y / 4);
	}

	createPylons(pylonRadius, spawnRadius);
}


void PylonManager::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_pylons.size(); i++)
	{
		for (int j = 0; j < m_pylons[i].getSpawns().size(); j++)
		{
			m_pylons[i].getSpawns().at(j)->draw(window);
		}
	}

	for (int i = 0; i < m_pylons.size(); i++)
	{
		m_pylons[i].draw(window);
	}
}


void PylonManager::createPylons(float pylonRadius, float spawnRadius)
{
	float angleIncrement = 2 * GameConstants::PI / GameConstants::NUMBER_OF_PYLONS;
	std::vector<SpawnPoint*> spawns;

	for (int i = 0; i < GameConstants::NUMBER_OF_PYLONS; i++)
	{
		Pylon pylon = Pylon(Vector2D(angleIncrement * i) * pylonRadius + GameConstants::WINDOW_CENTRE);

		if (spawns.size() != 0)
		{
			pylon.addSpawnPoint(spawns.back());
		}

		SpawnPoint* nextSpawn = new SpawnPoint(Vector2D((angleIncrement * i) + (angleIncrement / 2.0f)) * spawnRadius + GameConstants::WINDOW_CENTRE);
		pylon.addSpawnPoint(nextSpawn);

		spawns.push_back(nextSpawn);
		m_pylons.push_back(pylon);
	}

	if (m_pylons.size() != 0)
	{
		m_pylons[0].addSpawnPoint(spawns.back());
	}
}


void PylonManager::killPylon()
{
	int index = rand() % m_pylons.size();
	m_deadPylons.push_back(m_pylons.at(index));
	m_pylons.erase(m_pylons.begin() + index);
}


bool PylonManager::hasDeadPylons()
{
	if (m_pylons.size() != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Vector2D PylonManager::getSpawnPoint()
{
	int i = rand() % m_deadPylons.size();
	int j = rand() % m_deadPylons.at(i).getSpawns().size();
	return m_deadPylons.at(i).getSpawns().at(j)->getPos();
}


