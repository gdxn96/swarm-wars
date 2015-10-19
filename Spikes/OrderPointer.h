#pragma once

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "Vector2D.h"

using namespace sf;




class OrderPointer
{
private:
	//-------------
	// Constants
	//-------------
	const float M_PI;
	const float DEGREES; 

	//-------------
	// Other
	//-------------
	// centre of tower
	Vector2D m_centre;

	//-------------
	// Pointer 
	//-------------
	Vector2D m_pos;
	float m_radius;
	//angle from centre
	float m_angle;
	float m_speed;
	float m_minSpeed;
	float m_maxSpeed;
	//value used to increase/decrease speed
	float m_interval;
	Color m_color;
	CircleShape m_shape; 

public:
	OrderPointer(float, float, Color, Vector2D);
	void update();
	void move();
	void draw(RenderWindow*);
	void resetAngle();	//Reset if above 360 or below 0 degrees
	void updatePos();
	void changePointerSpeed();
	const Vector2D getPos();
	void setSpeed(float);
	float getAngle();
};