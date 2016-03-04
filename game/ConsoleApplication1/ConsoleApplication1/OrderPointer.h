#pragma once

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "Vector2D.h"
#include "GameConstants.h"
#include "Animation.h"
using namespace sf;

class OrderPointer
{
private:
	Vector2D m_position;
	float m_radius;

	//angle from centre
	float m_angle;
	Animation m_anim;
public:
	OrderPointer();

	void update(float rad,float dt);

	void update(float dt);

	void draw(RenderWindow & window);

	float getAngle();

	//normalizes a radian angle to be in the range 0-2PI
	float NormalizeAngle(float angle);
};