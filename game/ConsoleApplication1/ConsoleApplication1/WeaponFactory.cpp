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

	//add new weaposn
	//sniper
	this->addWeapon(WeaponType::SNIPER1, Weapon(">SNIPER LVL 1<", WeaponStats::SNIPER1_FOV, WeaponStats::SNIPER1_RANGE, WeaponStats::SNIPER1_DMG, WeaponStats::SNIPER1_FIRE_RATE, BulletType::SNIPER1, bulletFactory));
	this->addWeapon(WeaponType::SNIPER2, Weapon(">SNIPER LVL 2<", WeaponStats::SNIPER2_FOV, WeaponStats::SNIPER2_RANGE, WeaponStats::SNIPER2_DMG, WeaponStats::SNIPER2_FIRE_RATE, BulletType::SNIPER2, bulletFactory));
	this->addWeapon(WeaponType::SNIPER3, Weapon(">SNIPER LVL 3<", WeaponStats::PISTOL_FOV, WeaponStats::PISTOL_RANGE, WeaponStats::PISTOL_DMG, WeaponStats::PISTOL_FIRE_RATE, BulletType::SNIPER3, bulletFactory));
	//plasma
	this->addWeapon(WeaponType::PLASMA1, Weapon(">PLASMA LVL 1<", WeaponStats::PLASMA1_FOV, WeaponStats::PLASMA1_RANGE, WeaponStats::PLASMA1_DMG, WeaponStats::PLASMA1_FIRE_RATE, BulletType::PLASMA1, bulletFactory));
	this->addWeapon(WeaponType::PLASMA2, Weapon(">PLASMA LVL 2<", WeaponStats::PLASMA2_FOV, WeaponStats::PLASMA2_RANGE, WeaponStats::PLASMA2_DMG, WeaponStats::PLASMA2_FIRE_RATE, BulletType::PLASMA2, bulletFactory));
	this->addWeapon(WeaponType::PLASMA3, Weapon(">PLASMA LVL 3<", WeaponStats::PLASMA3_FOV, WeaponStats::PLASMA3_RANGE, WeaponStats::PLASMA3_DMG, WeaponStats::PLASMA3_FIRE_RATE, BulletType::PLASMA3, bulletFactory));
	//ak
	this->addWeapon(WeaponType::AK1, Weapon(">AK LVL 1<", WeaponStats::AK1_FOV, WeaponStats::AK1_RANGE, WeaponStats::AK1_DMG, WeaponStats::AK1_FIRE_RATE, BulletType::AK1, bulletFactory));
	this->addWeapon(WeaponType::AK2, Weapon(">AK LVL 2<", WeaponStats::AK2_FOV, WeaponStats::AK2_RANGE, WeaponStats::AK2_DMG, WeaponStats::AK2_FIRE_RATE, BulletType::AK2, bulletFactory));
	this->addWeapon(WeaponType::AK3, Weapon(">AK LVL 3<", WeaponStats::AK3_FOV, WeaponStats::AK3_RANGE, WeaponStats::AK3_DMG, WeaponStats::AK3_FIRE_RATE, BulletType::AK3, bulletFactory));

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