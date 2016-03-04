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
		
}

void LoadScene::updateInput()
{

}


void LoadScene::draw(sf::RenderWindow &window)
{
	AssetLoader* a = AssetLoader::getInstance();
	sf::Text text;
	text.setFont(GameConstants::font);
	text.setString("Loading..." + to_string(a->getNumLoaded()) + "/" + to_string(a->getNumToLoad()) + " Loaded \n loading: " + a->getLoadingAsset());

	window.draw(text);
}