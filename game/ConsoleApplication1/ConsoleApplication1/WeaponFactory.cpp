#include "stdafx.h"
#include "WeaponFactory.h"

WeaponFactory * WeaponFactory::instance = nullptr;

void WeaponFactory::createWeapons(BulletFactory * bulletFactory)
{
	weaponTypes.clear();
	this->addWeapon(WeaponType::AK, Weapon(WeaponStats::AK_FOV, WeaponStats::AK_RANGE, WeaponStats::AK_DMG, WeaponStats::AK_FIRE_RATE, BulletType::SIMPLE, bulletFactory));
	this->addWeapon(WeaponType::PLASMA, Weapon(WeaponStats::PLASMA_FOV, WeaponStats::PLASMA_RANGE, WeaponStats::PLASMA_DMG, WeaponStats::PLASMA_FIRE_RATE, BulletType::SIMPLE, bulletFactory));
	this->addWeapon(WeaponType::SNIPER, Weapon(WeaponStats::SNIPER_FOV, WeaponStats::SNIPER_RANGE, WeaponStats::SNIPER_DMG, WeaponStats::SNIPER_FIRE_RATE, BulletType::SIMPLE, bulletFactory));
	this->addWeapon(WeaponType::SHOTGUN, Weapon(WeaponStats::SHOTGUN_FOV, WeaponStats::SHOTGUN_RANGE, WeaponStats::SHOTGUN_DMG, WeaponStats::SHOTGUN_FIRE_RATE, BulletType::SIMPLE, bulletFactory));
	this->addWeapon(WeaponType::LMG, Weapon(WeaponStats::LMG_FOV, WeaponStats::LMG_RANGE, WeaponStats::LMG_DMG, WeaponStats::LMG_FIRE_RATE, BulletType::SIMPLE, bulletFactory));
	this->addWeapon(WeaponType::SMG, Weapon(WeaponStats::SMG_FOV, WeaponStats::SMG_RANGE, WeaponStats::SMG_DMG, WeaponStats::SMG_FIRE_RATE, BulletType::SIMPLE, bulletFactory));
	this->addWeapon(WeaponType::PISTOL, Weapon(WeaponStats::PISTOL_FOV, WeaponStats::PISTOL_RANGE, WeaponStats::PISTOL_DMG, WeaponStats::PISTOL_FIRE_RATE, BulletType::SIMPLE, bulletFactory));
}

void WeaponFactory::addWeapon(WeaponType type, Weapon weapon)
{
	weaponTypes.push_back(type);
	weapons.push_back(weapon);
}

WeaponFactory::WeaponFactory()
{}

WeaponFactory * WeaponFactory::getInstance()
{
	if (instance == nullptr)
	{
		instance = new WeaponFactory();
	}
	return instance;
}

Weapon WeaponFactory::getNewWeapon(WeaponType weapon)
{
	for (int i = 0; i < weaponTypes.size(); i++)
	{
		if (weaponTypes[i] == weapon)
		{
			cout << i << endl;
			return weapons[i];
		}
	}
	return Weapon();
}