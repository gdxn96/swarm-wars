#pragma once
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "Vector2D.h"
#include "GameConstants.h"
#include "VisionCone.h"

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
	float m_angle;
	float m_targetAngle;
	float m_radius;
	float m_speed;
	const float PI;

	float m_dirAngle;
	Vector2D m_position;
	UNIT_STATE m_state;

};

