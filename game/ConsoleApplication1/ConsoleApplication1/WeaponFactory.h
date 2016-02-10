#pragma once
#include "Weapon.h"
#include <vector>
#include "GameConstants.h"
#include <iostream>
using namespace std;

enum class WeaponType {PLASMA_RIFLE, ASSAULT_RIFLE};

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
