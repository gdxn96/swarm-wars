#include "stdafx.h"
#include "Enemy.h"
#include <iostream>

using namespace std;
Enemy::Enemy(Vector2D spawnPosition, Vector2D direction, float maxHealth, float damagePerSecond, float speed, float radius)
:	m_radius(radius),
	m_currentState(ENEMY_STATE::MOVING),
	m_position(spawnPosition),
	m_direction(direction),
	m_speed(speed),
	m_bounds(Circle(spawnPosition, radius)),
	m_alive(true),
	m_health(maxHealth),
	m_maxHealth(maxHealth),
	m_damagePerSecond(damagePerSecond)
{

}

float Enemy::getDamage()
{
	return m_damagePerSecond;
}

void Enemy::damage(float dmg)
{
	m_health -= dmg;
	if (m_health <= 0)
	{
		kill();
	}
}

Circle& Enemy::getBounds()
{
	return m_bounds;
}

bool Enemy::getAlive()
{
	return m_alive;
}

void Enemy::kill()
{
	m_alive = false;
}

void Enemy::update(float dt)
{
	if (m_currentState == ENEMY_STATE::MOVING)
	{
		m_position += m_direction * dt * m_speed;
		m_bounds.setCentre(m_position);
	}

	
}

void Enemy::draw(sf::RenderWindow& window)
{
	m_bounds.draw(window, sf::Color::Red);
}

void Enemy::changeState(ENEMY_STATE state)
{
	if (m_currentState != state)
	{
		m_currentState = state;
	}
	
}