#include "stdafx.h"
#include "WeaponFactory.h"

WeaponFactory * WeaponFactory::instance = nullptr;

void WeaponFactory::createWeapons(BulletFactory * bulletFactory)
{
	weaponTypes.clear();
	this->addWeapon(WeaponType::PLASMA_RIFLE, Weapon(GameConstants::PI / 16.0f, 300, 10, 10, BulletType::PLASMA, bulletFactory));
	this->addWeapon(WeaponType::ASSAULT_RIFLE, Weapon(GameConstants::PI / 16.0f, 300, 10, 10, BulletType::SIMPLE, bulletFactory));
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