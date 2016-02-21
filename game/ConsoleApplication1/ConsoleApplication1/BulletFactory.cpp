#include "stdafx.h"
#include "BulletFactory.h"
#include "Bullet.h"
#include "GameConstants.h"
#include <iostream>

void BulletFactory::addBullet(std::string parentId, BulletType bullet, Vector2D position, Vector2D direction, float range, float damage)
{
	float bulletSpeed = 0;
	float radius = 1;

	//use this switch statement to pass in different spritesheets/other 
	//vars to different bullets depending on type
	switch (bullet)
	{
	case BulletType::PLASMA:
		bulletSpeed = BULLET_STATS::PLASMA_SPEED;
		radius = BULLET_STATS::PLASMA_RADIUS;

		m_bulletList.push_back(new Bullet(parentId, position, direction, bulletSpeed, radius, range, damage));

		break;

	case BulletType::SIMPLE:
		bulletSpeed = BULLET_STATS::SIMPLE_SPEED;
		radius = BULLET_STATS::SIMPLE_RADIUS;

		m_bulletList.push_back(new Bullet(parentId, position, direction, bulletSpeed, radius, range, damage));

		break;

	default:
		return;
	}


}

std::vector<Bullet *> BulletFactory::getBullets()
{
	return m_bulletList;
}

void BulletFactory::drawBullets(sf::RenderWindow& window)
{
	for (int i = 0; i < m_bulletList.size(); i++)
	{
		m_bulletList.at(i)->Draw(window);
	}

}

void BulletFactory::UpdateBullets(float dt)
{
	for (int i = 0; i < m_bulletList.size(); i++)
	{
		if (m_bulletList.at(i)->getAlive())
		{
			m_bulletList.at(i)->Update(dt);
		}
		else
		{
			delete m_bulletList[i];
			m_bulletList.erase(m_bulletList.begin() + i);
			//std::cout << m_bulletList.size() << std::endl;
		}

	}

}

