#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 

using namespace sf;



class Character
{
private:
	//Character
	bool m_move;
	Vector2f m_centre;
	Vector2f m_pos;
	float m_radius;
	float m_speed;
	float m_angle;
	CircleShape m_shape;

	//Target
	Vector2f m_targetPos; 
	float m_targetRadius;
	float m_targetAngle;
	CircleShape m_target;

public:
	Character();
	Character(float, float, Color, Color, Vector2f);
	void update();
	void draw(RenderWindow&);
	void resetAngles();
	float findAngleBetween();

	// Get methods

	// Set methods
	void setTargetAngle(float, float);
	void setMove(bool);
};


#endif