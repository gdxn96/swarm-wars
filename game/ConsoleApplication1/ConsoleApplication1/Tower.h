#pragma once
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp"
#include "Circle.h"
#include "GameConstants.h"
#include "Animation.h"
#include "AudioMgr.h"
class Tower
{
public:
	Tower();
	void draw(sf::RenderWindow & window);
	Circle& getInnerBounds();
	Circle& getOuterBounds();
	void damage(float damage);
	bool getAlive();
	void update(float dt);
	void playMoraleIndicator();

private:
	Circle m_outerBounds;
	Circle m_innerBounds;
	float m_health;
	const float m_maxHealth;
	Animation m_anim;
	vector<vector<std::string>> m_moraleSounds;

	float const SOUND_TRIGGER_INTERVAL;
	float m_soundTriggerInterval;
};


