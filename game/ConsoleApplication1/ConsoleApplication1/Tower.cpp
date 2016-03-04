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
		vector<char *>({ "fireatwill",  "outnumbered", "scream",  "warcry" }),//worst
		vector<char *>({ "gettingslaughtered", "gettobase", "lookoutbehind" }),//bad
		vector<char *>({ "pitchblack", "unreliablearachnids2", "unreliablearachnids", "holyshitambush" }),//ok
		vector<char *>({ "what", "sodark", "keepeyesopen", "bugscrawlinaround" }),//good
		vector<char *>({ "wherethehellbugs", "itsDark", "drop2", "drop" })// best
}),
SOUND_TRIGGER_INTERVAL(5.0f),
m_soundTriggerInterval(5.0f),
moraleBar(Vector2D(GameConstants::WINDOW_CENTRE.x-100, 65), Vector2D(2,2),GameConstants::TOWER_HEALTH),
moraleText(">TROOP MORALE<", Vector2D(GameConstants::WINDOW_CENTRE.x-120, 50),255,0,"stoNe.tff")
{
	LightManager::getInstance()->AddLight("j",
		(Vector2D(GameConstants::WINDOW_CENTRE).toSFMLVector()),
		sf::Vector2f(0.39f, 0.39f), sf::Color::White, Vector2D(0, 0), 135, nullptr, "spotLight");
	LightManager::getInstance()->AddLight("flicker",
		(Vector2D(GameConstants::WINDOW_CENTRE).toSFMLVector()),
		sf::Vector2f(0.39f, 0.39f), sf::Color::White, Vector2D(0, 0), 225, nullptr, "spotLight");
	LightManager::getInstance()->AddLight("flicker",
		(Vector2D(GameConstants::WINDOW_CENTRE).toSFMLVector()),
		sf::Vector2f(0.39f, 0.39f), sf::Color::White, Vector2D(0, 0), 45, nullptr, "spotLight");
	LightManager::getInstance()->AddLight("j",
		(Vector2D(GameConstants::WINDOW_CENTRE).toSFMLVector()),
		sf::Vector2f(0.39f, 0.39f), sf::Color::White, Vector2D(0, 0), -45, nullptr, "spotLight");
	moraleText.setColor(sf::Color(0, 191, 255, 255));
	m_anim.setFramesPerSecond(60);
	m_anim.SetLooping(true);
	m_anim.setRadius(GameConstants::TOWER_RADIUS + 60);
	int amount = 0;
	
}

void Tower::draw(sf::RenderWindow & window)
{
	
	//m_outerBounds.draw(window, sf::Color::Magenta);
	m_anim.draw(window);
	moraleBar.draw(window);
	moraleText.draw(window);
	moraleText.setText(">TROOP MORALE<");
	
}

void Tower::update(float dt)
{
	m_anim.update(dt);
	moraleBar.update();
	moraleText.update(dt);
	moraleText.setPosition(Vector2D(GameConstants::WINDOW_CENTRE.x-120, 30));
	m_soundTriggerInterval -= dt;

	if (m_soundTriggerInterval <= 0)
	{
		playMoraleIndicator();
		m_soundTriggerInterval = SOUND_TRIGGER_INTERVAL;
		
	}
}

void Tower::playMoraleIndicator()
{
	float moralePercentage = (m_health / m_maxHealth * 100) - 0.1f;
	int moraleIndex = moralePercentage / 20;

	if (m_moraleSounds.size() == 5 && m_moraleSounds[moralePercentage / 20].size() > 0)
	{
		char * soundKey = m_moraleSounds[moralePercentage / 20][rand() % m_moraleSounds[moralePercentage / 20].size()];
		AudioManager::instance()->PlayGameSound(soundKey, false, 1, GameConstants::WINDOW_CENTRE,0);
	}
}

void Tower::damage(float damage)
{
	m_health -= damage;
	moraleBar.setBarAmount(damage);
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