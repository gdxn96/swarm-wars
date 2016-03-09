#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(std::string _name, float fov, float range, float damage, float bulletsPerSecond, 
	BulletType bullet, BulletFactory * bulletFactory) 

:	m_bulletFactory(bulletFactory), 
	m_bullet(bullet),
	m_fov(fov),
	m_range(range),
	m_damage(damage),
	m_dirAngle(0),
	m_fireRate(1.0f / bulletsPerSecond),
	m_timeToFire(m_fireRate),
	name(_name),
	m_bulletsPerSecond(bulletsPerSecond)
{

	m_visionCone.setRange(m_range);
}

void Weapon::draw(sf::RenderWindow & window)
{
	m_visionCone.draw(window);
}

void Weapon::update(Vector2D position, float dir, float dt)
{
	m_timeToFire -= dt;
	m_dirAngle = dir;
	m_position = position;

	float minAngle = m_dirAngle - m_fov / 2.0f;
	float maxAngle = m_dirAngle + m_fov / 2.0f;
	m_visionCone.update(m_position, minAngle, maxAngle);
}

Polygon2D& Weapon::getRange()
{
	return m_visionCone.getRange();
}
float Weapon::getRoF()
{
	return m_bulletsPerSecond;
}
float Weapon::getDamage()
{
	return m_damage;
}
string Weapon::getName()
{
	return name;
}
void Weapon::fire()
{
	if (m_timeToFire < 0)
	{
		m_timeToFire = m_fireRate;
		float minAngle = m_dirAngle - m_fov / 2.0f;
		float maxAngle = m_dirAngle + m_fov / 2.0f;
		Vector2D fireDirection = Vector2D(RandomFloat(minAngle, maxAngle));

		//fire
		m_bulletFactory->addBullet(m_parentId, m_bullet, m_position, fireDirection, m_range, m_damage);

	}
}

void Weapon::setParentId(std::string parent)
{
	m_parentId = parent;
}

