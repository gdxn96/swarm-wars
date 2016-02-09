#include "stdafx.h"
#include "Unit.h"

Unit::Unit() 
:	PI(GameConstants::PI), 
	m_speed(GameConstants::PLAYER_SPEED), 
	m_radius(GameConstants::PLAYER_RADIUS),
	m_angle(0),
	m_targetAngle(0),
	m_state(UNIT_STATE::WAITING)
{
	updateAngle(m_angle);
}

void Unit::update(float dt)
{	
	//if given a move order
	if (m_state == UNIT_STATE::MOVING)
	{
		//find direction to target
		int direction = getDirectionToTarget();

		//increment angle
		updateAngle(m_angle + dt * m_speed * direction);

		//check if unit is at destination
		if (fabs(m_angle - m_targetAngle) <= fabs(m_speed * dt))
		{
			//set state to waiting
			m_state = UNIT_STATE::WAITING;
		}
	}
	else if (m_state == UNIT_STATE::WAITING)
	{ 

	}
	
}

void Unit::draw(sf::RenderWindow & window)
{
	sf::CircleShape player = sf::CircleShape(m_radius);
	player.setFillColor(sf::Color::Red);
	player.setOrigin(m_radius, m_radius);
	player.setPosition(getPositionByAngle(m_angle).toSFMLVector());
	window.draw(player);


	sf::CircleShape target = sf::CircleShape(m_radius);
	target.setFillColor(sf::Color::Blue);
	target.setOrigin(m_radius, m_radius);
	target.setPosition(getPositionByAngle(m_targetAngle).toSFMLVector());
	window.draw(target);
}

Vector2D Unit::getPositionByAngle(float angle)
{
	Vector2D newPosition;

	//find new position relative to origin
	Vector2D offset = Vector2D(GameConstants::WALK_RADIUS * cos(angle),
		GameConstants::WALK_RADIUS * sin(angle));

	//set new position to offest relative to the window centre
	newPosition = GameConstants::WINDOW_CENTRE + offset;

	return newPosition;
}

void Unit::updateAngle(float angle)
{
	//update angle
	m_angle = NormalizeAngle(angle);

	//update player position based on angle
	m_position = getPositionByAngle(m_angle);
}

void Unit::setTargetAngle(float targetAngle)
{
	m_targetAngle = NormalizeAngle(targetAngle);
	m_state = UNIT_STATE::MOVING;
}

float Unit::NormalizeAngle(float angle)
{
	float PI = GameConstants::PI;
	while (angle <= -0) angle += 2 * PI;
	while (angle > 2 * PI) angle -= 2 * PI;
	return angle;
}

int Unit::getDirectionToTarget()
{
	int direction = 0;
	float angleBetween = findAngleBetween(m_angle, m_targetAngle);

	if (angleBetween <= PI)
	{
		direction = 1;	//clockwise
	}
	else
	{
		direction = -1;	//anti-clockwise
	}

	return direction;
}

float Unit::findAngleBetween(float b, float a)
{
	if (a < b)
	{
		return (a + 2 * PI) - b;
	}
	else
	{
		return a - b;
	}
}
