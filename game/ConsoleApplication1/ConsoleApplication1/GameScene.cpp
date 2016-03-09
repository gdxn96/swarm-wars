#include "stdafx.h"
#include "GameScene.h"
#include "AssetLoader.h"

GameScene::GameScene()
	:
	Scene(Scenes::GAME),
	m_collisionMgr(&m_unitController),
	m_creditsScoreText("text", Vector2D(GameConstants::WINDOW_CENTRE.x - 100, 0), 80, 6),
	m_pauseScene([&](){ togglePause(); }),
	m_drawMode(true),
	m_anim ("staticAnimation", Vector2D(-100, -100)),
	m_buyMenu(&m_unitController, [&](){ resetBunkers(); })
{
	otherMiniMapView.zoom(0.11f);
	m_creditsScoreText.setPosition(Vector2D(GameConstants::WINDOW_CENTRE.x - 100, GameConstants::WINDOW_CENTRE.y - (GameConstants::WINDOW_SIZE.h / 2)));

}

void GameScene::enter()
{
	LightManager::getInstance()->clear();
	m_bulletFactory = new BulletFactory();
	m_numBunkers = 15;
	resetBunkers();
	m_waveManager.reset();
	m_currentState = (GAME_STATE::GAME);
	m_paused = (false);
	m_anim.setFramesPerSecond(10);
	m_anim.SetLooping(true);
	m_anim.setRadius(200);
	m_anim.setPosition(GameConstants::WINDOW_CENTRE + Vector2D(150, 0));
	m_tower = new Tower();
	//create weapon list for easy retrieval
	WeaponFactory::getInstance()->createWeapons(m_bulletFactory);
	m_creditsScoreText.setColor(sf::Color(255, 215, 0, 255));
	//init must be called to avoid players being created without weapons
	m_unitController.init();

	

	floorSprite.setTexture(*AssetLoader::getInstance()->findTextureByKey("floor"));
	floorSprite.setPosition(Vector2f(0, 0));
	floorSprite.setScale(sf::Vector2f(0.5f, 0.5f));

	gameView.setCenter(m_unitController.getCurrentUnit()->getPosition().toSFMLVector());
	gameView.setSize(sf::Vector2f(GameConstants::WINDOW_SIZE.x, GameConstants::WINDOW_SIZE.y));
	gameView.zoom(zoom);
	AudioManager::instance()->PlayGameSound("track", false, 0.2f, Vector2D(0, 0), 0);

	miniMapView = View();
	// mini-map (upper-right corner)
	miniMapView.setViewport(sf::FloatRect(0.75f, 0.0f, 0.25f, 0.25f));
	miniMapView.zoom(1);
	miniMapView.setCenter(Vector2D(GameConstants::WINDOW_CENTRE).toSFMLVector());
	miniMapView.setSize(sf::Vector2f(GameConstants::WINDOW_SIZE.x, GameConstants::WINDOW_SIZE.y));


	otherGameView.setCenter(Vector2D(GameConstants::WINDOW_CENTRE).toSFMLVector());
	otherGameView.setSize(sf::Vector2f(GameConstants::WINDOW_SIZE.x, GameConstants::WINDOW_SIZE.y));
	

	// mini-map (upper-right corner)
	otherMiniMapView.setViewport(sf::FloatRect(0.75f, 0.0f, 0.25f, 0.25f));
	
	otherMiniMapView.setCenter(m_unitController.getCurrentUnit()->getPosition().toSFMLVector());
}

void GameScene::resetBunkers()
{
	for (auto&bunker : m_bunkers){ delete bunker; }
	m_bunkers.clear();

	for (int i = 0; i < m_numBunkers; i++)
	{
		m_bunkers.push_back(new Bunker(2 * GameConstants::PI / m_numBunkers * i));
	}
}

void GameScene::updateInput()
{
	if (!m_paused)
	{
		if (!m_buyMenu.Active())
		{
			m_unitController.updateInput();
			if (InputHandler::getInstance()->isPressed(InputHandler::START))
			{
				togglePause();
			}
			if (InputHandler::getInstance()->isPressed(InputHandler::BACK))
			{
				toggleDrawMode();
			}
			/////////////////////////////////temp/////////////////////////////////////////
			if (InputHandler::getInstance()->isPressed(InputHandler::DPAD_LEFT))
			{
				m_buyMenu.toggleActive();
			}
			/////////////////////////////////temp/////////////////////////////////////////
		}
		else
		{
			m_buyMenu.updateInput();
		}
		
	}
	else
	{
		m_pauseScene.updateInput();
	}
}

