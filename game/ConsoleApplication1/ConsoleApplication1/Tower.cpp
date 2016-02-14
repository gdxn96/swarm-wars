#include "stdafx.h"
#include "Tower.h"

Tower::Tower() 
:	m_bounds(Circle(GameConstants::WINDOW_CENTRE, GameConstants::TOWER_RADIUS)),
	m_innerBounds(Circle(GameConstants::WINDOW_CENTRE, GameConstants::TOWER_RADIUS / 2))
{
}

void Tower::draw(sf::RenderWindow & window)
{
	m_bounds.draw(window, sf::Color::Magenta);
}

Circle& Tower::getBounds()
{
	return m_innerBounds;
}