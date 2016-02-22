#pragma once

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "Vector2D.h"

using namespace sf;



class Character
{
private:
	//-------------
	//Constants
	//-------------
	const float M_PI;
	const float DEGREES;

	//-------------
	//Other
	//-------------
	//Centre of tower
	Vector2D m_centre;

	//-------------
	//Character
	//-------------
	bool m_move;
	Vector2D m_pos;
	float m_radius;
	float m_speed;
	//angle from centre
	float m_angle;
	CircleShape m_shape;

	//-------------
	//Target
	//-------------
	Vector2D m_tPos;
	float m_tRadius;
	float m_tAngle;
	CircleShape m_target;

public:
	Character(float, float, Color, Color, Vector2D);
	void update();
	void updatePos();
	void draw(RenderWindow*);
	void resetAngle();	//Reset if above 360 or below 0 degrees
	void findDirectionToTarget(float);
	float findAngleBetween();	//Between target and character angle

	// Get methods

	// Set methods
	void setTargetAngle(float, float);
	void setMove(bool);
};