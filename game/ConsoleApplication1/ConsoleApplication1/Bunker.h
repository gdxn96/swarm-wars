#pragma once
#include "Polygon.h"
#include "GameConstants.h"

class Bunker
{
public:
	Bunker(float angle);
	void damageBunker(float damage);
	void draw(sf::RenderWindow & window);
	Polygon2D& getPolygon(sf::RenderWindow & window);


private:
	float m_health;
	float m_maxHealth;
	Polygon2D m_bounds;
};


