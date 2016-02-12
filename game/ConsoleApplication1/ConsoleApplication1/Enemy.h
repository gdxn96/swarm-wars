#pragma once
#include "Vector2D.h"
#include "GameConstants.h"


enum class ENEMY_STATE {MOVING, ATTACKING, INIFILTRATING};
class Enemy
{
public:
	Enemy(Vector2D spawnPosition, Vector2D direction);
	void update(float dt);
	void draw(sf::RenderWindow& window);
	void changeState(ENEMY_STATE state);

private:
	Vector2D m_position;
	Vector2D m_direction;
	float m_speed;
	float m_radius;
	ENEMY_STATE m_currentState;

};

