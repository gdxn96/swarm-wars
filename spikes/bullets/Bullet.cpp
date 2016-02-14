#include "stdafx.h"
#include "Bullet.h"

#include <iostream>

Bullet::Bullet()
{
}

Bullet::Bullet(BulletType type, Vector2D initPos, Vector2D direction, float speed) : 
m_type(type), m_position(initPos), m_velocity(direction * speed), m_dir(direction.Normalize()), m_speed(speed)
{
}

void Bullet::Update()
{
	m_velocity = m_dir * m_speed;
	m_position += m_velocity;
}

void Bullet::Draw(sf::RenderWindow *window)
{
	if (m_type == BulletType::CIRCLE)
	{
		sf::CircleShape myBullet = sf::CircleShape(5);
		myBullet.setPosition(m_position.toSFMLVector() - Vector2D(5, 5).toSFMLVector());
		window->draw(myBullet);
	}
	else if (m_type == BulletType::SQUARE)
	{
		sf::CircleShape myBullet = sf::CircleShape(5, 4);
		myBullet.setPosition(m_position.toSFMLVector() - Vector2D(5, 5).toSFMLVector());
		window->draw(myBullet);
	}
		
	
}