void GameScene::update(float dt)
{
	if (m_currentState == GAME_STATE::GAME)
	{
		if (m_drawMode)//zoomed  view
		{
			m_tower->update(dt);
			m_UnitSelector.updateUnits(m_unitController.getUnits());
			m_tower->setBarPosition(GameConstants::WINDOW_CENTRE- Vector2D(50,0));
			m_tower->setBarScale(Vector2D(1, 1));
			//m_UnitSelector.setPosition(Vector2D(gameView.getCenter().x, gameView.getCenter().y));
			m_UnitSelector.update(dt);
			m_anim.setPosition(Vector2D(0,0));
			m_anim.setSize(GameConstants::WINDOW_SIZE* 4);
			m_anim.setAlpha(110);
			m_anim.update(dt);	
		}
		else
		{
			m_tower->update(dt);
			m_tower->setBarPosition(Vector2D(GameConstants::WINDOW_CENTRE.x - 100, 65));
			m_tower->setBarScale(Vector2D(2, 2));
			m_UnitSelector.updateUnits(m_unitController.getUnits());
			m_UnitSelector.setPosition(GameConstants::WINDOW_SIZE);
			m_UnitSelector.update(dt);
			m_anim.setPosition(m_unitController.getCurrentUnit()->getPosition());
			m_anim.setSize(GameConstants::WINDOW_SIZE * 0.2f);
			m_anim.setAlpha(190);
			m_anim.update(dt);
		}

		m_creditsScoreText.setText(">CREDITS< : " + std::to_string(m_unitController.getTotalCreditAmount()));
		m_creditsScoreText.update(dt);

		m_waveManager.update(dt);
		m_unitController.update(dt);
		m_bulletFactory->UpdateBullets(dt);
	
		m_creditsScoreText.setColor(sf::Color(0, 191, 255, 255));
		checkCollisions(dt);
		checkBunkers();

		if (m_waveManager.waveJustFinished())
		{
			m_waveManager.setWaveJustFinished(false);
			AudioManager::instance()->PlayGameSound("wavecleared", false, 0.2f, Vector2D(), 0);
			m_buyMenu.open();
		}
		if (m_waveManager.waveJustStarted())
		{
			AudioManager::instance()->PlayGameSound("newwave", false, 0.8f, Vector2D(), 0);
			m_waveManager.setWaveJustStarted(false);
			AudioManager::instance()->PlayGameSound("warning", false, 0.2f, Vector2D(), 0);
			m_buyMenu.close();
		}

		for (Bunker* bunker : m_bunkers)
		{
			bunker->update(dt);
		}
		m_buyMenu.update(dt);

	}
	else if (m_currentState == GAME_STATE::PAUSED)
	{
		m_pauseScene.update(dt);
	}
	checkGameState();
}

void GameScene::toggleDrawMode()
{
	m_drawMode = !m_drawMode;
}

void GameScene::checkGameState()
{
	if (m_tower->getAlive() && !m_waveManager.isGameOver())
	{
		m_currentState = GAME_STATE::GAME;
	}
	else if (m_waveManager.isGameOver())
	{
		
		m_currentState = GAME_STATE::GAME_WIN;
		
	}
	else if (!m_tower->getAlive())
	{
		m_currentState = GAME_STATE::GAME_LOSE;
	}

	if (m_paused)
	{
		m_currentState = GAME_STATE::PAUSED;
	}

	
}

void GameScene::checkBunkers()
{
	for (int i = 0; i < m_bunkers.size(); i++)
	{
		if (!m_bunkers.at(i)->isAlive())
		{
			delete m_bunkers[i];
			m_bunkers.erase(m_bunkers.begin() + i);
		}

	}
}

void GameScene::checkCollisions(float dt)
{
	m_collisionMgr.checkBulletsTower(m_bulletFactory->getBullets(),* m_tower);
	m_collisionMgr.checkEnemyUnitRange(m_waveManager.getEnemies(), m_unitController.getUnits());
	m_collisionMgr.checkEnemyTower(m_waveManager.getEnemies(),* m_tower);
	m_collisionMgr.checkEnemyBullets(m_waveManager.getEnemies(), m_bulletFactory->getBullets());
	m_collisionMgr.checkEnemyBunker(m_waveManager.getEnemies(), m_bunkers, dt);
	m_collisionMgr.updateEnemyNeighbours(m_waveManager.getEnemies());
}

void GameScene::togglePause()
{
	m_paused = !m_paused;
}

