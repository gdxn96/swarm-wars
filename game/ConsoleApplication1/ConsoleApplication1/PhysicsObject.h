#pragma once

#include "Circle.h"
#include "GameConstants.h"
#include <math.h>
#include "AssetLoader.h"


class PhysicsObject
{
private:
	//Object
	sf::CircleShape m_circle;
	Vector2D m_pos;
	Vector2D m_direction;
	sf::Color m_color;
	float m_speed;
	float m_minSpeed;
	float m_radius;
	float m_mass;
	float m_size;
	bool m_onScreen;
	float m_rotationDegrees;
	const float DEGREE;
	bool m_rotationDirection;

	//Physics
	float m_gravity;
	float m_restitution;
	float m_airMass;
	float m_drag;

	//Bounds
	Vector2D m_bounds;

public:
	PhysicsObject(Vector2D position, float angle, float speed);
	void update(float dt);
	void draw(sf::RenderWindow& window);
	void bounce();
	void changeRotation();
};