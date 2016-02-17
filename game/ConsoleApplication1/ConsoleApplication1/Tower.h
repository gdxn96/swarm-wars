#pragma once
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp"
#include "Circle.h"
#include "GameConstants.h"

class Tower
{
public:
	Tower();
	void draw(sf::RenderWindow & window);
	Circle& getBounds();
	void damage(float damage);
	bool getAlive();

private:
	Circle m_bounds;
	Circle m_innerBounds;
	float m_health;
	const float m_maxHealth;
};


