#include "stdafx.h"
#include "Tower.h"
#include "LightManager.h"
Tower::Tower() 
:	m_innerBounds(Circle(GameConstants::WINDOW_CENTRE, GameConstants::TOWER_RADIUS / 2)),
	m_outerBounds(Circle(GameConstants::WINDOW_CENTRE, GameConstants::TOWER_RADIUS)),
	m_health(GameConstants::TOWER_HEALTH),
	m_maxHealth(GameConstants::TOWER_HEALTH),
	m_anim("towerAnimation", GameConstants::WINDOW_CENTRE + Vector2D(5,0)),
	m_moraleSounds({
		{},//worst
		{},//bad
		{},//ok
		{},//good
		{}// best
}),
SOUND_TRIGGER_INTERVAL(1.0f),
m_soundTriggerInterval(1.0f)
{
	m_anim.setFramesPerSecond(60);
	m_anim.SetLooping(true);
	m_anim.setRadius(GameConstants::TOWER_RADIUS + 60);
	int amount = 120;
	LightManager::getInstance()->AddLight("j",
		(Vector2D(GameConstants::WINDOW_CENTRE + Vector2D(amount, amount)).toSFMLVector()),
		sf::Vector2f(1, 1), sf::Color::White, Vector2D(0, 0),135, nullptr, "pointLight");
	LightManager::getInstance()->AddLight("flicker",
		(Vector2D(GameConstants::WINDOW_CENTRE + Vector2D(-amount, amount)).toSFMLVector()),
		sf::Vector2f(1, 1), sf::Color::White, Vector2D(0, 0), 225, nullptr, "pointLight");
	LightManager::getInstance()->AddLight("flicker",
		(Vector2D(GameConstants::WINDOW_CENTRE + Vector2D(amount, -amount)).toSFMLVector()),
		sf::Vector2f(1, 1), sf::Color::White, Vector2D(0, 0), 45, nullptr, "pointLight");
	LightManager::getInstance()->AddLight("j",
		(Vector2D(GameConstants::WINDOW_CENTRE + Vector2D(-amount, -amount)).toSFMLVector()),
		sf::Vector2f(1, 1), sf::Color::White, Vector2D(0, 0), -45, nullptr, "pointLight");
}

void Tower::draw(sf::RenderWindow & window)
{
	m_anim.update();
	//m_outerBounds.draw(window, sf::Color::Magenta);
	m_anim.draw(window);
}

void Tower::update(float dt)
{
	m_soundTriggerInterval -= dt;

	if (m_soundTriggerInterval <= 0)
	{
		m_soundTriggerInterval = SOUND_TRIGGER_INTERVAL;
		playMoraleIndicator();
	}
}

void Tower::playMoraleIndicator()
{
	float moralePercentage = (m_health / m_maxHealth * 100) - 0.1f;
	int moraleIndex = moralePercentage / 20;

	if (m_moraleSounds.size() == 5 && m_moraleSounds[moraleIndex].size() > 0)
	{
		std::string soundKey = m_moraleSounds[moraleIndex][rand() % m_moraleSounds[moraleIndex].size()];
		AudioManager::instance()->PlayGameSound(soundKey, false, 100, m_innerBounds.getCentre(), 1);
	}
}

void Tower::damage(float damage)
{
	m_health -= damage;
}

bool Tower::getAlive()
{
	return m_health > 0;
}

Circle& Tower::getInnerBounds()
{
	return m_innerBounds;
}

Circle& Tower::getOuterBounds()
{
	return m_outerBounds;
}