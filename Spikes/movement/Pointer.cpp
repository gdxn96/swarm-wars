
#include "stdafx.h"
#include "Pointer.h"


Pointer::Pointer(float radius, float speed, sf::Color color) 
:	m_radius(radius),
	m_speed(speed),
	m_color(color)
{
	m_pos = CENTRE + sf::Vector2f(0, -ARC_RADIUS);
	m_angle = 0;

	m_shape = sf::CircleShape(m_radius);
	m_shape.setFillColor(m_color);
	m_shape.setPosition(sf::Vector2f(m_pos.x - radius, m_pos.y - radius));	// use m_pos as origin
}


void Pointer::move(float arg)
{
	m_angle += m_speed * arg;

	resetAngle();
	updatePos();
}


void Pointer::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}


void Pointer::resetAngle()
{
	if (m_angle >= 2 * PI)
	{
		m_angle -= 2 * PI;
	}
	else if (m_angle <= -2 * PI)
	{
		m_angle += 2 * PI;
	}
}


void Pointer::updatePos()
{
	m_pos = sf::Vector2f(CENTRE.x + ARC_RADIUS * cos(m_angle), CENTRE.y + ARC_RADIUS * sin(m_angle));
	m_shape.setPosition(sf::Vector2f(m_pos.x - m_radius, m_pos.y - m_radius));
}