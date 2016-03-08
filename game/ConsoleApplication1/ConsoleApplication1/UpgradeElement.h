#pragma once
#include "Polygon.h"
#include "Unit.h"
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "WeaponFactory.h"
#include "InputHandler.h"
#include "Animation.h"
#include "PulsingText.h"

class UpgradeElement
{
public:
	UpgradeElement(Unit * unit); // default no upgrade
	UpgradeElement(Unit* unit, WeaponType weapon, string uiElementKey); // regular upgrade, show weapon, don't dissapear until killed or new upgrade is selected
	void update(float dt);
	void updateInput();
	void draw(sf::RenderWindow& window);
	Unit* getParentUnit();
	void accept();
	bool isAlive();
	void kill();



private:
	Polygon2D m_icon;
	void changeUI(string name,Vector2D position,Vector2D size);
	Unit* m_parentUnit;
	bool m_alive;
	WeaponType m_weaponType;
	string m_key;
	void animationInit();
	Animation m_anim,m_bgAnim;
	sf::RectangleShape bg;
	PulsingText UIText, dmg, fireRate, Name;
	sf::Text a;
	sf::Font f;
};

