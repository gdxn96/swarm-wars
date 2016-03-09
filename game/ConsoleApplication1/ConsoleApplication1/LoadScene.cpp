#include "stdafx.h"
#include "LoadScene.h"
#include "AssetLoader.h"
#include "AudioMgr.h"

LoadScene::LoadScene() :
Scene(Scenes::LOAD),
text("name", Vector2D(GameConstants::WINDOW_SIZE.x/1.5f -100, GameConstants::WINDOW_SIZE.y - 60), 85, 3)
{
	
	bgShape.setSize(sf::Vector2f(1200, 100));
	fgShape.setSize(sf::Vector2f(1200, 100));
	
	back.setSize(Vector2D(GameConstants::WINDOW_SIZE).toSFMLVector());
	
	//bgShape.setFillColor(sf::Color(105, 106, 250, 255));
	//fgShape.setFillColor(sf::Color(135, 206, 250, 255));
	bgShape.setOutlineColor(sf::Color(255, 215, 0, 255));
	bgShape.setOutlineThickness(2);

	bgShape.setPosition(Vector2D(GameConstants::WINDOW_CENTRE.x - 600, GameConstants::WINDOW_CENTRE.y - 50).toSFMLVector());
	fgShape.setPosition(Vector2D(GameConstants::WINDOW_CENTRE.x - 600, GameConstants::WINDOW_CENTRE.y - 50).toSFMLVector());
}

void LoadScene::update(float dt)
{
	float s = a->getNumToLoad();

	float percentAmount = (a->getNumLoaded() / static_cast<float>(a->getNumToLoad()));
	fgShape.setSize(sf::Vector2f(1200*percentAmount, 100));
	text.setText(a->getLoadingAsset());
	text.update(dt);
}

void LoadScene::updateInput()
{

}


void LoadScene::draw(sf::RenderWindow &window)
{
	if (!t.loadFromFile("assets/bgMenu.png"))
	{
		cout << "error" << endl;
	}
	back.setTexture(&t);
	if (!t2.loadFromFile("assets/pulse.png"))
	{
		cout << "error" << endl;
	}
	if (!t3.loadFromFile("assets/goldpulse.png"))
	{
		cout << "error" << endl;
	}
	bgShape.setTexture(&t2);
	fgShape.setTexture(&t3);
	window.draw(back);
	
	window.draw(bgShape);
	window.draw(fgShape);
	text.draw(window);
}