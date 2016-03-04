#pragma once
#include "Vector2D.h"
#include <vector>
#include "Bullet.h"

enum class BulletType{ PLASMA, AK,SNIPER,LMG,SMG,PISTOL,SHOTGUN };



class BulletFactory
{
public:
	BulletFactory(){};

	
	//updates all the bullets in the list
	void UpdateBullets(float dt);

	//draws all the bullets in the list
	void drawBullets(sf::RenderWindow & window);

	//creates a bullet and places it inside the bulletList to be updated
	void addBullet(std::string parentId, BulletType bullet, Vector2D position, Vector2D direction, float range, float damage);

	std::vector<Bullet *> getBullets();

private:
	std::vector<Bullet *> m_bulletList;
};



