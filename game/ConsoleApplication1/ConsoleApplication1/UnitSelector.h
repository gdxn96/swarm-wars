#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2D.h"
#include "Animation.h"
#include "AssetLoader.h"
#include "GameConstants.h"
#include "LightManager.h"
#include "Unit.h"
#include "PulsingText.h"
class UnitSelector
{
public:
	UnitSelector();
	~UnitSelector();
	void update(float dt);
	void draw(sf::RenderWindow &);
	void toggleSelected();
	void updateUnits(vector<Unit *> _m_currentUnits);
	void setPosition(Vector2D);
private:
	vector<Unit *> m_currentUnits;
	sf::RectangleShape UnitOne, UnitTwo, UnitThree, UnitFour, Display;
	int m_currentSelected = 1;
	Vector2D m_position, UnitSizeSmall, UnitSizeLarge, DisplaySize;
	sf::RectangleShape bg;
	PulsingText number;
	Vector2D position;
};

