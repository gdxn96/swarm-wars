#include "stdafx.h"
#include "WaveManager.h"
#include "Enemy.h"
#include <iostream>

WaveManager::WaveManager() : m_waves({
	new Wave(WAVE_CONSTANTS::WAVE1_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE1_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE1_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE1_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE1_PYLONS_TO_KILL, &m_pylonMgr),
	new Wave(WAVE_CONSTANTS::WAVE2_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE2_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE2_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE2_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE2_PYLONS_TO_KILL, &m_pylonMgr),
	new Wave(WAVE_CONSTANTS::WAVE3_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE3_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE3_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE3_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE3_PYLONS_TO_KILL, &m_pylonMgr),
	new Wave(WAVE_CONSTANTS::WAVE4_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE4_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE4_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE4_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE4_PYLONS_TO_KILL, &m_pylonMgr)
}),
m_currentWave(m_waves[0]),
m_gameOver(false),
m_newWave(true)
{
	m_currentWave->init();
}

std::vector<Enemy *> WaveManager::getEnemies()
{
	if (m_currentWave!= nullptr)
	return m_currentWave->getEnemies();
	else
	{
		return vector<Enemy*>();
	}
}

void WaveManager::update(float dt)
{
	
	m_pylonMgr.update(dt);

	if (m_currentWave != nullptr && m_currentWave->getAlive())
	{
		m_currentWave->update(dt);
	}
	else
	{
		for (int i = 0; i < m_waves.size(); i++)
		{
			if (m_currentWave == m_waves[i])
			{
				//cleanup dead wave
				delete m_currentWave;

				//increment wave or activate gameOver
				if (i + 1 < m_waves.size())
				{
					m_currentWave = m_waves[i + 1];
					m_newWave = true;
					m_currentWave->init();
				}
				else
				{
					//gameOver
					m_gameOver = true;
					m_currentWave = nullptr;
				}

				//cleanup dead wave
				m_waves.erase(m_waves.begin() + i);
				break;
				
			}
		}
	}
	
}

bool WaveManager::isNewWave()
{
	return m_newWave;
}

void WaveManager::setNewWave(bool newWave)
{
	m_newWave = newWave;
}

void WaveManager::draw(sf::RenderWindow & window)
{
	if (m_currentWave != nullptr)
	{
		m_currentWave->draw(window);
	}
	
	m_pylonMgr.draw(window);
}

bool WaveManager::isGameOver()
{
	return m_gameOver;
}

