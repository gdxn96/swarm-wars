#include "stdafx.h"
#include "Bullet.h"
#include "GameConstants.h"
#include "LightManager.h"
#include "AudioMgr.h"

Bullet::Bullet(Vector2D position, Vector2D direction, float speed, float radius, float killDistance, float damage)
:	m_position(position),
	m_initPosition(position),
	m_range(killDistance),
	m_speed(speed),
	m_radius(radius),
	m_direction(direction),
	m_bounds(Circle(position, radius)),
	m_alive(true),
	m_damage(damage),
	m_anim("bulletAnimation", Vector2D(0, 0))
{
	m_anim.setFramesPerSecond(60);
	m_anim.SetLooping(true);
	m_anim.setRadius(m_radius + 50);
	//names plasmaAnimation//bulletAnimation//blueBulletAnimation
	//rgb(238,130,238)plasma// norma gold rgb(255,215,0)// blue rgb(0,191,255)
	LightManager::getInstance()->AddLight("bullet", m_position.toSFMLVector(), sf::Vector2f(0.19f, 0.19f), sf::Color(255, 215, 0, 205), m_direction * m_speed,0, this,"starLight");
	AudioManager::instance()->PlayGameSound("zum", false, 0.1f, m_position, 0);
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

	m_anim.update();
	m_anim.setRotation((std::atan2(m_direction.y, m_direction.x) - GameConstants::PI) * 180 / GameConstants::PI);
	m_anim.setPosition(m_position);
	if (Vector2D::Magnitude((m_position - m_initPosition)) > m_range)
	{
		m_alive = false;
		m_anim.setIsAlive(m_alive);
	}
}

Circle& Bullet::getBounds()
{
	return m_bounds;
}

void Bullet::Draw(sf::RenderWindow &window)
{
	
	//m_bounds.draw(window, sf::Color::Green);
	m_anim.draw(window);
}

bool Bullet::getAlive()
{
	return m_alive;
}
