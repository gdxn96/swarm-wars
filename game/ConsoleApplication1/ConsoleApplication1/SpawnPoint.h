#pragma once

#include "Vector2D.h"



class SpawnPoint
{
private:
	sf::CircleShape m_shape;	//temporary
	float m_radius;				//temporary
	Vector2D m_pos;
	bool m_active;

public:
	SpawnPoint(Vector2D position);
	void draw(sf::RenderWindow& window);
	Vector2D getPos();
	void setActive(bool val);
};