#include "stdafx.h"
#include "Pylon.h"



Pylon::Pylon(float anglePosition, float distFromCentre) :
m_position(Vector2D(anglePosition) * distFromCentre + GameConstants::WINDOW_CENTRE),
m_alive(true),
m_anim("pylonAnimation", Vector2D(-1110, -1110))
{
	m_anim.setFramesPerSecond(60);
	m_anim.SetLooping(true);
	m_anim.setSize(110/1.1f, 90/1.1f);
	m_anim.setPosition(m_position); 
	m_anim.setRotation(anglePosition * 180 / GameConstants::PI);
	m_light = new Light("j", m_position, Vector2D(0.7f, 0.7f), sf::Color(219, 112, 147, 100), Vector2D(0, 0), anglePosition * 180 / GameConstants::PI + 90, "spotLight");
	LightManager::getInstance()->AddLight(m_light);
	
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
	if (!m_alive)
	{
		m_anim.setFramesPerSecond(120);
		m_anim.changeAnimation("pylonExplosion");
	}
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
	m_light->setColor(sf::Color(0, 191, 255, 255));
	m_light->setScale(Vector2D(1.5f,1.5f));

	
}

void Pylon::addSpawnPoint(SpawnPoint* spawn)
{
	m_spawnPoints.push_back(spawn);
}

Vector2D Pylon::getSpawnPoint()
{
	return m_spawnPoints[rand() % m_spawnPoints.size()]->getPoint();
}