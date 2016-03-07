#pragma once
#include "Animation.h"
#include "Vector2D.h"
#include "SFML\Graphics.hpp"
#include "bar.h"
#include "PulsingText.h"
#include "Weapon.h"
#include "InputHandler.h"

class WeaponUpgrade
{
public:
	WeaponUpgrade(Vector2D _position, Vector2D _size);
	void update(float dt);
	void updateInput(float dt);
	void draw(sf::RenderWindow & window);
	void setPosition(Vector2D _postion);
	void setIsActive(bool _isActive);
	void setCurrentWeapon(Weapon *);
	void setRank(UNIT_RANK );
private:
	Vector2D m_position, m_offsetedPosition;
	float m_offsetHeight, m_offsetWidth, m_cellHeight, m_cellWidth;
	sf::RectangleShape m_topShape, m_bottomShape;
	sf::Color m_innerColor, m_outerColor;
	Animation m_topAnimation, m_botomAnimation, m_topButtonAnimation, m_bottomButtonAnimation;
	bar m_topDMGbar, m_topRoFBar, m_bottomDMGbar, m_bottomRoFBar;
	PulsingText m_weaponNameTop, m_weaponNameBottom;
	bool m_isActive = false;
	Weapon * m_currentWeapon;
	void setWeaponStats();
	UNIT_RANK  m_rank;
	string name;
};

