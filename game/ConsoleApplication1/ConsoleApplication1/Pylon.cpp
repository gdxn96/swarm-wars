#include "stdafx.h"
#include "Pylon.h"



Pylon::Pylon(float anglePosition, float distFromCentre) :
m_position(Vector2D(anglePosition) * distFromCentre + GameConstants::WINDOW_CENTRE),
m_alive(true),
m_anim("pylonAnimation", Vector2D(-1110, -1110))
{
	m_anim.setFramesPerSecond(60);
	m_anim.SetLooping(true);
	m_anim.setRadius(105);
	m_anim.setPosition(m_position); 
	m_anim.setRotation(anglePosition * 180 / GameConstants::PI);
	LightManager::getInstance()->AddLight("j",
		Vector2D(m_position).toSFMLVector(),
		sf::Vector2f(0.65f, 0.65f), sf::Color::White, Vector2D(0, 0), anglePosition * 180 / GameConstants::PI +90, nullptr, "spotLight");
	
}

Vector2D Pylon::getPosition()
{
	return m_position;
}

bool Pylon::getAlive()
{
	return m_alive;
}
void Pylon::update(float dt)
{
	m_anim.update(dt);
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
	m_anim.draw(window);
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