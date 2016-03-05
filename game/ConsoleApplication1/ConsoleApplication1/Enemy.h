#pragma once
#include "Vector2D.h"
#include "GameConstants.h"
#include "Circle.h"
#include "bar.h"
#include "Animation.h"
#include "Graph.h"
enum class ENEMY_STATE {MOVING, ATTACKING};
class Enemy
{
public:
	typedef GraphNode<string, int> Node;
	Enemy(Vector2D spawnPosition, std::vector<Node *> nodes, float maxHealth,
		float damagePerSecond, float speed, float radius, 
		int numberDeadPylons, std::string animKey);

	void update(float dt);
	void draw(sf::RenderWindow& window);
	void changeState(ENEMY_STATE state);

	Circle& getBounds();
	bool getAlive();
	float getDamage();
	void kill();
	void damage(float dmg);

	Vector2D getSeperationHeading();
	Vector2D getAlignmentHeading();
	Vector2D getCohesionHeading();
	Circle& getNeighbourBounds();

	Vector2D getDirection();
	void resetNeighbours();
	void addNeighbour(Enemy* enemy);



private:
	Vector2D m_position;
	Vector2D m_direction;
	
	std::vector<Node *> nodes;
	float m_speed;
	float m_radius;
	ENEMY_STATE m_currentState;
	Circle m_bounds;
	bool m_alive;
	float m_health;
	float m_damagePerSecond;
	const float m_maxHealth;
	bar m_healthBar;
	Animation m_anim;
	float m_seperationWeighting;

	vector<Enemy * > m_neighbours;
	Circle m_neighbourCircle;
	int m_pathSize;
	Vector2D m_targetDirection;
};

