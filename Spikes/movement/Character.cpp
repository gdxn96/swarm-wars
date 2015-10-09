#include "stdafx.h"
#include "Character.h"


Character::Character()
{

}

Character::Character(int type, float angle)
:	m_type(type),
	m_angle(angle),
	m_targAngle(angle)
{
	m_pos = sf::Vector2f(CENTRE.x + ARC_RADIUS * cos(m_angle), CENTRE.y + ARC_RADIUS * sin(m_angle));


	// set variables depending on type of troop
	if (m_type == soldier)
	{
		m_radius = 40;
		m_speed = 0.0001f;
		m_color = sf::Color(25, 51, 0, 255);
	}
	else if (m_type == sergeant)
	{
		m_radius = 50;
		m_speed = 0.000075f;
		m_color = sf::Color(255, 215, 0, 255);
	}


	m_shape = sf::CircleShape(m_radius);
	m_shape.setFillColor(m_color);
	m_shape.setPosition(sf::Vector2f(m_pos.x - m_radius, m_pos.y - m_radius));
}

void Character::update()
{

}

void Character::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}