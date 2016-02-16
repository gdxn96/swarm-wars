#include "stdafx.h"
#include "Unit.h"

Unit::Unit() 
:	PI(GameConstants::PI), 
	m_speed(GameConstants::PLAYER_SPEED), 
	m_radius(GameConstants::PLAYER_RADIUS),
	m_positionAngle(2 * GameConstants::PI * 0.75f),
	m_targetAngle(0),
	m_state(UNIT_STATE::WAITING),
	m_directionAngle(m_positionAngle),
	m_currentWeapon(WeaponFactory::getInstance()->getNewWeapon(WeaponType::ASSAULT_RIFLE)),
	m_isPlayer(true),
	m_isSelected(true),
	m_previousState(UNIT_STATE::WAITING)
{
	updateAngle(m_positionAngle);
	m_currentWeapon.update(getPositionByAngle(m_positionAngle), m_directionAngle, 0);
}

Unit::Unit(float startAngle)
: PI(GameConstants::PI),
m_speed(GameConstants::PLAYER_SPEED),
m_radius(GameConstants::PLAYER_RADIUS),
m_positionAngle(startAngle),
m_targetAngle(startAngle),
m_state(UNIT_STATE::WAITING),
m_directionAngle(startAngle),
m_currentWeapon(WeaponFactory::getInstance()->getNewWeapon(WeaponType::ASSAULT_RIFLE)),
m_isPlayer(false),
m_isSelected(false),
m_previousState(UNIT_STATE::WAITING)
{
	updateAngle(m_positionAngle);
	m_currentWeapon.update(getPositionByAngle(m_positionAngle), m_directionAngle, 0);
}

bool Unit::isPlayer()
{
	return m_isPlayer;
}

void Unit::setDirectionAngle(float angle)
{
	if (angle != 0)
	m_directionAngle = angle;
}

void Unit::fireWeapon()
{
	m_currentWeapon.fire();
}

void Unit::update(float dt)
{	
	//if given a move order
	if (m_state == UNIT_STATE::MOVING)
	{
		//find direction to target
		int direction = getDirectionToTarget();

		//increment angle
		updateAngle(m_positionAngle + dt * m_speed * direction);

		m_directionAngle = m_positionAngle + PI / 2 * direction;
		

		//check if unit is at destination
		if (fabs(m_positionAngle - m_targetAngle) <= fabs(m_speed * dt))
		{
			//set state to waiting
			m_state = UNIT_STATE::WAITING;
		}
	}
	else if (m_state == UNIT_STATE::WAITING)
	{ 
		
	}
	else if (m_state == UNIT_STATE::FIRING)
	{
		fireWeapon();
	}

	m_currentWeapon.update(getPositionByAngle(m_positionAngle), m_directionAngle, dt);
	
}

Polygon2D& Unit::getRangeCone()
{
	return m_currentWeapon.getRange();
}

void Unit::changeState(UNIT_STATE state)
{
	if ((m_isPlayer && !m_isSelected && m_state == UNIT_STATE::WAITING))
	{
		return;
	}
	if (m_state != state)
	{
		if (!m_isSelected || (m_isSelected && !m_isPlayer && m_state == UNIT_STATE::WAITING) || (!m_isPlayer && m_state == UNIT_STATE::FIRING))
		{
			cout << "ijbnisdfnubui" << endl;
			m_previousState = m_state;
			m_state = state;
		}
	}
		
}

void Unit::setSelected(bool isSelected)
{
	m_isSelected = isSelected;
}

UNIT_STATE &Unit::getPreviousState()
{
	return m_previousState;
}

void Unit::draw(sf::RenderWindow & window)
{
	//draw weapon
	m_currentWeapon.draw(window);

	////draw player
	//sf::CircleShape player = sf::CircleShape(m_radius);
	//player.setFillColor(sf::Color::Green);
	//if (m_isPlayer)
	//{
	//	player.setFillColor(sf::Color::Red);
	//}
	//
	//player.setOrigin(m_radius, m_radius);
	//player.setPosition(getPositionByAngle(m_positionAngle).toSFMLVector());
	

	//draw target
	sf::CircleShape target = sf::CircleShape(m_radius);
	target.setFillColor(sf::Color::Cyan);
	target.setOrigin(m_radius, m_radius);
	target.setPosition(getPositionByAngle(m_targetAngle).toSFMLVector());
	window.draw(target);
	target.setPosition(getPositionByAngle(m_positionAngle).toSFMLVector());
	target.setFillColor(sf::Color::Red);
	window.draw(target);
}

Vector2D Unit::getPositionByAngle(float angle)
{
	Vector2D newPosition;

	//find new position relative to origin
	Vector2D offset = Vector2D(angle) * GameConstants::WALK_RADIUS;

	//set new position to offest relative to the window centre
	newPosition = GameConstants::WINDOW_CENTRE + offset;

	return newPosition;
}

void Unit::updateAngle(float angle)
{
	//update angle
	m_positionAngle = NormalizeAngle(angle);

	//update player position based on angle
	m_position = getPositionByAngle(m_positionAngle);
}

void Unit::setTargetAngle(float targetAngle)
{
	if (targetAngle != 2 * PI && targetAngle != m_targetAngle)
	{
		m_targetAngle = NormalizeAngle(targetAngle);
		m_state = UNIT_STATE::MOVING;
	}
	
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
	float angleBetween = findAngleBetween(m_positionAngle, m_targetAngle);

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
