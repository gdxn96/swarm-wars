#include "stdafx.h"
#include "Character.h"



//GLOBAL VARIABLES (FOR TESTING PURPOSES)
const int PATH_RADIUS = 200;
const float PI = std::acos(-1);



Character::Character()
{

}

Character::Character(float radius, float speed, Color green, 
					 Color yellow, Vector2f centre) 
:	m_move(false), 
	m_centre(centre),
	m_radius(radius),
	m_speed(speed),
	m_angle(90 * PI / 180.0f),
	m_targetRadius(radius / 5),
	m_targetAngle(m_angle)
{
	m_pos = Vector2f(m_centre.x + PATH_RADIUS * cos(m_angle),
					 m_centre.y + PATH_RADIUS * sin(m_angle));
	m_targetPos = m_pos;

	//Character shape
	m_shape = CircleShape(m_radius);
	m_shape.setFillColor(green);
	m_shape.setPosition(Vector2f(m_pos.x - m_radius, m_pos.y - m_radius));

	//Target shape
	m_target = CircleShape(m_targetRadius);
	m_target.setFillColor(yellow);
	m_target.setPosition(Vector2f(m_targetPos.x - m_targetRadius, 
								  m_targetPos.y - m_targetRadius));
}


void Character::update()
{
	resetAngles();	//if above 360 or below 0 degrees


	// if within 'm_speed' of target, stop moving
	if (m_move && fabs(m_angle - m_targetAngle) <= fabs(m_speed))
	{
		m_angle = m_targetAngle;
		m_move = false;
	}


	if (m_move)
	{
		m_angle += m_speed;
		m_pos = Vector2f(m_centre.x + PATH_RADIUS * cos(m_angle),
						 m_centre.y + PATH_RADIUS * sin(m_angle));
	}


	//update shape positions
	m_shape.setPosition(Vector2f(m_pos.x - m_radius, m_pos.y - m_radius));
	m_target.setPosition(Vector2f(m_targetPos.x - m_targetRadius, 
								  m_targetPos.y - m_targetRadius));
}


void Character::draw(RenderWindow& window)
{
	window.draw(m_target);
	window.draw(m_shape);
}


void Character::resetAngles()
{
	//angle
	if (m_angle >= 2 * PI)
	{
		m_angle -= 2 * PI;
	}
	else if (m_angle < 0)
	{
		m_angle += 2 * PI;
	}

	//target angle
	if (m_targetAngle >= 2 * PI)
	{
		m_targetAngle -= 2 * PI;
	}
	else if (m_targetAngle < 0)
	{
		m_targetAngle += 2 * PI;
	}
}


float Character::findAngleBetween()
{
	if (m_targetAngle < m_angle)
	{
		return (m_targetAngle + 2 * PI) - m_angle;
	}
	else
	{
		return m_targetAngle - m_angle;
	}
}



//Get methods

//Set methods
void Character::setTargetAngle(float angle, float speed)
{
	m_targetAngle = angle;
	m_targetPos = Vector2f(m_centre.x + PATH_RADIUS * cos(m_targetAngle), 
						   m_centre.y + PATH_RADIUS * sin(m_targetAngle));


	float angleBetween = findAngleBetween();

	if (angleBetween <= PI)
	{
		m_speed = speed;
	}
	else
	{
		m_speed = -speed;
	}
}


void Character::setMove(bool val)
{
	m_move = val;
}