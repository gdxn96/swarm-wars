#include "stdafx.h"
#include "Pylon.h"


Pylon::Pylon(float anglePosition, float distFromCentre) :
m_position(Vector2D(anglePosition) * distFromCentre + GameConstants::WINDOW_CENTRE),
m_alive(true)
{
}

Vector2D Pylon::getPosition()
{
	return m_position;
}

bool Pylon::getAlive()
{
	return m_alive;
}

void Pylon::draw(sf::RenderWindow& window)
{
	sf::CircleShape shape(10);
	shape.setOrigin(sf::Vector2f(10, 10));
	shape.setPosition(m_position.toSFMLVector());
	window.draw(shape);

	for (auto& point : m_spawnPoints)
	{
		point->draw(window);
	}
}

void Pylon::kill()
{
	m_alive = false;
}

void Pylon::addSpawnPoint(SpawnPoint* spawn)
{
	m_spawnPoints.push_back(spawn);
}

Vector2D Pylon::getSpawnPoint()
{
	return m_spawnPoints[rand() % m_spawnPoints.size()]->getPoint();
}