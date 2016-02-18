#pragma once
#include "Polygon.h"
#include "Unit.h"
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "WeaponFactory.h"

class UpgradeElement
{
public:
	/*UpgradeElement(Unit* unit);
	UpgradeElement(Unit* unit, WeaponType weapon);
	void update(float dt);
	void draw(sf::RenderWindow&window);*/

private:
	Polygon2D miniIcon;
	Polygon2D largeIcon;
};

