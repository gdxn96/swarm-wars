#include "stdafx.h"
#include "Tower.h"

Tower::Tower() 
:	m_bounds(Circle(GameConstants::WINDOW_CENTRE, GameConstants::TOWER_RADIUS)),
	m_innerBounds(Circle(GameConstants::WINDOW_CENTRE, GameConstants::TOWER_RADIUS / 2)),
	m_health(100),
	m_maxHealth(100)
{
}

void Tower::draw(sf::RenderWindow & window)
{
	m_bounds.draw(window, sf::Color::Magenta);
}

void Tower::damage(float damage)
{
	m_health -= damage;
}

bool Tower::getAlive()
{
	return m_health > 0;
}

Circle& Tower::getBounds()
{
	return m_innerBounds;
}