#pragma once

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "Vector2D.h"
#include "GameConstants.h"
using namespace sf;

class OrderPointer
{
private:
	//-------------
	// Pointer 
	//-------------
	Vector2D m_position;
	float m_radius;

	//angle from centre
	float m_angle;

public:
	OrderPointer();

	void update(float rad);

	void draw(RenderWindow & window);

	float getAngle();

	//normalizes a radian angle to be in the range 0-2PI
	float NormalizeAngle(float angle);
};