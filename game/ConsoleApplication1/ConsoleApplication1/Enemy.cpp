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
	m_bounds(Circle(m_position, m_radius))
{
	
}

Circle& Enemy::getBounds()
{
	return m_bounds;
}


void Enemy::update(float dt)
{
	m_position += m_direction * dt * m_speed;
	m_bounds.setCentre(m_position);
}

void Enemy::draw(sf::RenderWindow& window)
{
	sf::CircleShape enemy = sf::CircleShape(m_radius);
	enemy.setFillColor(sf::Color::Red);
	enemy.setOrigin(m_radius, m_radius);
	enemy.setPosition(m_position.toSFMLVector());
	window.draw(enemy);
}

void Enemy::changeState(ENEMY_STATE state)
{
	m_currentState = state;
}