void GameScene::draw(sf::RenderWindow &window)
{
	
	if (m_drawMode)
	{
		drawZoomed(window);
	}
	else
	{
		drawWholeView(window);
	}

	window.setView(View((GameConstants::WINDOW_CENTRE * 1).toSFMLVector(), (GameConstants::WINDOW_SIZE * 1).toSFMLVector()));
	m_buyMenu.draw(window);
	m_creditsScoreText.draw(window);

	if (m_waveManager.isWaveOver())
	{
		//draw wave timer
		PulsingText waveTime("New Wave in: " + to_string_with_precision(m_waveManager.getTimeLeft(), 2) + "s", Vector2D(), 60, 80);
		waveTime.draw(window);
	}
	
}



void GameScene::drawZoomed(sf::RenderWindow & window)
{
	
	if (m_currentState == GAME_STATE::PAUSED)
	{
		window.setView(otherGameView);
		m_pauseScene.draw(window);
	}
	else if (m_currentState == GAME_STATE::GAME_LOSE)
	{
		window.setView(otherGameView);
		SceneManager::getInstance()->switchTo(Scenes::GAME_LOSE);
	}
	else if (m_currentState == GAME_STATE::GAME_WIN)
	{
		window.setView(otherGameView);
		SceneManager::getInstance()->switchTo(Scenes::GAME_WIN);
	}
	else
	{

		gameView.setCenter(m_unitController.getCurrentUnit()->getPosition().toSFMLVector());
		LightManager::getInstance()->draw(window);

		// game draw -------------------------------------------------------
		window.setView(gameView);
		window.draw(floorSprite);
		for (Bunker* bunker : m_bunkers)
		{
			bunker->draw(window);

		}

		m_tower->draw(window);

		m_waveManager.draw(window);
		m_unitController.draw(window);
		m_bulletFactory->drawBullets(window);
		//m_UnitSelector.draw(window);
		m_unitController.drawUI(window);
		LightManager::getInstance()->draw(window);
		sf::RectangleShape cover;
		//--------------------------------------------------------------


		//minimap draw---------------------------------------------
		window.setView(miniMapView);
		window.draw(floorSprite);
		for (Bunker* bunker : m_bunkers)
		{
			bunker->draw(window);
		}

		m_tower->draw(window);

		m_waveManager.draw(window);
		m_unitController.draw(window);
		m_bulletFactory->drawBullets(window);
		
		//miniMapView.setCenter();
		
		
		LightManager::getInstance()->draw(window);
		m_anim.draw(window);
		//---------------------------------------------------------------
	}

	
}
void GameScene::drawWholeView(sf::RenderWindow & window)
{
	if (m_currentState == GAME_STATE::PAUSED)
	{
		window.setView(otherGameView);
		m_pauseScene.draw(window);
	}
	else if (m_currentState == GAME_STATE::GAME_LOSE)
	{
		window.setView(otherGameView);
		SceneManager::getInstance()->switchTo(Scenes::GAME_LOSE);
	}
	else if (m_currentState == GAME_STATE::GAME_WIN)
	{
		window.setView(otherGameView);
		SceneManager::getInstance()->switchTo(Scenes::GAME_WIN);
	}
	else
	{

		gameView.setCenter(m_unitController.getCurrentUnit()->getPosition().toSFMLVector());
		LightManager::getInstance()->draw(window);

		//game draw ----------------------------------
		window.setView(otherGameView);
		window.draw(floorSprite);
		for (Bunker* bunker : m_bunkers)
		{
			bunker->draw(window);

		}

		

		m_waveManager.draw(window);
		m_tower->draw(window);
		m_unitController.draw(window);
		m_bulletFactory->drawBullets(window);
		m_UnitSelector.draw(window);
		
		m_unitController.drawUI(window);
		m_creditsScoreText.draw(window);
		
		miniMapView.setCenter(m_unitController.getCurrentUnit()->getPosition().toSFMLVector());
		LightManager::getInstance()->draw(window);
		//----------------------------------------------------------


		// mini map draw ----------------------------------
		window.setView(otherMiniMapView);
		window.draw(floorSprite);
		for (Bunker* bunker : m_bunkers)
		{
			bunker->draw(window);

		}

		m_tower->draw(window);
		m_anim.setPosition(GameConstants::WINDOW_CENTRE + Vector2D(150, 0));
		m_waveManager.draw(window);
		m_unitController.draw(window);
		m_bulletFactory->drawBullets(window);
		m_UnitSelector.draw(window);
		m_anim.draw(window);
		otherMiniMapView.setCenter(m_unitController.getCurrentUnit()->getPosition().toSFMLVector());
		LightManager::getInstance()->draw(window);
		sf::RectangleShape cover;
	}
}
