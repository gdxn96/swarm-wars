#include "stdafx.h"
#include "Tower.h"
#include "LightManager.h"
#include "InputHandler.h"
Tower::Tower() 
:	m_innerBounds(Circle(GameConstants::WINDOW_CENTRE, GameConstants::TOWER_RADIUS / 2)),
	m_outerBounds(Circle(GameConstants::WINDOW_CENTRE, GameConstants::TOWER_RADIUS)),
	m_health(GameConstants::TOWER_HEALTH),
	m_maxHealth(GameConstants::TOWER_HEALTH),
	m_anim("towerAnimation", Vector2D(-11111,-11111)),
	m_moraleSounds({
		vector<char *>({ "fireatwill",  "outnumbered", "scream",  "warcry" }),//worst
		vector<char *>({ "gettingslaughtered", "gettobase", "lookoutbehind" }),//bad
		vector<char *>({ "pitchblack", "unreliablearachnids2", "unreliablearachnids", "holyshitambush" }),//ok
		vector<char *>({ "what", "sodark", "keepeyesopen", "bugscrawlinaround" }),//good
		vector<char *>({ "wherethehellbugs", "itsDark", "drop2", "drop" })// best
}),
SOUND_TRIGGER_INTERVAL(15.0f),
m_soundTriggerInterval(SOUND_TRIGGER_INTERVAL),
FLICKER_TRIGGER_INTERVAL(1),
m_flickerTriggerInterval(0.5f),
moraleBar(Vector2D(GameConstants::WINDOW_CENTRE.x - 100, 65), Vector2D(2, 2), GameConstants::TOWER_HEALTH, sf::Color(4, 254, 253, 255), sf::Color(17, 169, 169, 255)),
moraleText(">TROOP MORALE<", Vector2D(GameConstants::WINDOW_CENTRE.x-120, 50),255,0)
{
	int temp = 90;
	m_anim.setPosition(GameConstants::WINDOW_CENTRE + Vector2D(5, 0));
	m_light1 = new Light("j",
		(GameConstants::WINDOW_CENTRE + Vector2D(temp, -temp)),
		Vector2D(0.39f, 0.39f), sf::Color::White, Vector2D(0, 0), 45, "pointLight");
	LightManager::getInstance()->AddLight(m_light1);
	m_light2 = new Light("j",
		(GameConstants::WINDOW_CENTRE + Vector2D(temp, temp)),
		Vector2D(0.39f, 0.39f), sf::Color::White, Vector2D(0, 0), 135 , "pointLight");
	LightManager::getInstance()->AddLight(m_light2);
	m_light3 = new Light("j",
		(GameConstants::WINDOW_CENTRE + Vector2D(-temp, temp)),
		Vector2D(0.39f, 0.39f), sf::Color::White, Vector2D(0, 0), 135 + 90, "pointLight");
	LightManager::getInstance()->AddLight(m_light3);
	m_light4 = new Light("j",
		(GameConstants::WINDOW_CENTRE + Vector2D(-temp, -temp)),
		Vector2D(0.39f, 0.39f), sf::Color::White, Vector2D(0, 0), 135 +180, "pointLight");
	LightManager::getInstance()->AddLight(m_light4);
	moraleText.setColor(sf::Color(0, 191, 255, 255));
	m_anim.setFramesPerSecond(60);
	m_anim.SetLooping(true);
	m_anim.setRadius(GameConstants::TOWER_RADIUS + 60);
	int amount = 0;
}

void Tower::setBarPosition(Vector2D pos)
{
	barPosition = pos;
}
void Tower::setBarScale(Vector2D s)
{
	barScale = s;
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
	moraleBar.setPosition(barPosition);
	moraleBar.setScale(barScale);
	moraleText.update(dt);
	moraleText.setPosition(Vector2D(GameConstants::WINDOW_CENTRE.x-120, 30));
	m_soundTriggerInterval -= dt;
	m_flickerTriggerInterval -= dt;
	if (m_soundTriggerInterval <= 0)
	{
		playMoraleIndicator();
		m_soundTriggerInterval = SOUND_TRIGGER_INTERVAL;
	}

	if (m_flickerTriggerInterval <= 0)
	{
		if (swapAmount == -1)
		{
			swapAmount = 1;
			m_light1->setAlpha(100);
		}
		else
		{
			swapAmount = -1;
			m_light1->setAlpha(255);
		}
		m_flickerTriggerInterval = FLICKER_TRIGGER_INTERVAL;
	}
	InputHandler::getInstance()->setVibration(0.0f, 0.0f);
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
	InputHandler::getInstance()->setVibration(0.4f, 0.0f);

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