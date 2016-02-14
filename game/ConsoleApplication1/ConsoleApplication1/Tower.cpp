#include "stdafx.h"
#include "Tower.h"

Tower::Tower() : m_bounds(Circle(GameConstants::WINDOW_CENTRE, GameConstants::TOWER_RADIUS))
{
}

void Tower::draw(sf::RenderWindow & window)
{
	m_bounds.draw(window, sf::Color::Magenta);
}

Circle& Tower::getBounds()
{
	return m_bounds;
}