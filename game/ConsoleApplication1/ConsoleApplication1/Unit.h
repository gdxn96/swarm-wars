#pragma once
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "Vector2D.h"
#include "GameConstants.h"
#include "VisionCone.h"
#include "WeaponFactory.h"

enum class UNIT_STATE { MOVING, WAITING, FIRING };
class Unit
{
public:
	Unit();
	void update(float dt);
	void draw(sf::RenderWindow & window);

	// when the angle gets updated the player position needs to be updated, 
	// so logic is wrapped in this function
	void updateAngle(float angle);

	void fireWeapon();

	void changeState(UNIT_STATE);

	//simple setter
	void setTargetAngle(float targetAngle);

	Vector2D getPositionByAngle(float angle);

	//finds out whether clockwise/anticlockwise is the shortest path 
	// for two angles to meet, returns either 1 or -1
	int getDirectionToTarget();

	float NormalizeAngle(float angle);

	//finds the radian angle between two radian values
	//not just a-b as multiple revolutions may mess up results
	float findAngleBetween(float a, float b);

private:
	float m_positionAngle; // angle signifying position relative to walk radius
	float m_targetAngle; // angle signifying target pos relative to walk radius
	float m_radius; // radius of player
	float m_speed; // angular speed of player, rads/second
	const float PI;

	float m_directionAngle; //radian rotation of player "0 rads == (x1, y0)"
	Vector2D m_position;
	UNIT_STATE m_state;
	Weapon m_currentWeapon;

};

