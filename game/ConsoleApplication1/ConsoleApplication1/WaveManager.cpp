#include "stdafx.h"
#include "WaveManager.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

WaveManager::WaveManager() : 
m_gameOver(false),
MAX_BUY_TIME(15.0f),
m_buyTime(MAX_BUY_TIME),
m_waveOver(false),
m_waveJustFinished(false),
m_waveJustStarted(false)
{

}

void WaveManager::reset()
{
	m_waveOver = false;
	m_waveJustFinished = false;
	string c = "";
	float x, y;
	int i = 0;
	graph = new Graph<string, int>(30);
	ifstream myfile;

	myfile.open("nodes.txt");
	while (myfile >> c >> x >> y) {
		graph->addNode(c, x, y, i++);
	}
	myfile.close();
	myfile.open("arcs.txt");
	int from, to, weight;
	while (myfile >> from >> to >> weight) {
		//cout << from << " " << to << " " << weight << endl;
		graph->addArc(from, to, weight);
		graph->addArc(to, from, weight);
	}
	myfile.close();

	m_pylonMgr.reset();
	m_waves.clear();
	m_waves = vector<Wave*>({
	new Wave(WAVE_CONSTANTS::WAVE1_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE1_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE1_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE1_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE1_PYLONS_TO_KILL, &m_pylonMgr),
	new Wave(WAVE_CONSTANTS::WAVE2_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE2_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE2_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE2_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE2_PYLONS_TO_KILL, &m_pylonMgr),
	new Wave(WAVE_CONSTANTS::WAVE3_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE3_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE3_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE3_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE3_PYLONS_TO_KILL, &m_pylonMgr),
	new Wave(WAVE_CONSTANTS::WAVE4_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE4_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE4_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE4_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE4_PYLONS_TO_KILL, &m_pylonMgr),
	new Wave(WAVE_CONSTANTS::WAVE5_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE5_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE5_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE5_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE5_PYLONS_TO_KILL, &m_pylonMgr),
	new Wave(WAVE_CONSTANTS::WAVE6_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE6_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE6_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE6_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE6_PYLONS_TO_KILL, &m_pylonMgr),
	new Wave(WAVE_CONSTANTS::WAVE7_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE7_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE7_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE7_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE7_PYLONS_TO_KILL, &m_pylonMgr),
	new Wave(WAVE_CONSTANTS::WAVE8_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE8_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE8_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE8_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE8_PYLONS_TO_KILL, &m_pylonMgr),
	new Wave(WAVE_CONSTANTS::WAVE9_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE9_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE9_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE9_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE9_PYLONS_TO_KILL, &m_pylonMgr),
	new Wave(WAVE_CONSTANTS::WAVE10_ENEMY1_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE10_ENEMY2_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE10_BOSS_SPAWN_INTERVAL, WAVE_CONSTANTS::WAVE10_NUMBER_ENEMIES, WAVE_CONSTANTS::WAVE10_PYLONS_TO_KILL, &m_pylonMgr)
	});

	m_currentWave = m_waves[0];
	m_currentWave->init();
	m_gameOver = false;

	m_pathRadius = GameConstants::WINDOW_SIZE.y / 3;
	m_pathAngleIncrement = 2 * GameConstants::PI / 20;//number of points
	for (int i = 0; i < 20; i++)
	{
		m_listOfPathPoints.push_back(Vector2D(m_pathAngleIncrement * i) * m_pathRadius + GameConstants::WINDOW_CENTRE);
	}
	/*ofstream outputfile;
	outputfile.open("output.txt");
	for (int line = 0; line < 20; line++)
	{
		outputfile << numberToString(line) << " " << numberToString(m_listOfPathPoints[line].x) << " " << numberToString(m_listOfPathPoints[line].y) << "\n";
	}
	outputfile << numberToString(20) << " " << numberToString(GameConstants::WINDOW_CENTRE.x) << " " << numberToString(GameConstants::WINDOW_CENTRE.y) << "\n";
	outputfile.close();

	ofstream outputArcs;
	outputArcs.open("outputArcs.txt");
	for (int line = 0; line < 20; line++)
	{
		if (line == 0)
		{
			outputArcs << numberToString(line) << " " << numberToString(line + 1) << " " << numberToString(100) << " \n";
			outputArcs << numberToString(line) << " " << numberToString(19) << " " << numberToString(100) << " \n";
		}
		else if (line == 19)
		{
			outputArcs << numberToString(line) << " " << numberToString(0) << " " << numberToString(100) << " \n";
			outputArcs << numberToString(line) << " " << numberToString(line - 1) << " " << numberToString(100) << " \n";
		}
		else
		{
			outputArcs << numberToString(line) << " " << numberToString(line + 1) << " " << numberToString(100) << " \n";
			outputArcs << numberToString(line) << " " << numberToString(line - 1) << " " << numberToString(100) << " \n";
		}
	}
	outputArcs << numberToString(0) << " " << numberToString(20) << " " << numberToString(100) << " \n";
	outputArcs << numberToString(4) << " " << numberToString(20) << " " << numberToString(100) << " \n";
	outputArcs << numberToString(9) << " " << numberToString(20) << " " << numberToString(100) << " \n";
	outputArcs << numberToString(14) << " " << numberToString(20) << " " << numberToString(100) << " \n";
	outputArcs.close();*/// graph stuff
	for (auto & p : m_waves)
	{
		p->setGraph(graph);
	}
}

void WaveManager::incrementWave()
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
				m_currentWave->init();
				m_waveOver = false;
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

std::vector<Enemy *> WaveManager::getEnemies()
{
	if (m_currentWave!= nullptr)
	return m_currentWave->getEnemies();
	else
	{
		return vector<Enemy*>();
	}
	m_gameOver = false;
}

bool WaveManager::isWaveOver()
{
	return m_waveOver;
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
		if (m_buyTime == MAX_BUY_TIME)
		{
			m_waveJustFinished = true;
		}
		m_buyTime -= dt;
		m_waveOver = true;

		if (m_buyTime < 0)
		{
			m_buyTime = MAX_BUY_TIME;
			incrementWave();
			m_waveJustStarted = true;
			
		}
		
	}
	
}

float WaveManager::getTimeLeft()
{
	return m_buyTime;
}

bool WaveManager::waveJustFinished()
{
	return m_waveJustFinished;
}

void WaveManager::setWaveJustFinished(bool waveFinished)
{
	m_waveJustFinished = waveFinished;
}


bool WaveManager::waveJustStarted()
{
	return m_waveJustStarted;
}

void WaveManager::setWaveJustStarted(bool waveStarted)
{
	m_waveJustStarted = waveStarted;
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

