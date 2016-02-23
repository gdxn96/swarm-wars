#pragma once
#include "Vector2D.h"

class Circle
{
public:
	Circle();
	Circle(Vector2D centre, float radius);
	void setCentre(Vector2D);
	void setRadius(float);
	void draw(sf::RenderWindow & window);
	float getRadius();
	Vector2D getCentre();
	void setTexture(sf::Texture *);
	void setAlpha(float);
private:
	Vector2D m_centre;
	float m_radius;
	sf::CircleShape circle;
};

