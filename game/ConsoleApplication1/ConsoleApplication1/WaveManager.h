#pragma once
#include "Vector2D.h"
#include "PylonManager.h"
#include "Wave.h"
#include "Graph.h"
#include "AudioMgr.h"

class WaveManager
{
public:
	WaveManager();
	void update(float dt);
	void draw(sf::RenderWindow & window);
	std::vector<Enemy *> getEnemies();
	bool isGameOver();
	void reset();

	bool waveJustFinished();
	void setWaveJustFinished(bool waveFinished);

	bool waveJustStarted();
	void setWaveJustStarted(bool waveStarted);

	bool isWaveOver();

	float getTimeLeft();

private:
	PylonManager m_pylonMgr;
	std::vector<Wave*> m_waves;
	Wave* m_currentWave;
	std::vector<Vector2D> m_listOfPathPoints;
	float m_pathRadius;
	float m_pathAngleIncrement;
	const float MAX_BUY_TIME;
	float m_buyTime;
	bool m_gameOver;

	bool m_waveOver;
	bool m_waveJustFinished;
	bool m_waveJustStarted;
	Graph<string, int> * graph;

	void incrementWave();
};


