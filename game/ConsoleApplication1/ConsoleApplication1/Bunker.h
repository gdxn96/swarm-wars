#pragma once
#include "Polygon.h"
#include "GameConstants.h"
#include "AssetLoader.h"
#include "LightManager.h"
class Bunker
{
public:
	Bunker(float angle);
	void damageBunker(float damage);
	void draw(sf::RenderWindow & window);
	Polygon2D& getBounds();
	bool isAlive();


private:
	float m_health;
	float m_alive;
	float m_maxHealth;
	Polygon2D m_bounds;
	sf::RectangleShape bunker;
};


