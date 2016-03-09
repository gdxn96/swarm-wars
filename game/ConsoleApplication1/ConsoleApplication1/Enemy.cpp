#include "stdafx.h"
#include "Enemy.h"
#include <iostream>

using namespace std;
Enemy::Enemy(Vector2D spawnPosition, std::vector<Node *> _nodes, float maxHealth, float damagePerSecond, float speed, float radius, int numberDeadPylons, std::string animKey)
:	m_radius(radius),
	m_currentState(ENEMY_STATE::MOVING),
	m_position(spawnPosition),
	m_speed(speed),
	m_bounds(Circle(spawnPosition, radius)),
	m_alive(true),
	m_health(maxHealth),
	m_maxHealth(maxHealth),
	m_damagePerSecond(damagePerSecond),
	m_healthBar(m_position + Vector2D(-m_radius, m_radius), Vector2D(0.4f, 0.7f), m_maxHealth, sf::Color(4, 254, 253, 255), sf::Color(17, 169, 169, 255)),
	m_anim(animKey, Vector2D(-100, -100)),
	m_neighbourCircle(m_position, 400),
	m_seperationWeighting(1 - (0.5f * numberDeadPylons / static_cast<float>(GameConstants::NUMBER_PYLONS))),
	nodes(_nodes)
{
	m_anim.setFramesPerSecond(220);
	m_anim.SetLooping(true);
	m_anim.setSize(100/2, 150/2);
	m_pathSize = nodes.size() -1;
	m_direction = (nodes[m_pathSize]->getPosition() - spawnPosition).Normalize();
	m_targetDirection = (nodes[m_pathSize]->getPosition() - spawnPosition).Normalize();
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
	if (Vector2D::Distance(m_position, nodes[m_pathSize]->getPosition()) <= 50)
	{
		if (m_pathSize != 0)
		m_pathSize--;
		
	}
	m_targetDirection = (nodes[m_pathSize]->getPosition() - m_position).Normalize();
	
	if (m_currentState == ENEMY_STATE::MOVING)
	{
		m_position += m_direction * dt * m_speed;
		m_bounds.setCentre(m_position);
		m_neighbourCircle.setCentre(m_position);
	}
	m_healthBar.update();
	m_healthBar.setPosition(m_position + Vector2D(-20, 0));
	//m_healthBar.setBarAmount(m_health);
	m_anim.update(dt);
	if (m_maxHealth == ENEMY_STATS::BOSS_HEALTH)
	{
		m_anim.setRotation((std::atan2(m_direction.y, m_direction.x) - GameConstants::PI) * 180 / GameConstants::PI);
	}
	else if (m_maxHealth == ENEMY_STATS::ENEMY2_HEALTH)
	{
		m_anim.setRotation(90 +(std::atan2(m_direction.y, m_direction.x) - GameConstants::PI) * 180 / GameConstants::PI);
	}
	else
	{
		m_anim.setRotation((std::atan2(m_direction.y, m_direction.x) - GameConstants::PI) * 180 / GameConstants::PI);
	}

	
	m_anim.setPosition(m_position);

	m_direction = ((getSeperationHeading() + getAlignmentHeading() + getCohesionHeading()) / 3).Normalize();
}

Circle& Enemy::getNeighbourBounds()
{
	return m_neighbourCircle;
}

void Enemy::addNeighbour(Enemy* enemy)
{
	m_neighbours.push_back(enemy);
}

void Enemy::resetNeighbours()
{
	m_neighbours.clear();
}

Vector2D Enemy::getSeperationHeading()
{
	Vector2D seperationHeading = m_direction;
	Vector2D neighbourDirections;
	for (auto& enemy : m_neighbours)
	{
		neighbourDirections += (enemy->getBounds().getCentre() - m_position).Normalize();
	}
	if (m_neighbours.size() != 0)
	{
		neighbourDirections = neighbourDirections / m_neighbours.size();
		seperationHeading = -neighbourDirections;
	}

	return seperationHeading.Normalize() * m_seperationWeighting;
}

Vector2D Enemy::getAlignmentHeading()
{
	return m_targetDirection;
}

Vector2D Enemy::getDirection()
{
	return m_direction;
}

Vector2D Enemy::getCohesionHeading()
{
	Vector2D positions;
	Vector2D cohesionHeading = m_direction;
	for (auto& enemy : m_neighbours)
	{
		positions += enemy->getBounds().getCentre();
	}
	if (m_neighbours.size() != 0)
	{
		positions = positions / m_neighbours.size();
		cohesionHeading = (positions - m_position).Normalize();
	}

	return cohesionHeading;
	
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