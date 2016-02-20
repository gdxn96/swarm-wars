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
	float angle = ((maxAngle - minAngle) / 2) + minAngle;

	Vector2D a, b, c;
	a = m_position;
	b = m_position + Vector2D(m_minAngle) * m_range;
	c = m_position + Vector2D(m_maxAngle) * m_range;

	m_rangeSize.clearPoints();
	m_rangeSize.addPoint(a);
	m_rangeSize.addPoint(b);
	m_rangeSize.addPoint(c);

	Vector2D broadPhaseCircleCentre = Vector2D(angle) * m_range / 2;
	m_rangeSize.setBroadPhaseCircle(m_position + broadPhaseCircleCentre, m_range / 2);
}

void VisionCone::setRange(float range)
{
	m_range = range;
	m_rangeSize.setBroadPhaseCircle(m_position, m_range);
}

Polygon2D& VisionCone::getRange()
{
	return m_rangeSize;
}

void VisionCone::draw(sf::RenderWindow & window)
{
	
	m_rangeSize.draw(window, sf::Color(255, 255, 255, 12));
}