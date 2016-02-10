#include "stdafx.h"
#include "WeaponFactory.h"

WeaponFactory * WeaponFactory::instance = nullptr;

void WeaponFactory::createWeapons(BulletFactory * bulletFactory)
{
	
	this->addWeapon(WeaponType::PLASMA_RIFLE, Weapon(GameConstants::PI / 16.0f, 300, 10, 10, BulletType::PLASMA, bulletFactory));
	this->addWeapon(WeaponType::ASSAULT_RIFLE, Weapon(GameConstants::PI / 16.0f, 300, 10, 10, BulletType::SIMPLE, bulletFactory));

	cout << "create weapons" << endl;
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
		cout << "dsvnosidvn" << endl;
		instance = new WeaponFactory();
	}
	cout << "iophih-ewhg" << endl;
	return instance;
}

Weapon WeaponFactory::getNewWeapon(WeaponType weapon)
{
	for (int i = 0; i < weaponTypes.size(); i++)
	{
		cout << "search" << endl;
		if (weaponTypes[i] == weapon)
		{
			cout << i << endl;
			return weapons[i];
		}
	}
	cout << "search_failed" << endl;
	return Weapon();
}