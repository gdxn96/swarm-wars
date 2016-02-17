#include "stdafx.h"
#include "Tower.h"

Tower::Tower() 
:	m_innerBounds(Circle(GameConstants::WINDOW_CENTRE, GameConstants::TOWER_RADIUS / 2)),
	m_outerBounds(Circle(GameConstants::WINDOW_CENTRE, GameConstants::TOWER_RADIUS)),
	m_health(GameConstants::TOWER_HEALTH),
	m_maxHealth(GameConstants::TOWER_HEALTH)
{
}

void Tower::draw(sf::RenderWindow & window)
{
	m_outerBounds.draw(window, sf::Color::Magenta);
}

void Tower::damage(float damage)
{
	m_health -= damage;
}

bool Tower::getAlive()
{
	return m_health > 0;
}

Circle& Tower::getInnerBounds()
{
	return m_innerBounds;
}

Circle& Tower::getOuterBounds()
{
	return m_outerBounds;
}