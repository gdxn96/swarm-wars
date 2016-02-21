#include "stdafx.h"
#include "BulletFactory.h"
#include "Bullet.h"
#include "GameConstants.h"
#include <iostream>

void BulletFactory::addBullet(std::string parentId, BulletType bullet, Vector2D position, Vector2D direction, float range, float damage)
{
	float bulletSpeed = 0;
	float radius = 1;
	sf::Color color;
	std::string animName,audioName;

	//use this switch statement to pass in different spritesheets/other 
	//vars to different bullets depending on type
	switch (bullet)
	{
	case BulletType::PLASMA:
		bulletSpeed = BULLET_STATS::PLASMA_SPEED;
		radius = BULLET_STATS::PLASMA_RADIUS;
		color = BULLET_STATS::PLASMA_COLOR;
		animName = BULLET_STATS::PLASMA_TEXTURE_KEY;
		audioName = BULLET_STATS::PLASMA_AUDIO_NAME;
		break;

	case BulletType::AK:
		bulletSpeed = BULLET_STATS::SIMPLE_SPEED;
		radius = BULLET_STATS::SIMPLE_RADIUS;
		color = BULLET_STATS::SIMPLE_COLOR;
		animName = BULLET_STATS::SIMPLE_TEXTURE_KEY;
		audioName = BULLET_STATS::SIMPLE_AUDIO_NAME;
		break;

	case BulletType::LMG:
		bulletSpeed = BULLET_STATS::LMG_SPEED;
		radius = BULLET_STATS::LMG_RADIUS;
		color = BULLET_STATS::LMG_COLOR;
		animName = BULLET_STATS::LMG_TEXTURE_KEY;
		audioName = BULLET_STATS::LMG_AUDIO_NAME;
		break;

	case BulletType::SMG:
		bulletSpeed = BULLET_STATS::SMG_SPEED;
		radius = BULLET_STATS::SMG_RADIUS;
		color = BULLET_STATS::SMG_COLOR;
		animName = BULLET_STATS::SMG_TEXTURE_KEY;
		audioName = BULLET_STATS::SMG_AUDIO_NAME;
		break;

	case BulletType::SNIPER:
		bulletSpeed = BULLET_STATS::SNIPER_SPEED;
		radius = BULLET_STATS::SNIPER_RADIUS;
		color = BULLET_STATS::SNIPER_COLOR;
		animName = BULLET_STATS::SNIPER_TEXTURE_KEY;
		audioName = BULLET_STATS::SNIPER_AUDIO_NAME;
		break;

	case BulletType::PISTOL:
		bulletSpeed = BULLET_STATS::PISTOL_SPEED;
		radius = BULLET_STATS::PISTOL_RADIUS;
		color = BULLET_STATS::PISTOL_COLOR;
		animName = BULLET_STATS::PISTOL_TEXTURE_KEY;
		audioName = BULLET_STATS::PISTOL_AUDIO_NAME;
		break;

	case BulletType::SHOTGUN:
		bulletSpeed = BULLET_STATS::SHOTGUN_SPEED;
		radius = BULLET_STATS::SHOTGUN_RADIUS;
		color = BULLET_STATS::SHOTGUN_COLOR;
		animName = BULLET_STATS::SHOTGUN_TEXTURE_KEY;
		audioName = BULLET_STATS::SHOTGUN_AUDIO_NAME;
		break;

	default:
		return;
	}

	m_bulletList.push_back(new Bullet(parentId, position, direction, bulletSpeed, radius, range, damage, color, animName,audioName));

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

