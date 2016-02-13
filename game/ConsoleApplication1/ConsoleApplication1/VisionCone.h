#pragma once

#include "Vector2D.h"
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream>
#include "Polygon.h"

class VisionCone
{
public:
	VisionCone();
	void update(Vector2D position, float minAngle, float maxAngle);
	void setRange(float range);
	void draw(sf::RenderWindow & window);
	Polygon2D& getRange();

private:
	float m_range;
	float m_minAngle;
	float m_maxAngle;
	Vector2D m_position;
	Polygon2D m_rangeSize;

};


