#pragma once

#include "Scene.h"
#include "UnitController.h"
#include "BulletFactory.h"
#include "WeaponFactory.h"
#include "EnemyManager.h"
#include "CollisionManager.h"
#include "Bunker.h"
#include "Tower.h"

class GameScene : public Scene
{
public:
	GameScene();
	void update(float dt) override;
	void checkCollisions(float dt);
	void draw(sf::RenderWindow &window) override;
	void checkBunkers();

	//local method to game scene that needs to be addressed, no implementation
	void pause();
	

	//can be overrided
	//void exit();
	//void enter();

private:
	UnitController m_unitController;
	BulletFactory * m_bulletFactory;
	EnemyManager m_enemyManager;
	CollisionManager m_collisionMgr;

	vector<Bunker * > m_bunkers;
	Tower m_tower;

	int m_numBunkers;
	bool m_paused;


};
