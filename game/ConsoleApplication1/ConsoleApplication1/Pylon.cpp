#include "stdafx.h"
#include "Pylon.h"


Pylon::Pylon(Vector2D position) :
	m_pos(position),
	m_radius(5)
{
	m_shape = sf::CircleShape(m_radius);
	m_shape.setPosition(m_pos.toSFMLVector());
	m_shape.setOrigin(m_radius / 2, m_radius / 2);
	m_shape.setFillColor(sf::Color::White);
}

void Pylon::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void Pylon::addSpawnPoint(SpawnPoint* spawn)
{
	m_spawns.push_back(spawn);
}

std::vector<SpawnPoint*> Pylon::getSpawns()
{
	return m_spawns;
}