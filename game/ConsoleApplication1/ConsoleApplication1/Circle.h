#pragma once
#include "Vector2D.h"

class Circle
{
public:
	Circle(Vector2D centre, float radius);
	void setCentre(Vector2D);
	void setRadius(float);
	float getRadius();
	Vector2D getCentre();

private:
	Vector2D m_centre;
	float m_radius;
};

