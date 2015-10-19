#include "stdafx.h"
#include "OrderPointer.h"

using namespace sf;




//GLOBAL VARIABLE (FOR TESTING PURPOSES)
const int PATH_RADIUS = 200;



OrderPointer::OrderPointer(float radius, float speed, Color color, Vector2D centre)
:	M_PI(std::acos(-1)),
	DEGREES(M_PI * 180.0f),
	m_centre(centre),
	m_radius(radius),
	m_angle(0),
	m_speed(speed),
	m_minSpeed(speed),
	m_maxSpeed(speed * 2),
	m_interval(speed / 60),
	m_color(color)
{
	//Define shape
	m_shape = CircleShape(m_radius);
	m_shape.setFillColor(m_color);
	updatePos();
}


void OrderPointer::update()
{
	move();
}


void OrderPointer::move()
{
	// Move pointer
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		changePointerSpeed();
		m_angle -= m_speed;
		resetAngle();
		updatePos();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		changePointerSpeed();
		m_angle += m_speed;
		resetAngle();
		updatePos();
	}
}


void OrderPointer::resetAngle()
{
	if (m_angle >= 2 * M_PI)
	{
		m_angle -= 2 * M_PI;
	}
	else if (m_angle <= 0)
	{
		m_angle += 2 * M_PI;
	}
}


void OrderPointer::changePointerSpeed()
{
	if (Keyboard::isKeyPressed(Keyboard::LShift) && m_speed <= m_maxSpeed)
	{
		m_speed += m_interval;
	}
	else if (m_speed >= m_minSpeed)
	{
		m_speed -= m_interval;
	}
}


void OrderPointer::draw(RenderWindow* window)
{
	window->draw(m_shape);
}


void OrderPointer::updatePos()
{
	Vector2D offset = Vector2D(PATH_RADIUS * cos(m_angle),
							   PATH_RADIUS * sin(m_angle));

	//Positions
	m_pos = Vector2D(m_centre.x + offset.x, m_centre.y + offset.y);
	m_shape.setPosition(Vector2f(m_pos.x - m_radius, m_pos.y - m_radius));
}



// Get methods

float OrderPointer::getAngle()
{
	return m_angle;
}