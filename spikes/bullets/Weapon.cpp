#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon() : currWeapon(WeaponType::CIRCLE)
{

}

void Weapon::switchWeapon()
{
	if (currWeapon == WeaponType::CIRCLE)
	{
		currWeapon = WeaponType::TRIANGLE;
	}
	else
	{
		currWeapon = WeaponType::CIRCLE;
	}
}

void Weapon::fire(Vector2D direction, Vector2D initPos)
{
	switch (currWeapon)
	{
	case WeaponType::CIRCLE:
		BulletManager::getInstance()->addBullet(BulletType::CIRCLE, Vector2D(0,0), Vector2D(1,1));
		break;
	case WeaponType::TRIANGLE:
		BulletManager::getInstance()->addBullet(BulletType::TRIANGLE, Vector2D(0, 0), Vector2D(1, 1));
		break;
	default:
		break;
	}
}