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
	m_damagePerSecond(damagePerSecond),
	m_healthBar(m_position + Vector2D(-m_radius,0), Vector2D(0.4f,0.7f),m_maxHealth),
	m_anim("bugAnimation", Vector2D(-100, -100))
{
	m_anim.setFramesPerSecond(60);
	m_anim.SetLooping(true);
	m_anim.setRadius(m_radius + 140);
}

float Enemy::getDamage()
{
	return m_damagePerSecond;
}

void Enemy::damage(float dmg)
{
	m_healthBar.setBarAmount(dmg);
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
	m_anim.setIsAlive(m_alive);
}

void Enemy::update(float dt)
{
	if (m_currentState == ENEMY_STATE::MOVING)
	{
		m_position += m_direction * dt * m_speed;
		m_bounds.setCentre(m_position);
	}
	m_healthBar.update();
	m_healthBar.setPosition(m_position + Vector2D(-20, 0));
	//m_healthBar.setBarAmount(m_health);
	m_anim.update();
	m_anim.setRotation(90 + (std::atan2(m_direction.y, m_direction.x) - GameConstants::PI) * 180 / GameConstants::PI);
	m_anim.setPosition(m_position);
}

void Enemy::draw(sf::RenderWindow& window)
{
	//m_bounds.draw(window, sf::Color::Red);
	m_anim.draw(window);
	m_healthBar.draw(window);
}

void Enemy::changeState(ENEMY_STATE state)
{
	if (m_currentState != state)
	{
		m_currentState = state;
	}
	
}