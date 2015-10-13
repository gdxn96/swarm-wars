#pragma once
#include "Bullet.h"
#include "Vector2D.h"
#include <vector>
#include "BulletTypes.h"




class BulletManager
{
public:
	
	static BulletManager * getInstance();

	//updates all the bullets in the list
	void UpdateBullets();

	//draws all the bullets in the list
	void drawBullets(sf::RenderWindow* window);

	//creates a bullet and places it inside the bulletList to be updated
	void addBullet(BulletType bullet, Vector2D position, Vector2D direction);

protected:
	BulletManager();
	static BulletManager * instance;

	std::vector<Bullet *> bulletList;
};



