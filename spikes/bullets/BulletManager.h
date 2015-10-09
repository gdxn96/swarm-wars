#pragma once
#include "Bullet.h"
#include "Vector2D.h"
#include <vector>
#include "BulletTypes.h"



class BulletManager
{
public:
	static BulletManager * getInstance()
	{
		static BulletManager * instance;
		return instance;
	}
	void UpdateBullets();

	std::vector<Bullet> getBulletList();

	//creates a bullet and places it inside the bulletList to be updated
	void addBullet(BulletType bullet, Vector2D position, Vector2D direction);

private:
	BulletManager() {};

	std::vector<Bullet *> bulletList;
};

