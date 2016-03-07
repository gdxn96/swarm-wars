#include "stdafx.h"
#include "PhysicsObject.h"
#include "AssetLoader.h"
//////////////////
// PHYSICS USED
/////////////////
// 1. Projectile Motion
// 2. Gravity
// 3. Elastic collisions
// 4. Friction
// 5. Air Resistance

PhysicsObject::PhysicsObject(Vector2D position, float angle, float speed) :
	m_pos(position),
	m_direction(Vector2D(angle)),
	m_speed(speed),
	m_minSpeed(0.02f),
	m_radius(20),
	m_mass(1.15f),
	m_onScreen(false),
	m_gravity(0.5f),
	m_restitution(0.75f),
	m_airMass(0.207f),
	m_anim("exp", Vector2D(-1100,-1000))
{
	m_bounds = Vector2D(GameConstants::WINDOW_SIZE.x, GameConstants::WINDOW_SIZE.y / 3 * 2);

	m_circle = Circle(m_pos, m_radius);
	m_size = (GameConstants::PI * m_radius * m_radius) / 8000.0f;
	m_drag = pow((m_mass / (m_mass + m_airMass)), m_size);
	c.setTexture(AssetLoader::getInstance()->findTextureByKey("grenade"));
	c.setRadius(m_radius);
	c.setPosition(m_pos.toSFMLVector());
	m_anim.setFramesPerSecond(30);
	m_anim.SetLooping(true);
	m_anim.setDoOnce(true);
}

void PhysicsObject::update(float dt)
{
	if (!m_onScreen && (m_pos.x - m_radius > 0))
	{
		m_onScreen = true;
	}

	if (Vector2D::Magnitude(m_direction) > m_minSpeed)
	{
		m_direction.y += (m_gravity * dt);			
		m_direction = m_direction * m_drag;			
		m_pos += (m_direction * m_speed * dt);
		m_circle.setCentre(m_pos);

		if (m_onScreen)
		{
			this->bounce();
			c.rotate(m_direction.Magnitude()*dt*150);
			
		}
		one = true;
	}
	else
	{
		one = false;
		m_anim.setPosition(m_pos);
		m_anim.update(dt);
		
	}
	c.setPosition(m_pos.toSFMLVector());
	
	//cout << "speed" << m_direction.x << endl;
}

void PhysicsObject::draw(sf::RenderWindow& window)
{
	m_circle.draw(window);
	if (one)
	{
		window.draw(c);
	}
	else
	{
		m_anim.draw(window);
	}
}


void PhysicsObject::bounce()
{
	if (m_pos.x - m_radius <= 0)
	{
		m_pos.x = m_radius;
		m_direction.x *= -1 * m_restitution;		
	}
	else if (m_pos.x + m_radius >= m_bounds.x)
	{
		m_pos.x = m_bounds.x - m_radius;
		m_direction.x *= -1 * m_restitution;
	}

	if (m_pos.y - m_radius <= 0)
	{
		m_pos.y = m_radius;
		m_direction.y *= -1 * m_restitution;
	}
	else if (m_pos.y + m_radius >= m_bounds.y)
	{
		m_pos.y = m_bounds.y - m_radius;
		m_direction.y *= -1 * m_restitution;
	}

	m_circle.setCentre(m_pos);
}