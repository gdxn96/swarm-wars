#include "stdafx.h"
#include "Bullet.h"
#include "GameConstants.h"
#include "LightManager.h"
#include "AudioMgr.h"

Bullet::Bullet(std::string parentId, Vector2D position, Vector2D direction, float speed, float radius, float killDistance, float damage, sf::Color color, string animName, std::string audioName)
:	m_position(position),
	m_initPosition(position),
	m_range(killDistance),
	m_speed(speed),
	m_radius(radius),
	m_direction(direction),
	m_bounds(Circle(position, radius)),
	m_alive(true),
	m_damage(damage),
	m_anim(animName, Vector2D(-1110, -1110)),
	m_parentId(parentId),
	m_light(new Light("bullet", m_position, Vector2D(0.29f, 0.29f), color, Vector2D(0, 0), 0, "spotLight"))
{
	m_anim.setFramesPerSecond(60);
	m_anim.SetLooping(true);
	m_anim.setRadius(m_radius + 50);
	//names plasmaAnimation//bulletAnimation//blueBulletAnimation
	//rgb(238,130,238)plasma// norma gold rgb(255,215,0)// blue rgb(0,191,255)
	
	LightManager::getInstance()->AddLight(m_light);
	AudioManager::instance()->PlayGameSound(audioName, false, 0.1f, m_position, 0);
	if (audioName == "pistol")
	{
		AudioManager::instance()->PlayGameSound("shell", false, 0.1f, m_position, 0);
	}
}

std::string Bullet::getParentId()
{
	return m_parentId;
}

float Bullet::getDamage()
{
	return m_damage;
}

void Bullet::Update(float dt)
{
	m_velocity = m_direction * m_speed * dt;
	m_position += m_velocity;
	m_bounds.setCentre(m_position);
	m_light->setPosition(m_position);
	m_anim.setPosition(m_position);
	m_anim.update(dt);
	m_anim.setRotation((std::atan2(m_direction.y, m_direction.x) - GameConstants::PI) * 180 / GameConstants::PI);
	
	if (Vector2D::Magnitude((m_position - m_initPosition)) > m_range)
	{	
		m_anim.setIsAlive(m_alive);
		kill();
	}
}
void Bullet::kill()
{
	m_alive = false;
	if (m_light != nullptr)
	m_light->setIsAlive(false);
	m_light = nullptr;
}
Circle& Bullet::getBounds()
{
	return m_bounds;
}

void Bullet::Draw(sf::RenderWindow &window)
{
	m_anim.draw(window);
}

bool Bullet::getAlive()
{
	return m_alive;
}
