#pragma once
#include "Vector2D.h"
#include "Circle.h"
#include "Animation.h"
#include "GameConstants.h"
#include "Light.h"

class Bullet
{
public:
	Bullet(std::string parentId, Vector2D position, Vector2D direction, float speed, float radius, float killDistance, float damage,sf::Color color,std::string animName,std::string audioName);
	void Update(float dt);
	void Draw(sf::RenderWindow &window);
	bool getAlive();
	Circle& getBounds();
	void kill();
	float getDamage();
	std::string getParentId();
private:
	Vector2D m_initPosition;
	Vector2D m_position;
	Vector2D m_direction;
	Vector2D m_velocity;

	float m_radius;
	float m_damage;

	float m_speed;
	float m_range;
	bool  m_alive ;
	Circle m_bounds;
	Animation m_anim;
	std::string m_parentId;
	Light * m_light;

	
};
