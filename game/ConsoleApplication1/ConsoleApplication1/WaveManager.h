#pragma once
#include "Vector2D.h"
#include "PylonManager.h"
#include "Wave.h"

class WaveManager
{
public:
	WaveManager();
	void update(float dt);
	void draw(sf::RenderWindow & window);
	std::vector<Enemy *> getEnemies();
	bool isGameOver();

	bool isNewWave();
	void setNewWave(bool newWave);
private:
	PylonManager m_pylonMgr;
	std::vector<Wave*> m_waves;
	Wave* m_currentWave;
	bool m_newWave;

	bool m_gameOver;
};


