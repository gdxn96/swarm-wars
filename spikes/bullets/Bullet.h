#pragma once
#include "BulletTypes.h"
#include "Vector2D.h"

class Bullet
{
public:
	Bullet();
	Bullet(BulletType type, Vector2D initPos, Vector2D direction, float speed);
	void Update();

private:
	Vector2D m_position;
	Vector2D m_dir;
	Vector2D m_velocity;
	float m_speed;
};


