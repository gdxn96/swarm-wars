#pragma once

#ifndef POINTER_H
#define POINTER_H

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 

using namespace sf;




class Pointer
{
private:
	Vector2f m_centre;
	Vector2f m_pos;
	float m_radius;
	float m_angle;
	float m_speed;
	Color m_color;
	CircleShape m_shape; 

public:
	Pointer(float, float, Color, Vector2f);
	void move();
	void draw(RenderWindow&);
	void resetAngle();
	void updatePos();
	const Vector2f getPos();
	void setSpeed(float);

	float getAngle();
};


#endif