#pragma once
#include "Vector2D.h"
#include "VisionCone.h"
#include "BulletFactory.h"

class Weapon
{
public:
	Weapon(){};
	Weapon(std::string name,float fov, float range, float damage, float bulletsPerSecond, BulletType bullet, BulletFactory * bulletFactory);
	void draw(sf::RenderWindow & window);
	void update(Vector2D position, float dir, float dt);
	void fire();
	Polygon2D& getRange();
	float getRoF();
	float getDamage();
	string getName();
	void setParentId(std::string parentId);

private:
	float m_range;
	float m_timeToFire;
	float m_fireRate;
	float m_damage;
	float m_fov;
	float m_dirAngle;
	std::string name;
	Vector2D m_position;
	VisionCone m_visionCone;
	BulletType m_bullet;
	BulletFactory *m_bulletFactory;
	float m_bulletsPerSecond;
	std::string m_parentId;
};


