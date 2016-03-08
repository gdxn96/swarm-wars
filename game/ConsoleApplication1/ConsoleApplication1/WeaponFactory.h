#pragma once
#include "Weapon.h"
#include <vector>
#include "GameConstants.h"
#include <iostream>
using namespace std;

enum class WeaponType { PLASMA, AK, AK1, AK2, AK3, SNIPER, SNIPER1, SNIPER2, SNIPER3, SHOTGUN, PLASMA1, PLASMA2, PLASMA3, LMG, SMG, PISTOL, NULL_WEAPON };

class WeaponFactory
{
public:
	static WeaponFactory * getInstance();
	Weapon getNewWeapon(WeaponType weapon);
	void addWeapon(WeaponType type, Weapon weapon);
	void createWeapons(BulletFactory * bulletFactory);

private:
	std::vector<Weapon> weapons;
	std::vector<WeaponType> weaponTypes;
	BulletFactory * m_bulletFactory;

protected:
	WeaponFactory();
	static WeaponFactory * instance;
};
