#include "stdafx.h"
#include "SplashScene.h"

SplashScene::SplashScene() : 
	Scene(Scenes::SPLASH), 
	m_timeToSwitch(3),
	object(PhysicsObject(Vector2D(-100, 500), -45, 3000))
{

}

void SplashScene::update(float dt)
{
	//can obviously be deleted once you start working on the scene
	//m_timeToSwitch -= dt;

	object.update(dt);

	/*if (m_timeToSwitch <= 0)
	{
		m_timeToSwitch = 3;
		SceneManager::getInstance()->switchTo(Scenes::MAINMENU);
	}*/
}

void SplashScene::draw(sf::RenderWindow &window)
{
	object.draw(window);
}