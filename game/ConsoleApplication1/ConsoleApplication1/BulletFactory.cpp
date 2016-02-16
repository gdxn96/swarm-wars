#include "stdafx.h"
#include "BulletFactory.h"
#include "Bullet.h"
#include <iostream>

void BulletFactory::addBullet(BulletType bullet, Vector2D position, Vector2D direction, float range)
{
	float bulletSpeed = 0;
	float radius = 1;

	//use this switch statement to pass in different spritesheets/other 
	//vars to different bullets depending on type
	switch (bullet)
	{
	case BulletType::PLASMA:
		bulletSpeed = 150;
		radius = 2;

		m_bulletList.push_back(new Bullet(position, direction, bulletSpeed, radius, range));

		break;

	case BulletType::SIMPLE:
		bulletSpeed = 150;
		radius = 2;

		m_bulletList.push_back(new Bullet(position, direction, bulletSpeed, radius, range));

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

