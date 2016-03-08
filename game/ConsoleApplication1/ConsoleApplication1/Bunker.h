#pragma once
#include "Polygon.h"
#include "GameConstants.h"
#include "AssetLoader.h"
#include "LightManager.h"
#include "Light.h"
class Bunker
{
public:
	Bunker(float angle);
	void damageBunker(float damage);
	void draw(sf::RenderWindow & window);
	Polygon2D& getBounds();
	bool isAlive();
	void update(float dt);
	~Bunker();
private:
	float m_health;
	float m_alive;
	float m_maxHealth;
	Polygon2D m_bounds;
	sf::RectangleShape bunker;
	Light * m_light;

	float const FLICKER_TRIGGER_INTERVAL;
	float m_flickerTriggerInterval;

	int swapAmount = 1;
};


