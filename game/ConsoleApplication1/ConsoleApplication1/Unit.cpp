#include "stdafx.h"
#include "Unit.h"

Unit::Unit(float startAngle, string id)
: PI(GameConstants::PI),
m_speed(GameConstants::PLAYER_SPEED),
m_radius(GameConstants::PLAYER_RADIUS),
m_positionAngle(startAngle),
m_targetAngle(startAngle),
m_state(UNIT_STATE::WAITING),
m_directionAngle(startAngle),
m_currentWeapon(WeaponFactory::getInstance()->getNewWeapon(WeaponType::AK)),
m_isPlayer(false),
m_isSelected(false),
m_previousState(UNIT_STATE::WAITING),
m_rank(UNIT_RANK::A),
m_experience(0),
m_id(id),
m_anim("walingAssaltAnimation", Vector2D(-100, -100)),
m_selectAnimation("selectorAnimation", Vector2D(-100, -100))
{
	m_anim.setFramesPerSecond(60);
	m_anim.setRadius(m_radius + 50);
	m_anim.SetLooping(false);
	m_selectAnimation.setFramesPerSecond(60);
	m_selectAnimation.setRadius(m_radius + 90);
	m_selectAnimation.SetLooping(false);
	//m_selectAnimation = Animation("")
	updateAngle(m_positionAngle);
	m_currentWeapon.update(getPositionByAngle(m_positionAngle), m_directionAngle, 0);
	m_currentWeapon.setParentId(m_id);
}

void Unit::setIsPlayer(bool isPlayer)
{
	m_isPlayer = isPlayer;
}

bool Unit::isPlayer()
{
	return m_isPlayer;
}

bool Unit::getSelected()
{
	return m_isSelected;
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
	
	m_anim.update();
	m_anim.setRotation((m_directionAngle - (PI )) * 180 / PI);
	m_anim.setPosition(m_position);

	m_selectAnimation.update();
	m_selectAnimation.setPosition(m_position);
	//if given a move order
	if (m_state == UNIT_STATE::MOVING)
	{
		//m_anim.setFramesPerSecond(45);
		m_anim.SetLooping(true);
		m_anim.changeAnimation("walingAssaltAnimation");
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
		m_anim.changeAnimation("walingAssaltAnimation");
		m_anim.SetLooping(false);

	}
	else if (m_state == UNIT_STATE::FIRING)
	{
		fireWeapon();
		m_anim.SetLooping(true);
		m_anim.setFramesPerSecond(500);
		m_anim.changeAnimation("shootingAssaltAnimation");
	}

	m_currentWeapon.update(getPositionByAngle(m_positionAngle), m_directionAngle, dt);

	if (m_isSelected)
	{
		m_selectAnimation.SetLooping(true);
		m_selectAnimation.setDoOnce(true);
	}
	else
	{
		m_selectAnimation.SetLooping(false);
		m_selectAnimation.reset();
	}
}

Polygon2D& Unit::getRangeCone()
{
	return m_currentWeapon.getRange();
}

void Unit::changeState(UNIT_STATE state)
{
	if ((m_isPlayer && !m_isSelected && m_state == UNIT_STATE::WAITING))
	{
		//return;
	}
	if (m_state != state)
	{
		if (!m_isSelected || (m_isSelected && !m_isPlayer && m_state == UNIT_STATE::WAITING) || (!m_isPlayer && m_state == UNIT_STATE::FIRING))
		{
			//cout << "ijbnisdfnubui" << endl;
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

void Unit::setWeapon(Weapon weapon)
{
	m_currentWeapon = weapon;
	m_currentWeapon.setParentId(m_id);
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
	m_anim.draw(window);
	m_selectAnimation.draw(window);
}

float Unit::getExperience()
{
	return m_experience;
}

void Unit::addExperience(float experience)
{
	m_experience += experience;
}

UNIT_RANK& Unit::getRank()
{
	return m_rank;
}

void Unit::setRank(UNIT_RANK rank)
{
	m_rank = rank;
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
	else if (m_isPlayer && targetAngle != m_targetAngle)
	{
		m_targetAngle = m_positionAngle;
		m_state = UNIT_STATE::WAITING;
	}
	
}

Vector2D Unit::getPosition()
{
	return m_position;
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

string Unit::getId()
{
	return m_id;
}
