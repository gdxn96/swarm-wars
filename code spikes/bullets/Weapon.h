#pragma once

#include "Vector2D.h"
#include "BulletManager.h"
#include "BulletTypes.h"

enum class WeaponType {SQUARE, CIRCLE};

class Weapon
{
public:
	Weapon();

	/*at the moment simply switches between square-gun and 
	circle-gun, will be changed later to enum types*/
	void switchWeapon();

	//simply takes the initial direction/position of the bullet asks 
	//bulletMgr to create it
	void fire(Vector2D direction, Vector2D initPos);
private:
	WeaponType currWeapon;
};


