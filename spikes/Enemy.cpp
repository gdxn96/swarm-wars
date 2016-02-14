#include "stdafx.h"
#include "Enemy.h"



Enemy::Enemy()
{

}

Enemy::Enemy(sf::Vector2f pos, float speed, sf::Color red) 
:	m_pos(pos), 
	m_speed(speed),
	m_radius(25),
	m_atTargetNode(true),
	m_atFinalNode(false)
{
	m_shape = sf::CircleShape(m_radius);
	m_shape.setFillColor(red);
	m_shape.setPosition(m_pos.x - m_radius, m_pos.y - m_radius);
}



void Enemy::update()
{
	if (!m_atTargetNode)
	{
		updatePos();

		//When close, jump to next node
		if (fabs(length(m_pos - m_targetNode)) <= m_speed)
		{
			m_pos = m_targetNode;
			m_atTargetNode = true;
		}
	}
}

void Enemy::draw(sf::RenderWindow* window)
{
	window->draw(m_shape);
}

sf::Vector2f Enemy::normalise(sf::Vector2f vec)
{
	return vec / length(vec);
}

float Enemy::length(sf::Vector2f vec)
{
	return sqrt(vec.x*vec.x + vec.y*vec.y);
}

void Enemy::updatePos()
{
	m_pos += m_dir * m_speed;
	m_shape.setPosition(m_pos.x - m_radius, m_pos.y - m_radius);
}



// Getters

sf::Vector2f Enemy::getPos()
{
	return m_pos;
}

bool Enemy::atTargetNode()
{
	return m_atTargetNode;
}

bool Enemy::atFinalNode()
{
	return m_atFinalNode;
}



// Setters

void Enemy::setTargetNode(sf::Vector2f target)
{
	m_targetNode = target;
	m_atTargetNode = false;

	//set new direction
	m_dir = normalise((m_targetNode - m_pos));
}

void Enemy::setAtFinalNode(bool val)
{
	m_atFinalNode = val;
}