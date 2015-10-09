#pragma once

#ifndef POINTER_H
#define POINTER_H

#include "Constants.h"
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 




class Pointer
{
private:
	sf::Vector2f m_pos;
	float m_radius;
	float m_angle;
	float m_speed;
	sf::Color m_color;
	sf::CircleShape m_shape; 

public:
	Pointer(float, float, sf::Color);
	void move(float);
	void draw(sf::RenderWindow&);
	void resetAngle();
	void updatePos();
	const sf::Vector2f getPos();
	void setSpeed(float);
};


#endif