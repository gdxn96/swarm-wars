#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(BulletType type, Vector2D initPos, Vector2D direction, float speed) : m_velocity(direction * speed), m_dir(direction.Normalize()), m_speed(speed)
{
}

void Bullet::Update()
{
	m_velocity = m_dir * m_speed;
	m_position += m_velocity;
}