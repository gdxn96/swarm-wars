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
#include "BuyMenuScene.h"

enum class GAME_STATE {PAUSED, GAME, GAME_LOSE, GAME_WIN};
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
	void toggleDrawMode();
	void resetBunkers();
	int i = 0;
	//can be overrided
	void enter();
	//void exit();

private:
	BuyMenu m_buyMenu;

	UnitController m_unitController;
	UnitSelector m_UnitSelector;
	BulletFactory * m_bulletFactory;
	WaveManager m_waveManager;
	CollisionManager m_collisionMgr;
	GAME_STATE m_currentState;
	void drawZoomed(sf::RenderWindow & window);
	void drawWholeView(sf::RenderWindow & window);
	PauseScene m_pauseScene;
	
	vector<Bunker * > m_bunkers;
	Tower * m_tower;
	sf::Texture floor;
	sf::Sprite floorSprite;
	int m_numBunkers;
	bool m_paused;
	bool m_drawMode;
	float zoom = 0.51f;

	//camera test
	sf::View miniMapView, gameView,otherMiniMapView,otherGameView;
	Animation m_anim;

	PulsingText m_creditsScoreText;


};
