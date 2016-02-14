#include "stdafx.h"
#include "Character.h"



//GLOBAL VARIABLE (FOR TESTING PURPOSES)
const int PATH_RADIUS = 200;



Character::Character(float radius, float speed, Color green, Color yellow, 
					 Vector2D centre) 
:	M_PI(std::acos(-1)),
	DEGREES(M_PI / 180.0f),
	m_move(false), 
	m_centre(centre),
	m_radius(radius),
	m_speed(speed),
	m_angle(90 * DEGREES),
	m_tRadius(radius / 5),
	m_tAngle(m_angle)
{
	Vector2D offset = Vector2D(PATH_RADIUS * cos(m_angle), 
							   PATH_RADIUS * sin(m_angle));

	//Positions
	m_pos = Vector2D(m_centre.x + offset.x, m_centre.y + offset.y);
	m_tPos = m_pos;

	//Character shape
	m_shape = CircleShape(m_radius);
	m_shape.setFillColor(green);
	m_shape.setPosition(Vector2f(m_pos.x - m_radius, m_pos.y - m_radius));

	//Target shape
	m_target = CircleShape(m_tRadius);
	m_target.setFillColor(yellow);
	m_target.setPosition(Vector2f(m_tPos.x - m_tRadius, 
								  m_tPos.y - m_tRadius));
}


void Character::update()
{
	// if close to target, snap to it and stop moving
	if (m_move && fabs(m_angle - m_tAngle) <= fabs(m_speed))
	{
		m_angle = m_tAngle;
		m_move = false;
		updatePos();
	}
	else if (m_move)
	{
		m_angle += m_speed;
		resetAngle();
		updatePos();
	}
}


void Character::updatePos()
{
	Vector2D offset = Vector2D(PATH_RADIUS * cos(m_angle), 
							   PATH_RADIUS * sin(m_angle));

	//Positions
	m_pos = Vector2D(m_centre.x + offset.x, m_centre.y + offset.y);
	m_shape.setPosition(Vector2f(m_pos.x - m_radius, m_pos.y - m_radius));
}


void Character::draw(RenderWindow* window)
{
	window->draw(m_target);
	window->draw(m_shape);
}


void Character::resetAngle()
{
	//angle
	if (m_angle >= 2 * M_PI)
	{
		m_angle -= 2 * M_PI;
	}
	else if (m_angle < 0)
	{
		m_angle += 2 * M_PI;
	}
}


void Character::findDirectionToTarget(float speed)
{
	float angleBetween = findAngleBetween();

	if (angleBetween <= M_PI)
	{
		m_speed = speed;	//clockwise
	}
	else
	{
		m_speed = -speed;	//anti-clockwise
	}
}


float Character::findAngleBetween()
{
	if (m_tAngle < m_angle)
	{
		return (m_tAngle + 2 * M_PI) - m_angle;
	}
	else
	{
		return m_tAngle - m_angle;
	}
}



//Get methods

//Set methods
void Character::setTargetAngle(float angle, float speed)
{
	m_tAngle = angle;
	Vector2D offset = Vector2D(PATH_RADIUS * cos(angle), 
							   PATH_RADIUS * sin(angle));

	//Set positions
	m_tPos = Vector2D(m_centre.x + offset.x, m_centre.y + offset.y);
	m_target.setPosition(Vector2f(m_tPos.x - m_tRadius,
								  m_tPos.y - m_tRadius));

	findDirectionToTarget(speed);
}


void Character::setMove(bool val)
{
	m_move = val;
}