#include "stdafx.h"
#include "BulletManager.h"


void BulletManager::addBullet(BulletType bullet, Vector2D position, Vector2D direction)
{
	Bullet myBullet;

	//use this switch statement to pass in different spritesheets/other vars to different bullets depending on type
	switch (bullet)
	{
	case BulletType::TRIANGLE:
		bulletList.push_back(&Bullet(bullet, position, direction, 5));

		break;
	case BulletType::CIRCLE:
		bulletList.push_back(&Bullet(bullet, position, direction, 5));

		break;
	default:
		break;
	}
	
}

