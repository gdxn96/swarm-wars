#pragma once

#include "Vector2D.h"
#include "SpawnPoint.h"



class Pylon
{
private:
	sf::CircleShape m_shape;
	Vector2D m_pos;
	float m_radius;
	std::vector<SpawnPoint*> m_spawns;

public:
	Pylon(Vector2D position);
	void draw(sf::RenderWindow& window);
	void addSpawnPoint(SpawnPoint* spawn);
	std::vector<SpawnPoint*> getSpawns();
};