#include "stdafx.h"
#include "Pointer.h"
#include "Var.h"

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 


Pointer::Pointer(float radius, float speed, sf::Color color) 
:	m_radius(radius),
	m_speed(speed),
	m_color(color)
{
	m_pos = CENTRE - sf::Vector2f(0, ARC_RADIUS);
	m_angle = 0;

	m_shape = sf::CircleShape(m_radius);
	m_shape.setFillColor(m_color);
	m_shape.setPosition(m_pos);
}


void Pointer::update()
{
	m_angle += m_speed;

	//reset angle every revolution
	if (m_angle >= 2*PI)
	{
		m_angle -= 2*PI;
	}

	m_pos = sf::Vector2f(CENTRE.x + ARC_RADIUS * cos(m_angle), CENTRE.y + ARC_RADIUS * sin(m_angle));
	m_shape.setPosition(m_pos);
}

void Pointer::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}