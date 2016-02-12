#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(Vector2D position, Vector2D direction, float speed, float radius, float killDistance)
:	m_position(position),
	m_initPosition(position),
	m_range(killDistance),
	m_speed(speed),
	m_radius(radius),
	m_direction(direction),
	m_alive(true)
{
}

void Bullet::Update(float dt)
{
	m_velocity = m_direction * m_speed * dt;
	m_position += m_velocity;

	if (Vector2D::Magnitude((m_position - m_initPosition)) > m_range)
	{
		m_alive = false;
	}
}

void Bullet::Draw(sf::RenderWindow &window)
{
	sf::CircleShape myBullet = sf::CircleShape(m_radius);
	myBullet.setPosition(m_position.toSFMLVector() - Vector2D(m_radius, m_radius).toSFMLVector());
	myBullet.setFillColor(sf::Color::Green);
	window.draw(myBullet);
}

bool Bullet::getAlive()
{
	return m_alive;
}
