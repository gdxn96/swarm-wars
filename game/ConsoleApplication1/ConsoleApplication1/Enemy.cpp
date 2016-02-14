#include "stdafx.h"
#include "Enemy.h"
#include <iostream>

using namespace std;
Enemy::Enemy(Vector2D spawnPosition, Vector2D direction) 
:   m_radius(GameConstants::ENEMY_RADIUS), 
	m_currentState(ENEMY_STATE::MOVING),
	m_position(spawnPosition),
	m_direction(direction),
	m_speed(GameConstants::ENEMY_SPEED),
	m_bounds(Circle(m_position, m_radius)),
	m_alive(true)
{
	
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
	m_currentState = state;
}