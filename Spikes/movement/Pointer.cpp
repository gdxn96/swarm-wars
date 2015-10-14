#include "stdafx.h"
#include "Pointer.h"

//using namespace sf;




//GLOBAL VARIABLES (FOR TESTING PURPOSES)
const int PATH_RADIUS = 200;
const float PI = std::acos(-1);



Pointer::Pointer(float radius, float speed, Color color, Vector2f centre) 
:	m_centre(centre),
	m_radius(radius),
	m_angle(0),
	m_speed(speed),
	m_color(color)
{
	//Define shape
	m_shape = CircleShape(m_radius);
	m_shape.setFillColor(m_color);
	updatePos();
}


void Pointer::move()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_angle -= m_speed;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_angle += m_speed;
	}

	resetAngle();
	updatePos();
}


void Pointer::resetAngle()
{
	if (m_angle >= 2 * PI)
	{
		m_angle -= 2 * PI;
	}
	else if (m_angle <= 0)
	{
		m_angle += 2 * PI;
	}
}


void Pointer::draw(RenderWindow& window)
{
	window.draw(m_shape);
}


void Pointer::updatePos()
{
	m_pos = Vector2f(m_centre.x + PATH_RADIUS * cos(m_angle), 
					 m_centre.y + PATH_RADIUS * sin(m_angle));

	m_shape.setPosition(Vector2f(m_pos.x - m_radius, m_pos.y - m_radius));
}



// Get methods

float Pointer::getAngle()
{
	return m_angle;
}