#pragma once

#include "Vector2D.h"
#include "BulletManager.h"
#include "BulletTypes.h"

enum class WeaponType {TRIANGLE, CIRCLE};
class Weapon
{
public:
	Weapon();
	void switchWeapon();
	void fire(Vector2D direction, Vector2D initPos);
private:
	WeaponType currWeapon;
};


