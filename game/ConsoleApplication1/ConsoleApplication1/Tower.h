#pragma once
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp"
#include "Circle.h"
#include "GameConstants.h"
#include "Animation.h"
#include "AudioMgr.h"
#include "bar.h"
#include "PulsingText.h"
#include "Light.h"
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
	void setBarPosition(Vector2D);
	void setBarScale(Vector2D);
private:
	void playMoraleIndicator();
	Circle m_outerBounds;
	Circle m_innerBounds;
	float m_health;
	const float m_maxHealth;
	Animation m_anim;
	const vector<vector<char *>> m_moraleSounds;

	float const SOUND_TRIGGER_INTERVAL;
	float m_soundTriggerInterval;

	float const FLICKER_TRIGGER_INTERVAL;
	float m_flickerTriggerInterval;
	int swapAmount = 1;
	bar moraleBar;
	PulsingText moraleText;
	Light * m_light1,* m_light2,* m_light3, * m_light4;
	Vector2D barPosition;
	Vector2D barScale;
};


