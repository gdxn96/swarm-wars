#include "stdafx.h"
#include "VisionCone.h"

VisionCone::VisionCone()
{
}

void VisionCone::update(Vector2D position, float minAngle, float maxAngle)
{
	m_minAngle = minAngle;
	m_maxAngle = maxAngle;
	m_position = position;
}

void VisionCone::setRange(float range)
{
	m_range = range;
}

void VisionCone::draw(sf::RenderWindow & window)
{
	
	sf::ConvexShape polygon;
	polygon.setPointCount(3);

	Vector2D a, b, c;
	a = m_position;
	b = m_position + Vector2D(m_minAngle) * m_range;
	c = m_position + Vector2D(m_maxAngle) * m_range;

	polygon.setPoint(0, a.toSFMLVector());
	polygon.setPoint(1, b.toSFMLVector());
	polygon.setPoint(2, c.toSFMLVector());


	window.draw(polygon);
}