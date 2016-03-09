#pragma once
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "Vector2D.h"
#include "GameConstants.h"
#include "WeaponFactory.h"
#include "Animation.h"
#include "AssetLoader.h"
#include "bar.h"
#include "WeaponUpgrade.h"
#include "Light.h"

enum class UNIT_STATE { MOVING, WAITING, FIRING };
enum class UNIT_TYPE { PLAYER, SNIPER, CQB, ASSAULT};

class Unit
{
public:
	Unit(std::string id);
	int playerColorIndex = 0;

	void update(float dt);
	void draw(sf::RenderWindow & window);

	// when the angle gets updated the player position needs to be updated, 
	// so logic is wrapped in this function
	void updateAngle(float angle);

	void fireWeapon();

	void changeState(UNIT_STATE);

	float getExperience();
	void addExperience(float experience);

	void setWeapon(Weapon weapon);

	UNIT_RANK& getRank();

	void setRank(UNIT_RANK rank);

	//simple setter
	void setTargetAngle(float targetAngle);

	void setDirectionAngle(float angle);

	Vector2D getPositionByAngle(float angle);

	//finds out whether clockwise/anticlockwise is the shortest path 
	// for two angles to meet, returns either 1 or -1
	int getDirectionToTarget();

	bool isPlayer();

	void setUnitType(UNIT_TYPE unitType);

	void setSelected(bool isSelected);

	float NormalizeAngle(float angle);

	//finds the radian angle between two radian values
	//not just a-b as multiple revolutions may mess up results
	float findAngleBetween(float a, float b);

	Polygon2D& getRangeCone();

	UNIT_STATE &getPreviousState();


	bool getSelected();
	Vector2D getPosition();

	std::string getId();
	void setXPBar(float);
	int maxRank = 100;
	void addCredits(int);
	int getCredits();
	void setWeaponActiveUI(bool _isActive);
	UNIT_TYPE getType();
	WeaponUpgrade * getWeaponUpgrade();
private:
	WeaponUpgrade m_weaponUpgradeUI;
	float m_positionAngle; // angle signifying position relative to walk radius
	float m_targetAngle; // angle signifying target pos relative to walk radius
	float m_radius; // radius of player
	float m_speed; // angular speed of player, rads/second
	const float PI;
	Animation m_anim;
	Animation m_selectAnimation;
	float m_directionAngle; //radian rotation of player "0 rads == (x1, y0)"
	Vector2D m_position;

	UNIT_STATE m_state;
	UNIT_STATE m_previousState;

	Weapon m_currentWeapon;
	UNIT_TYPE m_unitType;
	bool m_isSelected;
	bar m_xpBar;
	UNIT_RANK m_rank;
	float m_experience;
	std::string m_id;
	sf::RectangleShape rankImg;
	int credits;
	Light * m_light;
};

