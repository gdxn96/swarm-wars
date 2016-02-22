#include "stdafx.h"
#include "PhysicsObject.h"

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
	m_radius(50),
	m_mass(1.15f),
	m_onScreen(false),
	m_gravity(1.5f),
	m_restitution(0.75f),
	m_airMass(0.207f),
	DEGREE(45),
	m_rotationDegrees(0)
{
	m_bounds = Vector2D(GameConstants::WINDOW_SIZE.x, GameConstants::WINDOW_SIZE.y / 3 * 2);
	m_circle = CircleShape(m_radius);
	m_circle.setPosition(m_pos.toSFMLVector());
	m_circle.setOrigin(sf::Vector2f(m_radius, m_radius));
	m_circle.setTexture(AssetLoader::getInstance()->findTextureByKey("starLight"), true);

	m_size = (GameConstants::PI * m_radius * m_radius) / 40000.0f;
	m_drag = pow((m_mass / (m_mass + m_airMass)), m_size);
}

void PhysicsObject::changeRotation()
{
	m_rotationDirection = !m_rotationDirection;
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
		m_circle.setPosition(m_pos.toSFMLVector());

		if (m_onScreen)
		{
			this->bounce();
		}

		if (m_rotationDirection)
		{
			m_rotationDegrees -= 70 * dt;
		}
		else
		{
			m_rotationDegrees += 70 * dt;
		}
	}

	
	
}

void PhysicsObject::draw(sf::RenderWindow& window)
{
	m_circle.setRotation(m_rotationDegrees);
	window.draw(m_circle);
}


void PhysicsObject::bounce()
{
	
	if (m_pos.x - m_radius <= 0)
	{
		changeRotation();
		m_pos.x = m_radius;
		m_direction.x *= -1 * m_restitution;		
	}
	else if (m_pos.x + m_radius >= m_bounds.x)
	{
		changeRotation();
		m_pos.x = m_bounds.x - m_radius;
		m_direction.x *= -1 * m_restitution;
	}

	if (m_pos.y - m_radius <= 0)
	{
		changeRotation();
		m_pos.y = m_radius;
		m_direction.y *= -1 * m_restitution;
	}
	else if (m_pos.y + m_radius >= m_bounds.y)
	{
		m_pos.y = m_bounds.y - m_radius;
		m_direction.y *= -1 * m_restitution;
	}
	m_circle.setPosition(m_pos.toSFMLVector());
}