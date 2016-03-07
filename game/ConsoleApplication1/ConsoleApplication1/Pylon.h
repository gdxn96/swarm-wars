#pragma once

#include "Vector2D.h"
#include "SpawnPoint.h"
#include "GameConstants.h"
#include "Animation.h"
#include "LightManager.h"
#include "Light.h"
class Pylon
{
private:
	Vector2D m_position;
	std::vector<SpawnPoint*> m_spawnPoints;
	float m_radius;
	bool m_alive;

public:
	Pylon(float anglePosition, float distFromCentre);
	void draw(sf::RenderWindow& window);
	void addSpawnPoint(SpawnPoint* spawn);
	Vector2D getSpawnPoint();
	Vector2D getPosition();
	void kill();
	bool getAlive();
	Animation m_anim;
	void update(float dt);
	Light * m_light;
};