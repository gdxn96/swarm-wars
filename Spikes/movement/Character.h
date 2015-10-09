#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Constants.h"
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 




class Character
{
private:
	int m_type;
	sf::Vector2f m_pos;
	float m_radius;
	float m_angle;
	float m_targAngle;		// when moving to location
	float m_speed;
	sf::Color m_color;
	sf::CircleShape m_shape;

public:
	Character();
	Character(int, float);
	void update();
	void draw(sf::RenderWindow&);
};


#endif