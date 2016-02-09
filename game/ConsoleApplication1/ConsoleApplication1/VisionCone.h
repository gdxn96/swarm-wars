#pragma once

#include "Vector2D.h"
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream>

class VisionCone
{
public:
	VisionCone();
	void update(Vector2D position, float minAngle, float maxAngle);
	void setRange(float range);
	void draw(sf::RenderWindow & window);

private:
	float m_range;
	float m_minAngle;
	float m_maxAngle;
	Vector2D m_position;

};


