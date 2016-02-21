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


void LoadScene::draw(sf::RenderWindow &window)
{
	sf::Text text;
	text.setFont(GameConstants::font);
	text.setString("Loading...");

	window.draw(text);
}