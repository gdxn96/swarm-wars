#pragma once
#include "Vector2D.h"
#include "GameConstants.h"
#include "Circle.h"


enum class ENEMY_STATE {MOVING, ATTACKING};
class Enemy
{
public:
	Enemy(Vector2D spawnPosition, Vector2D direction, float maxHealth, float damagePerSecond, float speed, float radius);
	void update(float dt);
	void draw(sf::RenderWindow& window);
	void changeState(ENEMY_STATE state);

	Circle& getBounds();
	bool getAlive();
	float getDamage();
	void kill();
	void damage(float dmg);

private:
	Vector2D m_position;
	Vector2D m_direction;
	float m_speed;
	float m_radius;
	ENEMY_STATE m_currentState;
	Circle m_bounds;
	bool m_alive;
	float m_health;
	float m_damagePerSecond;
	const float m_maxHealth;



};

