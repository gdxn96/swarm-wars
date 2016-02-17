#pragma once
#include "Vector2D.h"
#include "Circle.h"

class Bullet
{
public:
	Bullet(Vector2D position, Vector2D direction, float speed, float radius, float killDistance, float damage);
	void Update(float dt);
	void Draw(sf::RenderWindow &window);
	bool getAlive();
	Circle& getBounds();
	void kill();
	float getDamage();

private:
	Vector2D m_initPosition;
	Vector2D m_position;
	Vector2D m_direction;
	Vector2D m_velocity;

	float m_radius;
	float m_damage;

	float m_speed;
	float m_range;
	bool m_alive;
	Circle m_bounds;
	
};
