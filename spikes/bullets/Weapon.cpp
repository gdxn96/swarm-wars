#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon() : currWeapon(WeaponType::CIRCLE)
{

}

void Weapon::switchWeapon()
{
	if (currWeapon == WeaponType::CIRCLE)
	{
		currWeapon = WeaponType::SQUARE;
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
		BulletManager::getInstance()->addBullet(BulletType::CIRCLE, initPos, direction);
		break;
	case WeaponType::SQUARE:
		BulletManager::getInstance()->addBullet(BulletType::SQUARE, initPos, direction);
		break;
	default:
		break;
	}
}