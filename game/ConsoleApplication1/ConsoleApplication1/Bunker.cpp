#include "stdafx.h"
#include "Bunker.h"

Bunker::Bunker(float angle) : m_maxHealth(GameConstants::BUNKER_HEALTH),
FLICKER_TRIGGER_INTERVAL(1),
m_flickerTriggerInterval(0.5f), 
m_health(GameConstants::BUNKER_HEALTH), m_alive(true)
{
	float minAngle = angle - GameConstants::BUNKER_SIZE_WIDTH / 2;
	float maxAngle = angle + GameConstants::BUNKER_SIZE_WIDTH / 2;

	Vector2D topLeft = Vector2D(minAngle) * GameConstants::BUNKER_SIZE_OUTER;
	Vector2D topRight = Vector2D(maxAngle) * GameConstants::BUNKER_SIZE_OUTER;
	Vector2D bottomRight = Vector2D(maxAngle) * GameConstants::BUNKER_SIZE_INNER;
	Vector2D bottomLeft = Vector2D(minAngle) * GameConstants::BUNKER_SIZE_INNER;

	Vector2D centerPoint = Vector2D(angle) * GameConstants::BUNKER_SIZE_OUTER;
	bunker.setSize(Vector2f(GameConstants::BUNKER_SIZE_HEIGHT, 60));
	bunker.setRotation(angle * 180 / GameConstants::PI);
	bunker.setPosition((GameConstants::WINDOW_CENTRE + bottomLeft+Vector2D(0,0)).toSFMLVector());
	bunker.setTexture(AssetLoader::getInstance()->findTextureByKey("bunker"));
	m_bounds.addPoint(GameConstants::WINDOW_CENTRE + topLeft);
	m_bounds.addPoint(GameConstants::WINDOW_CENTRE + topRight);
	m_bounds.addPoint(GameConstants::WINDOW_CENTRE + bottomRight);
	m_bounds.addPoint(GameConstants::WINDOW_CENTRE + bottomLeft);
	m_bounds.setBroadPhaseCircle(GameConstants::WINDOW_CENTRE, GameConstants::BUNKER_SIZE_OUTER);
	m_light = new Light("j", Vector2D(GameConstants::WINDOW_CENTRE + centerPoint + Vector2D(0, 0)), Vector2D(0.1f, 0.3f), sf::Color(127, 255, 0 ,255), Vector2D(0, 0), angle * 180 / GameConstants::PI, "bumpLight");
	LightManager::getInstance()->AddLight(m_light);
}

void Bunker::damageBunker(float damage)
{
	m_health -= damage;
	if (m_health <= 0)
	{
		m_alive = false;
		if (m_light != nullptr)
		{
			m_light->setIsAlive(false);
		}
		m_light = nullptr;
	}
	if (m_health <= GameConstants::BUNKER_HEALTH / 1.5f && m_health > GameConstants::BUNKER_HEALTH/2)
	{
		m_light->setColor(sf::Color(255, 165, 0, 255));
	}
	else if (m_health <= GameConstants::BUNKER_HEALTH / 2 && m_health > GameConstants::BUNKER_HEALTH / 2.5f)
	{
		m_light->setColor(sf::Color::Red);
	}
}

void Bunker::update(float dt)
{
	m_flickerTriggerInterval -= dt;
	if (m_health <= GameConstants::BUNKER_HEALTH / 2.5f && m_health > 0)
	{
		if (m_flickerTriggerInterval <= 0)
		{
			if (swapAmount == -1)
			{
				swapAmount = 1;
				m_light->setAlpha(100);
			}
			else
			{
				swapAmount = -1;
				m_light->setAlpha(255);
			}
			m_flickerTriggerInterval = FLICKER_TRIGGER_INTERVAL;
		}
	}
}

bool Bunker::isAlive()
{
	return m_alive;
}

void Bunker::draw(sf::RenderWindow & window)
{
	window.draw(bunker);
}

Polygon2D& Bunker::getBounds()
{
	return m_bounds;
}

Bunker::~Bunker()
{
	if (m_light != nullptr)
	{
		m_light->setIsAlive(false);
	}
	m_light = nullptr;
}