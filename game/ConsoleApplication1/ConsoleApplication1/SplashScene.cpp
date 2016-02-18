#include "stdafx.h"
#include "SplashScene.h"

SplashScene::SplashScene() : 
	Scene(Scenes::SPLASH), 
	m_timeToSwitch(6.5f),
	object(PhysicsObject(Vector2D(-100, 500), -45, 3000))
{

}

void SplashScene::update(float dt)
{
	//keeping time in for the moment
	m_timeToSwitch -= dt;

	object.update(dt);

	if (m_timeToSwitch <= 0)
	{
		SceneManager::getInstance()->switchTo(Scenes::MAINMENU);
	}
}

void SplashScene::draw(sf::RenderWindow &window)
{
	object.draw(window);
}