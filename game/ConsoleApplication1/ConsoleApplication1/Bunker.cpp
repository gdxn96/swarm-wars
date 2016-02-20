#include "stdafx.h"
#include "Bunker.h"

Bunker::Bunker(float angle) : m_maxHealth(GameConstants::BUNKER_HEALTH), m_health(GameConstants::BUNKER_HEALTH), m_alive(true)
{
	float minAngle = angle - GameConstants::BUNKER_SIZE_WIDTH / 2;
	float maxAngle = angle + GameConstants::BUNKER_SIZE_WIDTH / 2;

	Vector2D topLeft = Vector2D(minAngle) * GameConstants::BUNKER_SIZE_OUTER;
	Vector2D topRight = Vector2D(maxAngle) * GameConstants::BUNKER_SIZE_OUTER;
	Vector2D bottomRight = Vector2D(maxAngle) * GameConstants::BUNKER_SIZE_INNER;
	Vector2D bottomLeft = Vector2D(minAngle) * GameConstants::BUNKER_SIZE_INNER;
	bunker.setSize(Vector2f(GameConstants::BUNKER_SIZE_HEIGHT, 60));
	bunker.setRotation(angle * 180 / GameConstants::PI);
	bunker.setPosition((GameConstants::WINDOW_CENTRE + bottomLeft+Vector2D(0,0)).toSFMLVector());
	bunker.setTexture(AssetLoader::getInstance()->findTextureByKey("bunker"));
	m_bounds.addPoint(GameConstants::WINDOW_CENTRE + topLeft);
	m_bounds.addPoint(GameConstants::WINDOW_CENTRE + topRight);
	m_bounds.addPoint(GameConstants::WINDOW_CENTRE + bottomRight);
	m_bounds.addPoint(GameConstants::WINDOW_CENTRE + bottomLeft);
	m_bounds.setBroadPhaseCircle(GameConstants::WINDOW_CENTRE, GameConstants::BUNKER_SIZE_OUTER);
	LightManager::getInstance()->AddLight("j",Vector2D(GameConstants::WINDOW_CENTRE + bottomLeft + Vector2D(0, 0)).toSFMLVector(),	sf::Vector2f(0.1f, 0.1f), sf::Color(255, 165, 0,255), Vector2D(0, 0), 45, nullptr, "bumpLight");
}

void Bunker::damageBunker(float damage)
{
	m_health -= damage;
	if (m_health <= 0)
	{
		m_alive = false;
	}
}

bool Bunker::isAlive()
{
	return m_alive;
}



void Bunker::draw(sf::RenderWindow & window)
{
	//at the moment it draws the collision bounds polygon, change the draw to whatever is appropriate here
	// not inside polygon class
	//m_bounds.draw(window, sf::Color(128, 64, 128, 255));
	window.draw(bunker);
}

Polygon2D& Bunker::getBounds()
{
	return m_bounds;
}