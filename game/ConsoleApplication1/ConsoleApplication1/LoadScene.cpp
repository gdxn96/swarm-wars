#include "stdafx.h"
#include "LoadScene.h"
#include "AssetLoader.h"
#include "AudioMgr.h"

LoadScene::LoadScene() :
Scene(Scenes::LOAD)
{
	
}

void LoadScene::update(float dt)
{
	if (loadAssets() == 1)
	SceneManager::getInstance()->switchTo(Scenes::SPLASH);
	
}

int LoadScene::loadAssets()
{
	return 1;
}

void LoadScene::draw(sf::RenderWindow &window)
{

}