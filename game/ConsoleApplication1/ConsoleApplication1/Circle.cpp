#include "stdafx.h"
#include "Circle.h"

Circle::Circle(Vector2D centre, float radius) : m_radius(radius), m_centre(centre)
{
}

void Circle::setCentre(Vector2D centre)
{
	m_centre = centre;
}

void Circle::setRadius(float radius)
{
	m_radius = radius;
}

float Circle::getRadius()
{
	return m_radius;
}

Vector2D Circle::getCentre()
{
	return m_centre;
}

void Circle::draw(sf::RenderWindow & window, sf::Color color)
{
	sf::CircleShape circle = sf::CircleShape(m_radius);
	circle.setFillColor(color);
	circle.setOrigin(m_radius, m_radius);
	circle.setPosition(m_centre.toSFMLVector());
	window.draw(circle);
}