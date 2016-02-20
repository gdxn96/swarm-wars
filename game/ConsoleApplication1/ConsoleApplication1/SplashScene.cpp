#include "stdafx.h"
#include "SplashScene.h"

SplashScene::SplashScene() : Scene(Scenes::SPLASH), m_timeToSwitch(3)
{
		
}

void SplashScene::update(float dt)
{
	//switches immediately to game scene, comment out to see demo
	SceneManager::getInstance()->switchTo(Scenes::GAME);

	//can obviously be deleted once you start working on the scene
	m_timeToSwitch -= dt;

	if (m_timeToSwitch <= 0)
	{
		m_timeToSwitch = 3;
		SceneManager::getInstance()->switchTo(Scenes::MAINMENU);
	}
}

void SplashScene::draw(sf::RenderWindow &window)
{
	//can obviously be deleted once you start working on the scene
	sf::Text text("Splash \n\n\n\nDone in " + to_string(m_timeToSwitch) + " seconds", GameConstants::font, 50);
	text.setColor(sf::Color::Red);
	window.draw(text);
}