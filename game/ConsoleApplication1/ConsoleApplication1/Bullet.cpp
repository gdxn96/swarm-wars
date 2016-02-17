#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(Vector2D position, Vector2D direction, float speed, float radius, float killDistance, float damage)
:	m_position(position),
	m_initPosition(position),
	m_range(killDistance),
	m_speed(speed),
	m_radius(radius),
	m_direction(direction),
	m_alive(true),
	m_bounds(Circle(position, radius)),
	m_damage(damage)
{
}

float Bullet::getDamage()
{
	return m_damage;
}

void Bullet::kill()
{
	m_alive = false;
}

void Bullet::Update(float dt)
{
	m_velocity = m_direction * m_speed * dt;
	m_position += m_velocity;
	m_bounds.setCentre(m_position);

	if (Vector2D::Magnitude((m_position - m_initPosition)) > m_range)
	{
		m_alive = false;
	}
}

Circle& Bullet::getBounds()
{
	return m_bounds;
}

void Bullet::Draw(sf::RenderWindow &window)
{
	m_bounds.draw(window, sf::Color::Green);
}

bool Bullet::getAlive()
{
	return m_alive;
}
