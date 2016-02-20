#pragma once
#include "Polygon.h"
#include "Unit.h"
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "WeaponFactory.h"
#include "InputHandler.h"

class UpgradeElement
{
public:
	UpgradeElement(Unit * unit); // default no upgrade
	UpgradeElement(Unit* unit, WeaponType weapon, string uiElementKey); // regular upgrade, show weapon, don't dissapear until killed or new upgrade is selected
	void update(float dt);
	void draw(sf::RenderWindow& window);
	Unit* getParentUnit();
	void accept();
	bool isAlive();
	void kill();



private:
	Polygon2D m_icon;

	Unit* m_parentUnit;
	bool m_alive;
	WeaponType m_weaponType;
	string m_key;
	

	
};

