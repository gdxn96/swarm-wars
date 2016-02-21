#include "stdafx.h"
#include "SpawnPoint.h"



SpawnPoint::SpawnPoint(Vector2D position) :
	m_pos(position),
	m_active(false),
	m_radius(5)
{

}

void SpawnPoint::draw(sf::RenderWindow& window)	// temporary for testing
{
	m_shape = sf::CircleShape(m_radius);
	m_shape.setPosition(Vector2D(m_pos.x - m_radius / 2, m_pos.y - m_radius / 2).toSFMLVector());
	m_shape.setFillColor(sf::Color::Green);

	window.draw(m_shape);
}

Vector2D SpawnPoint::getPos()
{
	return m_pos;
}

void SpawnPoint::setActive(bool val)
{
	m_active = val;
}