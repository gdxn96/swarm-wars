#include "stdafx.h"
#include "BulletManager.h"


BulletManager * BulletManager::instance = 0;

void BulletManager::addBullet(BulletType bullet, Vector2D position, Vector2D direction)
{
	Bullet myBullet;

	//use this switch statement to pass in different spritesheets/other vars to different bullets depending on type
	switch (bullet)
	{
	case BulletType::SQUARE:

		//note that i pass the bullet type in here, this will be removed asap
		BulletManager::getInstance()->bulletList.push_back(new Bullet(bullet, position, direction, 5));

		break;
	case BulletType::CIRCLE:
		BulletManager::getInstance()->bulletList.push_back( new Bullet(bullet, position, direction, 5));
		break;
	default:
		break;
	}
	
}

BulletManager * BulletManager::getInstance()
{
	if (instance == 0)
	{
		instance = new BulletManager();
	}
	return instance;
}

BulletManager::BulletManager()
{}

void BulletManager::drawBullets(sf::RenderWindow* window)
{
	for (int i = 0; i < bulletList.size(); i++)
		bulletList.at(i)->Draw(window);
}

void BulletManager::UpdateBullets()
{
	for (int i = 0; i < bulletList.size(); i++)
		bulletList.at(i)->Update();
}
