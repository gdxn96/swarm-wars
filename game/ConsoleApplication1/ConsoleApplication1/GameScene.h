#pragma once

#include "Scene.h"
#include "UnitController.h"
#include "BulletFactory.h"
#include "WeaponFactory.h"
#include "WaveManager.h"
#include "CollisionManager.h"
#include "Bunker.h"
#include "Tower.h"
#include "UnitSelector.h"
#include "Animation.h"
#include "PulsingText.h"
class GameScene : public Scene
{
public:
	GameScene();
	void update(float dt) override;
	void checkCollisions(float dt);
	void draw(sf::RenderWindow &window) override;
	void updateInput() override;
	void checkBunkers();

	//local method to game scene that needs to be addressed, no implementation
	void pause();
	

	//can be overrided
	//void exit();
	//void enter();

private:
	UnitController m_unitController;
	UnitSelector m_UnitSelector;
	BulletFactory * m_bulletFactory;
	WaveManager m_waveManager;
	CollisionManager m_collisionMgr;
	
	vector<Bunker * > m_bunkers;
	Tower m_tower;
	sf::Texture floor;
	sf::Sprite floorSprite;
	int m_numBunkers;
	bool m_paused;


	//camera test
	sf::View miniMapView, gameView;
	Animation m_anim;

	PulsingText m_creditsScoreText;

	template <class T>
	std::string numberToString(const T& t);

};
