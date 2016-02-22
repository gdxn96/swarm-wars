#pragma once
#include "Vector2D.h"
#include "VisionCone.h"
#include "BulletFactory.h"

class Weapon
{
public:
	Weapon(){};
	Weapon(float fov, float range, float damage, float bulletsPerSecond, BulletType bullet, BulletFactory * bulletFactory);
	void draw(sf::RenderWindow & window);
	void update(Vector2D position, float dir, float dt);
	void fire();
	float RandomFloat(float min, float max);
	Polygon2D& getRange();

	void setParentId(std::string parentId);

private:
	float m_range;
	float m_timeToFire;
	float m_fireRate;
	float m_damage;
	float m_fov;
	float m_dirAngle;
	Vector2D m_position;
	VisionCone m_visionCone;
	BulletType m_bullet;
	BulletFactory *m_bulletFactory;

	std::string m_parentId;
};


