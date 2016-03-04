#pragma once
#include "Vector2D.h"
#include <vector>
#include "GameConstants.h"
#include "Pylon.h"
#include "Bolt.h"

class PylonManager
{
public:
	PylonManager();
	Vector2D& getSpawnPoint();
	void draw(sf::RenderWindow & window);
	void update(float dt);
	std::vector<Pylon *> getOpenSpawnPoints();
	void killPylon();
	void reset();

private:
	std::vector<Pylon * > m_pylons;
	std::vector<Pylon * > m_deadPylons;

	std::vector<Bolt *>  m_bolts;
};
