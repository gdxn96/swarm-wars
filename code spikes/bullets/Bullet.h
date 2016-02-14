#pragma once
#include "BulletTypes.h"
#include "Vector2D.h"

class Bullet
{
public:
	//default
	Bullet();
	Bullet(BulletType type, Vector2D initPos, Vector2D direction, float speed);
	void Update();
	void Draw(sf::RenderWindow *window);

private:
	Vector2D m_position;
	Vector2D m_dir;
	Vector2D m_velocity;
	float m_speed;

	//later the bullet type will be removed from bullet and variables will be 
	//set depending on bullet type in bulletManager, this is just for testing
	BulletType m_type;
};


