#include "stdafx.h"
#include "PylonManager.h"
#include "AudioMgr.h"

PylonManager::PylonManager()
{
	
}

std::vector<Pylon *> PylonManager::getOpenSpawnPoints()
{
	return m_deadPylons;
}

void PylonManager::reset()
{
	for (auto& pylon : m_pylons)
		delete pylon;

	for (auto& bolt : m_bolts)
		delete bolt;
	m_pylons.clear();
	m_deadPylons.clear();
	m_bolts.clear();

	// create pylons using game constants
	int numPylons = GameConstants::NUMBER_PYLONS;

	// distance from centre of screen and spawn positions
	float spawnRadius = GameConstants::WINDOW_SIZE.x;

	// distance from centre of screen and pylon positions
	float pylonRadius = GameConstants::WINDOW_SIZE.y / 2;

	//angle between pylons
	float pylonAngleIncrement = 2 * GameConstants::PI / numPylons;

	//angle offset between spawnpoints and pylon
	float spawnPointAngleOffset = pylonAngleIncrement / 2;
	std::vector<SpawnPoint* > spawnPoints;

	for (int i = 0; i < numPylons; i++)
	{
		m_pylons.push_back(new Pylon(pylonAngleIncrement * i, pylonRadius));

		spawnPoints.push_back(new SpawnPoint(
			pylonAngleIncrement * i + spawnPointAngleOffset,
			spawnRadius));

		m_pylons[i]->addSpawnPoint(spawnPoints[i]);
	}

	if (numPylons > 0)
	{
		m_pylons[0]->addSpawnPoint(spawnPoints[spawnPoints.size() - 1]);
		m_bolts.push_back(new Bolt(m_pylons[0], m_pylons[m_pylons.size() - 1]));
	}

	for (int i = 0; i < numPylons - 1; i++)
	{
		m_pylons[i + 1]->addSpawnPoint(spawnPoints[i]);
		m_bolts.push_back(new Bolt(m_pylons[i], m_pylons[i + 1]));
	}
}

void PylonManager::draw(sf::RenderWindow& window)
{
	
	for (auto& bolt : m_bolts)
	{
		bolt->draw(window);
	}
	for (auto & pylon : m_pylons)
	{
		pylon->draw(window);
	}
}

Vector2D& PylonManager::getSpawnPoint()
{
	if (m_deadPylons.size() > 0)
	{
		return m_deadPylons[rand() % m_deadPylons.size()]->getSpawnPoint();
	}

	
}

void PylonManager::killPylon()
{
	if (m_deadPylons.size() != m_pylons.size())
	{
		int index = rand() % m_pylons.size();
		Pylon* pylon = m_pylons[index];
		pylon->kill();
		m_deadPylons.push_back(pylon);

		for (auto& bolt : m_bolts)
		{
			if (bolt->containsPylon(pylon))
			{
				bolt->kill();
			}
		}
		
	}
}

void PylonManager::update(float dt)
{
	for (auto& bolt : m_bolts)
	{
		bolt->update(dt);
	}
	for (auto & pylon : m_pylons)
	{
		pylon->update(dt);
	}
}



