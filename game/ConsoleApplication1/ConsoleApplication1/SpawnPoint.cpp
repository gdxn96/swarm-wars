#include "stdafx.h"
#include "SpawnPoint.h"

SpawnPoint::SpawnPoint(float angle, float distFromCentre)
{
	m_points.push_back(Vector2D(angle + GameConstants::PI / 180 * 4) * distFromCentre + GameConstants::WINDOW_CENTRE);
	m_points.push_back(Vector2D(angle) * distFromCentre + GameConstants::WINDOW_CENTRE);
	m_points.push_back(Vector2D(angle - GameConstants::PI / 180 * 4) * distFromCentre + GameConstants::WINDOW_CENTRE);
}

Vector2D SpawnPoint::getPoint()
{
	return m_points[rand() % m_points.size()];
}

void SpawnPoint::draw(sf::RenderWindow & window)
{
	sf::CircleShape circle(10);
	circle.setOrigin(10, 10);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(getPoint().toSFMLVector());
	window.draw(circle);

}