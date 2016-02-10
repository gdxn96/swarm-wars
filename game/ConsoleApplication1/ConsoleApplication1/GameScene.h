#pragma once

#include "Scene.h"
#include "UnitController.h"
#include "BulletFactory.h"
#include "WeaponFactory.h"

class GameScene : public Scene
{
public:
	GameScene();
	void update(float dt) override;
	void draw(sf::RenderWindow &window) override;

	//local method to game scene that needs to be addressed, no implementation
	void pause();
	

	//can be overrided
	//void exit();
	//void enter();

private:
	UnitController m_unitController;
	BulletFactory * m_bulletFactory;
	

};
