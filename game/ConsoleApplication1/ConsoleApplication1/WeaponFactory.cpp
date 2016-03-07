#include "stdafx.h"
#include "WeaponFactory.h"

WeaponFactory * WeaponFactory::instance = nullptr;

void WeaponFactory::createWeapons(BulletFactory * bulletFactory)
{
	weaponTypes.clear();
	weapons.clear();
	this->addWeapon(WeaponType::AK, Weapon(">AK<",WeaponStats::AK_FOV, WeaponStats::AK_RANGE, WeaponStats::AK_DMG, WeaponStats::AK_FIRE_RATE, BulletType::AK, bulletFactory));
	this->addWeapon(WeaponType::PLASMA, Weapon(">PLASMA<",WeaponStats::PLASMA_FOV, WeaponStats::PLASMA_RANGE, WeaponStats::PLASMA_DMG, WeaponStats::PLASMA_FIRE_RATE, BulletType::PLASMA, bulletFactory));
	this->addWeapon(WeaponType::SNIPER, Weapon(">SNIPER<",WeaponStats::SNIPER_FOV, WeaponStats::SNIPER_RANGE, WeaponStats::SNIPER_DMG, WeaponStats::SNIPER_FIRE_RATE, BulletType::SNIPER, bulletFactory));
	this->addWeapon(WeaponType::SHOTGUN, Weapon(">SHOTGUN<",WeaponStats::SHOTGUN_FOV, WeaponStats::SHOTGUN_RANGE, WeaponStats::SHOTGUN_DMG, WeaponStats::SHOTGUN_FIRE_RATE, BulletType::SHOTGUN, bulletFactory));
	this->addWeapon(WeaponType::LMG, Weapon(">LMG<",WeaponStats::LMG_FOV, WeaponStats::LMG_RANGE, WeaponStats::LMG_DMG, WeaponStats::LMG_FIRE_RATE, BulletType::LMG, bulletFactory));
	this->addWeapon(WeaponType::SMG, Weapon(">SMG<",WeaponStats::SMG_FOV, WeaponStats::SMG_RANGE, WeaponStats::SMG_DMG, WeaponStats::SMG_FIRE_RATE, BulletType::SMG, bulletFactory));
	this->addWeapon(WeaponType::PISTOL, Weapon(">PISTOL<",WeaponStats::PISTOL_FOV, WeaponStats::PISTOL_RANGE, WeaponStats::PISTOL_DMG, WeaponStats::PISTOL_FIRE_RATE, BulletType::PISTOL, bulletFactory));
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