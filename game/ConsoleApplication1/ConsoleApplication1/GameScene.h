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
#include "PauseScene.h"

enum class GAME_STATE {PAUSED, GAME, GAME_LOSE};
class GameScene : public Scene
{
public:
	GameScene();
	void update(float dt) override;
	void checkCollisions(float dt);
	void draw(sf::RenderWindow &window) override;
	void updateInput() override;
	void checkBunkers();
	void checkGameState();
	void togglePause();
	

	//can be overrided
	//void exit();
	//void enter();

private:
	UnitController m_unitController;
	UnitSelector m_UnitSelector;
	BulletFactory * m_bulletFactory;
	WaveManager m_waveManager;
	CollisionManager m_collisionMgr;
	GAME_STATE m_currentState;

	PauseScene m_pauseScene;
	
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
