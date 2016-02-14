#include "stdafx.h"
#include "Bunker.h"

Bunker::Bunker(float angle) : m_maxHealth(100), m_health(m_maxHealth)
{
	float minAngle = angle - GameConstants::BUNKER_SIZE_WIDTH / 2;
	float maxAngle = angle + GameConstants::BUNKER_SIZE_WIDTH / 2;

	Vector2D topLeft = Vector2D(minAngle) * GameConstants::BUNKER_SIZE_OUTER;
	Vector2D topRight = Vector2D(maxAngle) * GameConstants::BUNKER_SIZE_OUTER;
	Vector2D bottomRight = Vector2D(maxAngle) * GameConstants::BUNKER_SIZE_INNER;
	Vector2D bottomLeft = Vector2D(minAngle) * GameConstants::BUNKER_SIZE_INNER;

	m_bounds.addPoint(GameConstants::WINDOW_CENTRE + topLeft);
	m_bounds.addPoint(GameConstants::WINDOW_CENTRE + topRight);
	m_bounds.addPoint(GameConstants::WINDOW_CENTRE + bottomRight);
	m_bounds.addPoint(GameConstants::WINDOW_CENTRE + bottomLeft);

}

void Bunker::damageBunker(float damage)
{
	m_health -= damage;
}



void Bunker::draw(sf::RenderWindow & window)
{
	//at the moment it draws the collision bounds polygon, change the draw to whatever is appropriate here
	// not inside polygon class
	m_bounds.draw(window, sf::Color(128, 64, 128, 255));
}

Polygon2D& Bunker::getPolygon(sf::RenderWindow & window)
{
	return m_bounds;
}