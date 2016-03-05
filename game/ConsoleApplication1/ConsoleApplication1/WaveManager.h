#pragma once
#include "Vector2D.h"
#include "PylonManager.h"
#include "Wave.h"
#include "Graph.h"

class WaveManager
{
public:
	WaveManager();
	void update(float dt);
	void draw(sf::RenderWindow & window);
	std::vector<Enemy *> getEnemies();
	bool isGameOver();
	void reset();

	bool isNewWave();
	void setNewWave(bool newWave);
	template <class T>
	std::string numberToString(const T& t) {

		std::stringstream ss;
		ss << t;

		return ss.str();

	}
private:
	PylonManager m_pylonMgr;
	std::vector<Wave*> m_waves;
	Wave* m_currentWave;
	bool m_newWave;
	std::vector<Vector2D> m_listOfPathPoints;
	float m_pathRadius;
	float m_pathAngleIncrement;
	bool m_gameOver;
	Graph<string, int> * graph;
};


